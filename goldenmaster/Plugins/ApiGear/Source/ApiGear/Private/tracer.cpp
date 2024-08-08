// Copyright Epic Games, Inc. All Rights Reserved
#include "tracer.h"
#include <iostream>
#include <sstream>
#include "Engine/GameInstance.h"

#include "Modules/ModuleManager.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/IHttpResponse.h"
#include "Interfaces/IHttpRequest.h"
#include "ApiGearSettings.h"

DEFINE_LOG_CATEGORY(LogApiGearTracer);

Tracer* Tracer::s_instance(nullptr);

static bool isbusy = false;

Tracer::Tracer()
	: m_tracingDisabled(true)
	, m_loggingDisabled(true)
{
	if (s_instance)
	{
		log("Tracer can only be instantiated once");
	}

	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	m_serverURL = settings->Tracer_URL;
	m_tracingDisabled = !settings->Tracer_Enabled;
	m_loggingDisabled = !settings->Tracer_EnableDebugLog;
	m_http = nullptr;
	log("Tracer instantiated");
}

Tracer* Tracer::instance()
{
	if (!s_instance)
	{
		s_instance = new Tracer();
	}
	return s_instance;
}

void Tracer::log(const FString& logMessage)
{
	if (!m_loggingDisabled)
	{
		UE_LOG(LogApiGearTracer, Display, TEXT("%s"), *logMessage);
	}
}

void Tracer::connect()
{
	const FString ServerProtocol = TEXT("ws");
	log("connecting .. ");

	if (!m_http)
	{
		if (!FModuleManager::Get().IsModuleLoaded("HTTP"))
		{
			FModuleManager::Get().LoadModule("HTTP");
		}
		m_http = &FHttpModule::Get();
	}
}

void Tracer::trace(const std::string& eventType, const std::string& symbol, const nlohmann::json& fields)
{
	nlohmann::json obj;
	obj["type"] = eventType;
	obj["symbol"] = symbol;
	obj["data"] = fields;

	if (m_tracingDisabled)
	{
		return;
	}

	{
		FScopeLock lock(&m_queueMutex);
		m_queue.push(obj);
	} // scopelock

	process();
}

void Tracer::call(const std::string& symbol, const nlohmann::json& fields)
{
	trace("call", symbol, fields);
}

void Tracer::signal(const std::string& symbol, const nlohmann::json& fields)
{
	trace("signal", symbol, fields);
}

void Tracer::state(const std::string& symbol, const nlohmann::json& fields)
{
	trace("state", symbol, fields);
}

void Tracer::process()
{

	if (isbusy)
	{
		log("still busy ... skipping");
		return;
	}

	log("processing .. ");
	if (!m_http)
	{
		log("not setup .. ");
		connect();
		return;
	}

	{
		FScopeLock lock(&m_queueMutex);

		log("trying to send.. ");
		if (!m_queue.empty())
		{
			nlohmann::json list;
			while (!m_queue.empty())
			{
				list.push_back(m_queue.front());
				m_queue.pop();
			}
			const FString value = list.dump().c_str();

			if (m_http->IsHttpEnabled())
			{
				isbusy = true;
				log(FString::Printf(TEXT("data: %s"), *value));

				FHttpRequestPtr m_httprequest = m_http->CreateRequest();

				m_httprequest->OnProcessRequestComplete().BindStatic(
					[](FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
					{
					FString Messagebody;
					Messagebody = HttpResponse->GetContentAsString();
					// log(Messagebody);
					// UE_LOG(LogApiGearTracer, Display, TEXT("Response: %s"), *Messagebody);
					isbusy = false;
					// HttpResponse->GetContentAsString();
				});
				m_httprequest->SetVerb(TEXT("POST"));
				m_httprequest->SetHeader(TEXT("Content-Type"), TEXT("application/json; charset=utf-8"));
				m_httprequest->SetURL(m_serverURL);
				m_httprequest->SetContentAsString(value);
				m_httprequest->ProcessRequest();
			}
			else
			{
				return;
			}
		}
	} // scopelock
}
