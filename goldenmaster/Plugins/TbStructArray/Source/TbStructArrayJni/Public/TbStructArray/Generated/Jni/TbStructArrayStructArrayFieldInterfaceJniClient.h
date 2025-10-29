/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceInterface.h"
#include "TbStructArray/Generated/api/AbstractTbStructArrayStructArrayFieldInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbStructArray/Generated/Jni/TbStructArrayJniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbStructArrayStructArrayFieldInterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbStructArrayStructArrayFieldInterfaceClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSTRUCTARRAYJNI_API UTbStructArrayStructArrayFieldInterfaceJniClient : public UAbstractTbStructArrayStructArrayFieldInterface
{
	GENERATED_BODY()
public:
	explicit UTbStructArrayStructArrayFieldInterfaceJniClient();

	UTbStructArrayStructArrayFieldInterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbStructArrayStructArrayFieldInterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	FTbStructArrayStructWithArrayOfStructs GetPropStructArray() const override;
	void SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray) override;
	FTbStructArrayStructWithArrayOfEnums GetPropEnumArray() const override;
	void SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray) override;
	FTbStructArrayStructWithArrayOfInts GetPropIntArray() const override;
	void SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray) override;
	FTbStructArrayMixedStruct GetPropMixed() const override;
	void SetPropMixed(const FTbStructArrayMixedStruct& InPropMixed) override;

	// operations
	virtual FTbStructArrayMixedStruct FuncMixed(const FTbStructArrayMixedStruct& ParamMixed) override;
	virtual FTbStructArrayStructWithArrayOfStructs FuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbStructArrayJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbStructArrayJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|JNI")
	bool _IsReady() const;

	/**
	* @param package. This client will connect only to a StructArrayFieldInterface Service, that myb be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|JNI|Connection")
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
