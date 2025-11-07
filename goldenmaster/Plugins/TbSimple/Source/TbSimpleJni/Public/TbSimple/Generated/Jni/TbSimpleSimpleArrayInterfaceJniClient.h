/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "TbSimple/Generated/api/AbstractTbSimpleSimpleArrayInterface.h"
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

#include "TbSimpleSimpleArrayInterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleArrayInterfaceClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEJNI_API UTbSimpleSimpleArrayInterfaceJniClient : public UAbstractTbSimpleSimpleArrayInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleArrayInterfaceJniClient();

	UTbSimpleSimpleArrayInterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbSimpleSimpleArrayInterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	TArray<bool> GetPropBool() const override;
	void SetPropBool(const TArray<bool>& InPropBool) override;
	TArray<int32> GetPropInt() const override;
	void SetPropInt(const TArray<int32>& InPropInt) override;
	TArray<int32> GetPropInt32() const override;
	void SetPropInt32(const TArray<int32>& InPropInt32) override;
	TArray<int64> GetPropInt64() const override;
	void SetPropInt64(const TArray<int64>& InPropInt64) override;
	TArray<float> GetPropFloat() const override;
	void SetPropFloat(const TArray<float>& InPropFloat) override;
	TArray<float> GetPropFloat32() const override;
	void SetPropFloat32(const TArray<float>& InPropFloat32) override;
	TArray<double> GetPropFloat64() const override;
	void SetPropFloat64(const TArray<double>& InPropFloat64) override;
	TArray<FString> GetPropString() const override;
	void SetPropString(const TArray<FString>& InPropString) override;
	FString GetPropReadOnlyString() const override;

	// operations
	virtual TArray<bool> FuncBool(const TArray<bool>& ParamBool) override;
	virtual TArray<int32> FuncInt(const TArray<int32>& ParamInt) override;
	virtual TArray<int32> FuncInt32(const TArray<int32>& ParamInt32) override;
	virtual TArray<int64> FuncInt64(const TArray<int64>& ParamInt64) override;
	virtual TArray<float> FuncFloat(const TArray<float>& ParamFloat) override;
	virtual TArray<float> FuncFloat32(const TArray<float>& ParamFloat32) override;
	virtual TArray<double> FuncFloat64(const TArray<double>& ParamFloat) override;
	virtual TArray<FString> FuncString(const TArray<FString>& ParamString) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSimpleJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a SimpleArrayInterface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|JNI|Connection")
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
