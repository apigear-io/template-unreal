
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
#include "TbStructArray/Generated/Core/TbStructArrayPropertiesData.h"

void TbStructArrayStructArrayFieldInterfacePropertiesData::SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
{
	FWriteScopeLock WriteLock(PropStructArrayLock);
	PropStructArray = InPropStructArray;
}

FTbStructArrayStructWithArrayOfStructs TbStructArrayStructArrayFieldInterfacePropertiesData::GetPropStructArray() const
{
	FReadScopeLock ReadLock(PropStructArrayLock);
	return PropStructArray;
}

void TbStructArrayStructArrayFieldInterfacePropertiesData::SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
{
	FWriteScopeLock WriteLock(PropEnumArrayLock);
	PropEnumArray = InPropEnumArray;
}

FTbStructArrayStructWithArrayOfEnums TbStructArrayStructArrayFieldInterfacePropertiesData::GetPropEnumArray() const
{
	FReadScopeLock ReadLock(PropEnumArrayLock);
	return PropEnumArray;
}

void TbStructArrayStructArrayFieldInterfacePropertiesData::SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
{
	FWriteScopeLock WriteLock(PropIntArrayLock);
	PropIntArray = InPropIntArray;
}

FTbStructArrayStructWithArrayOfInts TbStructArrayStructArrayFieldInterfacePropertiesData::GetPropIntArray() const
{
	FReadScopeLock ReadLock(PropIntArrayLock);
	return PropIntArray;
}

void TbStructArrayStructArrayFieldInterfacePropertiesData::SetPropMixed(const FTbStructArrayMixedStruct& InPropMixed)
{
	FWriteScopeLock WriteLock(PropMixedLock);
	PropMixed = InPropMixed;
}

FTbStructArrayMixedStruct TbStructArrayStructArrayFieldInterfacePropertiesData::GetPropMixed() const
{
	FReadScopeLock ReadLock(PropMixedLock);
	return PropMixed;
}
