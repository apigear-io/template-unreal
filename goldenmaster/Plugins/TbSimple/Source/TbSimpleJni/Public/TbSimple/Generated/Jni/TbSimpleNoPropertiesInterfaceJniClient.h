/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbSimple/Generated/api/TbSimpleNoPropertiesInterfaceInterface.h"
#include "TbSimple/Generated/api/AbstractTbSimpleNoPropertiesInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimple/Generated/Jni/TbSimpleJniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbSimpleNoPropertiesInterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleNoPropertiesInterfaceClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEJNI_API UTbSimpleNoPropertiesInterfaceJniClient : public UAbstractTbSimpleNoPropertiesInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoPropertiesInterfaceJniClient();

	UTbSimpleNoPropertiesInterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbSimpleNoPropertiesInterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// operations
	virtual void FuncVoid() override;
	virtual bool FuncBool(bool bParamBool) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSimpleJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a NoPropertiesInterface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|JNI|Connection")
	void _unbind();

private:
	bool b_isReady = false;
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jclass m_javaJniClientClass = nullptr;
	jobject m_javaJniClientInstance = nullptr;
#endif
};
