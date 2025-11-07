/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
#include "TbSimple/Generated/api/AbstractTbSimpleNoOperationsInterface.h"
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

#include "TbSimpleNoOperationsInterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleNoOperationsInterfaceClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEJNI_API UTbSimpleNoOperationsInterfaceJniClient : public UAbstractTbSimpleNoOperationsInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoOperationsInterfaceJniClient();

	UTbSimpleNoOperationsInterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbSimpleNoOperationsInterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	bool GetPropBool() const override;
	void SetPropBool(bool bInPropBool) override;
	int32 GetPropInt() const override;
	void SetPropInt(int32 InPropInt) override;

	// operations

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSimpleJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a NoOperationsInterface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|JNI|Connection")
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
