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
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"

#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"
#include "TbRefIfacesParentIfMsgBusMessages.generated.h"

UENUM(BlueprintType)
enum class ETbRefIfacesParentIfDiscoveryMessageType : uint8
{
	// send by other services to make sure they are unique
	ServiceAnnouncement UMETA(Displayname = "Service Announcement"),
	// send by clients to start an actual connection
	ConnectionRequest UMETA(Displayname = "Connection Request")
};

USTRUCT()
struct FTbRefIfacesParentIfDiscoveryMessage
{
	GENERATED_BODY()

	UPROPERTY()
	ETbRefIfacesParentIfDiscoveryMessageType Type = ETbRefIfacesParentIfDiscoveryMessageType::ConnectionRequest;
};

USTRUCT()
struct FTbRefIfacesParentIfServiceAnnouncementReplyMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefIfacesParentIfInitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 100;

	UPROPERTY()
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIf = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();

	UPROPERTY()
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfList = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();

	UPROPERTY()
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIf = TScriptInterface<ITbIfaceimportEmptyIfInterface>();

	UPROPERTY()
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfList = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefIfacesParentIfServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct FTbRefIfacesParentIfPingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbRefIfacesParentIfPongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct FTbRefIfacesParentIfLocalIfSignalSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> Param = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfLocalIfSignalListSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> Param = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfImportedIfSignalSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbIfaceimportEmptyIfInterface> Param = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfImportedIfSignalListSignalMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> Param = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfSetLocalIfRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIf = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfLocalIfChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIf = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfSetLocalIfListRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfList = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfLocalIfListChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfList = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfSetImportedIfRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIf = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfImportedIfChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIf = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfSetImportedIfListRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfList = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfImportedIfListChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfList = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfLocalIfMethodRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> Param = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfLocalIfMethodReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> Result = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfLocalIfMethodListRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> Param = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfLocalIfMethodListReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> Result = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfImportedIfMethodRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TScriptInterface<ITbIfaceimportEmptyIfInterface> Param = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfImportedIfMethodReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TScriptInterface<ITbIfaceimportEmptyIfInterface> Result = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
};

USTRUCT()
struct FTbRefIfacesParentIfImportedIfMethodListRequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> Param = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
};

USTRUCT()
struct FTbRefIfacesParentIfImportedIfMethodListReplyMessage
{
	GENERATED_BODY()

	UPROPERTY()
	FGuid ResponseId;

	UPROPERTY()
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> Result = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
};
