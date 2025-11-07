/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "TbIfaceimport/Generated/api/AbstractTbIfaceimportEmptyIf.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbIfaceimport/Generated/Jni/TbIfaceimportJniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbIfaceimportEmptyIfJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbIfaceimportEmptyIfClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBIFACEIMPORTJNI_API UTbIfaceimportEmptyIfJniClient : public UAbstractTbIfaceimportEmptyIf
{
	GENERATED_BODY()
public:
	explicit UTbIfaceimportEmptyIfJniClient();

	UTbIfaceimportEmptyIfJniClient(FVTableHelper& Helper);
	virtual ~UTbIfaceimportEmptyIfJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// operations

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbIfaceimport|EmptyIf|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbIfaceimportJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbIfaceimportJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a EmptyIf Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|JNI|Connection")
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
