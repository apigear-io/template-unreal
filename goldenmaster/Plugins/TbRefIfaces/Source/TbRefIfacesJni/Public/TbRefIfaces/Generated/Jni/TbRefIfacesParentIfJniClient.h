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

#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesParentIf.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesJniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbRefIfacesParentIfJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesParentIfClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFIFACESJNI_API UTbRefIfacesParentIfJniClient : public UAbstractTbRefIfacesParentIf
{
	GENERATED_BODY()
public:
	explicit UTbRefIfacesParentIfJniClient();

	UTbRefIfacesParentIfJniClient(FVTableHelper& Helper);
	virtual ~UTbRefIfacesParentIfJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const override;
	void SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf) override;
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList() const override;
	void SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList) override;
	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const override;
	void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf) override;
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList() const override;
	void SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList) override;

	// operations
	virtual TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;
	virtual TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;
	virtual TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;
	virtual TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|ParentIf|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbRefIfacesJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbRefIfacesJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|JNI")
	bool _IsReady() const;

	/**
	* @param package. This client will connect only to a ParentIf Service, that myb be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|JNI|Connection")
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
