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

#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
#include "TbSimple/Generated/api/AbstractTbSimpleSimpleInterface.h"
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

#include "TbSimpleSimpleInterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleInterfaceClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEJNI_API UTbSimpleSimpleInterfaceJniClient : public UAbstractTbSimpleSimpleInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleInterfaceJniClient();

	UTbSimpleSimpleInterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbSimpleSimpleInterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	bool GetPropBool() const override;
	void SetPropBool(bool bInPropBool) override;
	int32 GetPropInt() const override;
	void SetPropInt(int32 InPropInt) override;
	int32 GetPropInt32() const override;
	void SetPropInt32(int32 InPropInt32) override;
	int64 GetPropInt64() const override;
	void SetPropInt64(int64 InPropInt64) override;
	float GetPropFloat() const override;
	void SetPropFloat(float InPropFloat) override;
	float GetPropFloat32() const override;
	void SetPropFloat32(float InPropFloat32) override;
	double GetPropFloat64() const override;
	void SetPropFloat64(double InPropFloat64) override;
	FString GetPropString() const override;
	void SetPropString(const FString& InPropString) override;

	// operations
	virtual void FuncNoReturnValue(bool bParamBool) override;
	virtual bool FuncBool(bool bParamBool) override;
	virtual int32 FuncInt(int32 ParamInt) override;
	virtual int32 FuncInt32(int32 ParamInt32) override;
	virtual int64 FuncInt64(int64 ParamInt64) override;
	virtual float FuncFloat(float ParamFloat) override;
	virtual float FuncFloat32(float ParamFloat32) override;
	virtual double FuncFloat64(double ParamFloat) override;
	virtual FString FuncString(const FString& ParamString) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbSimpleJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbSimpleJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|JNI")
	bool _IsReady() const;

	/**
	* @param package. This client will connect only to a SimpleInterface Service, that myb be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|JNI|Connection")
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
