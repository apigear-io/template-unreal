/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif


#include "TbStructArrayStructArrayFieldInterfaceJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbStructArrayStructArrayFieldInterface_JNI, Log, All);


/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbStructArrayStructArrayFieldInterfaceInterface
 */
UCLASS(BlueprintType)
class TBSTRUCTARRAYJNI_API UTbStructArrayStructArrayFieldInterfaceJniAdapter : public UGameInstanceSubsystem, public ITbStructArrayStructArrayFieldInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbStructArrayStructArrayFieldInterfaceJniAdapter();
	virtual ~UTbStructArrayStructArrayFieldInterfaceJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
    void setBackendService(TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> getBackendService();

private:

    //helper function, wraps calling java service side
    void callJniServiceReady(bool isServiceReady);

	// helper member;
#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	jclass m_javaJniServiceClass = nullptr;
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif

	// signals
	void OnSigMixedSignal(const FTbStructArrayMixedStruct& ParamMixed) override;

	void OnSigStructArraySignal(const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;

	void OnPropStructArrayChanged(const FTbStructArrayStructWithArrayOfStructs& PropStructArray) override;
	void OnPropEnumArrayChanged(const FTbStructArrayStructWithArrayOfEnums& PropEnumArray) override;
	void OnPropIntArrayChanged(const FTbStructArrayStructWithArrayOfInts& PropIntArray) override;
	void OnPropMixedChanged(const FTbStructArrayMixedStruct& PropMixed) override;


	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> BackendService;
};
