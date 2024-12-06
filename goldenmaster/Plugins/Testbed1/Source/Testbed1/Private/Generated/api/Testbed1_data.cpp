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

#include "Generated/api/Testbed1_data.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

bool FTestbed1StructBool::operator==(const FTestbed1StructBool& rhs) const
{
	return (fieldBool == rhs.fieldBool);
}

bool FTestbed1StructBool::operator!=(const FTestbed1StructBool& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructBool::operator FString() const
{
	return ToString();
}

FString FTestbed1StructBool::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructBool::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructInt::operator==(const FTestbed1StructInt& rhs) const
{
	return (fieldInt == rhs.fieldInt);
}

bool FTestbed1StructInt::operator!=(const FTestbed1StructInt& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructInt::operator FString() const
{
	return ToString();
}

FString FTestbed1StructInt::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructInt::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructFloat::operator==(const FTestbed1StructFloat& rhs) const
{
	return (fieldFloat == rhs.fieldFloat);
}

bool FTestbed1StructFloat::operator!=(const FTestbed1StructFloat& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructFloat::operator FString() const
{
	return ToString();
}

FString FTestbed1StructFloat::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructFloat::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructString::operator==(const FTestbed1StructString& rhs) const
{
	return (fieldString == rhs.fieldString);
}

bool FTestbed1StructString::operator!=(const FTestbed1StructString& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructString::operator FString() const
{
	return ToString();
}

FString FTestbed1StructString::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructString::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

/* Returns true if Testbed1StructBool A is equal to Testbed1StructBool B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructBoolTestbed1StructBool(FTestbed1StructBool A, FTestbed1StructBool B)
{
	return A == B;
}

/* Returns true if Testbed1StructBool A is not equal to Testbed1StructBool B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructBoolTestbed1StructBool(FTestbed1StructBool A, FTestbed1StructBool B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructBoolToString(const FTestbed1StructBool& InTestbed1StructBool)
{
	return InTestbed1StructBool.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructBoolToJSON(const FTestbed1StructBool& InTestbed1StructBool)
{
	return InTestbed1StructBool.ToJSON();
}

/* Returns true if Testbed1StructInt A is equal to Testbed1StructInt B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructIntTestbed1StructInt(FTestbed1StructInt A, FTestbed1StructInt B)
{
	return A == B;
}

/* Returns true if Testbed1StructInt A is not equal to Testbed1StructInt B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructIntTestbed1StructInt(FTestbed1StructInt A, FTestbed1StructInt B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructIntToString(const FTestbed1StructInt& InTestbed1StructInt)
{
	return InTestbed1StructInt.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructIntToJSON(const FTestbed1StructInt& InTestbed1StructInt)
{
	return InTestbed1StructInt.ToJSON();
}

/* Returns true if Testbed1StructFloat A is equal to Testbed1StructFloat B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructFloatTestbed1StructFloat(FTestbed1StructFloat A, FTestbed1StructFloat B)
{
	return A == B;
}

/* Returns true if Testbed1StructFloat A is not equal to Testbed1StructFloat B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructFloatTestbed1StructFloat(FTestbed1StructFloat A, FTestbed1StructFloat B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructFloatToString(const FTestbed1StructFloat& InTestbed1StructFloat)
{
	return InTestbed1StructFloat.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructFloatToJSON(const FTestbed1StructFloat& InTestbed1StructFloat)
{
	return InTestbed1StructFloat.ToJSON();
}

/* Returns true if Testbed1StructString A is equal to Testbed1StructString B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructStringTestbed1StructString(FTestbed1StructString A, FTestbed1StructString B)
{
	return A == B;
}

/* Returns true if Testbed1StructString A is not equal to Testbed1StructString B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructStringTestbed1StructString(FTestbed1StructString A, FTestbed1StructString B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructStringToString(const FTestbed1StructString& InTestbed1StructString)
{
	return InTestbed1StructString.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructStringToJSON(const FTestbed1StructString& InTestbed1StructString)
{
	return InTestbed1StructString.ToJSON();
}
