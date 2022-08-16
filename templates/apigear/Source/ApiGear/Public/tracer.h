// Copyright Epic Games, Inc. All Rights Reserved
#pragma once
#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
// Disable nlohmann::json exception handling
#define JSON_NOEXCEPTION 1
#include <nlohmann/json.hpp>
#include <string>
#include <map>
#include <queue>
#include "HttpModule.h"
#include <iostream>

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearTracer, Log, All);

class APIGEAR_API Tracer
{
public:
    static Tracer* instance();
    Tracer(Tracer const&) = delete;
    void operator=(Tracer const&) = delete;

    void call(const std::string &symbol, const nlohmann::json &fields);
    void signal(const std::string &symbol, const nlohmann::json &fields);
    void state(const std::string &symbol, const nlohmann::json &fields);

private:
    explicit Tracer();

    void connect();
    void process();
    void trace(const std::string &eventKind, const std::string &symbol, const nlohmann::json &fields);

    void log(const FString &logMessage);

private:
    static Tracer* s_instance;
    std::queue<nlohmann::json> m_queue;
    bool m_tracingDisabled;
    bool m_loggingDisabled;
    FString m_serverURL;
    FCriticalSection m_queueMutex;
    FHttpModule* m_http;
};
