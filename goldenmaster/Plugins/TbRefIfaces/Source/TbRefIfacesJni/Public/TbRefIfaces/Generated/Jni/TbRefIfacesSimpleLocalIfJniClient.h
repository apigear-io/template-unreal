/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesSimpleLocalIf.h"
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

#include "TbRefIfacesSimpleLocalIfJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbRefIfacesSimpleLocalIfClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBREFIFACESJNI_API UTbRefIfacesSimpleLocalIfJniClient : public UAbstractTbRefIfacesSimpleLocalIf
{
	GENERATED_BODY()
public:
	explicit UTbRefIfacesSimpleLocalIfJniClient();

	UTbRefIfacesSimpleLocalIfJniClient(FVTableHelper& Helper);
	virtual ~UTbRefIfacesSimpleLocalIfJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	int32 GetIntProperty() const override;
	void SetIntProperty(int32 InIntProperty) override;

	// operations
	virtual int32 IntMethod(int32 Param) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbRefIfacesJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbRefIfacesJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a SimpleLocalIf Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|JNI|Connection")
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
