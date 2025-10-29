/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
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


#include "TbRefIfacesSimpleLocalIfJniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesSimpleLocalIf_JNI, Log, All);


/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type ITbRefIfacesSimpleLocalIfInterface
 */
UCLASS(BlueprintType)
class TBREFIFACESJNI_API UTbRefIfacesSimpleLocalIfJniAdapter : public UGameInstanceSubsystem, public ITbRefIfacesSimpleLocalIfSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbRefIfacesSimpleLocalIfJniAdapter();
	virtual ~UTbRefIfacesSimpleLocalIfJniAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
    void setBackendService(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> getBackendService();

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
	void OnIntSignalSignal(int32 Param) override;

	void OnIntPropertyChanged(int32 IntProperty) override;


	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> BackendService;
};
