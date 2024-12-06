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

#include "Generated/api/CustomTypes_data.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

bool FCustomTypesVector3D::operator==(const FCustomTypesVector3D& rhs) const
{
	return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
}

bool FCustomTypesVector3D::operator!=(const FCustomTypesVector3D& rhs) const
{
	return !operator==(rhs);
}

FCustomTypesVector3D::operator FString() const
{
	return ToString();
}

FString FCustomTypesVector3D::ToString() const
{
	return ToJSON(true);
}

FString FCustomTypesVector3D::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

/* Returns true if CustomTypesVector3D A is equal to CustomTypesVector3D B (A == B) */
bool UCustomTypesLibrary::EqualEqual_CustomTypesVector3DCustomTypesVector3D(FCustomTypesVector3D A, FCustomTypesVector3D B)
{
	return A == B;
}

/* Returns true if CustomTypesVector3D A is not equal to CustomTypesVector3D B (A != B) */
bool UCustomTypesLibrary::NotEqual_CustomTypesVector3DCustomTypesVector3D(FCustomTypesVector3D A, FCustomTypesVector3D B)
{
	return A != B;
}

FString UCustomTypesLibrary::Conv_CustomTypesVector3DToString(const FCustomTypesVector3D& InCustomTypesVector3D)
{
	return InCustomTypesVector3D.ToString();
}

FString UCustomTypesLibrary::Conv_CustomTypesVector3DToJSON(const FCustomTypesVector3D& InCustomTypesVector3D)
{
	return InCustomTypesVector3D.ToJSON();
}
