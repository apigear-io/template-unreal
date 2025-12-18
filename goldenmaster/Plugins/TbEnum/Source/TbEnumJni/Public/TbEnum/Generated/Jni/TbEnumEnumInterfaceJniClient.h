/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#pragma once

#include "TbEnum/Generated/api/TbEnumEnumInterfaceInterface.h"
#include "TbEnum/Generated/api/AbstractTbEnumEnumInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbEnum/Generated/Jni/TbEnumJniConnectionStatus.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "TbEnumEnumInterfaceJniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbEnumEnumInterfaceClient_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBENUMJNI_API UTbEnumEnumInterfaceJniClient : public UAbstractTbEnumEnumInterface
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceJniClient();

	UTbEnumEnumInterfaceJniClient(FVTableHelper& Helper);
	virtual ~UTbEnumEnumInterfaceJniClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;
	ETbEnumEnum0 GetProp0() const override;
	void SetProp0(ETbEnumEnum0 InProp0) override;
	ETbEnumEnum1 GetProp1() const override;
	void SetProp1(ETbEnumEnum1 InProp1) override;
	ETbEnumEnum2 GetProp2() const override;
	void SetProp2(ETbEnumEnum2 InProp2) override;
	ETbEnumEnum3 GetProp3() const override;
	void SetProp3(ETbEnumEnum3 InProp3) override;

	// operations
	virtual ETbEnumEnum0 Func0(ETbEnumEnum0 Param0) override;
	virtual ETbEnumEnum1 Func1(ETbEnumEnum1 Param1) override;
	virtual ETbEnumEnum2 Func2(ETbEnumEnum2 Param2) override;
	virtual ETbEnumEnum3 Func3(ETbEnumEnum3 Param3) override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Jni|Remote", DisplayName = "Connection Status Changed")
	FTbEnumJniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	FTbEnumJniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a EnumInterface Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|JNI|Connection")
	void _unbind();

private:
	bool b_isReady = false;
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
