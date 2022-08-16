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

#include "Testbed1_data.h"
bool FTestbed1StructBool::operator==(const FTestbed1StructBool& rhs) const
{
	return (fieldBool == rhs.fieldBool);
}

bool FTestbed1StructBool::operator!=(const FTestbed1StructBool& rhs) const
{
	return !operator==(rhs);
}
bool FTestbed1StructInt::operator==(const FTestbed1StructInt& rhs) const
{
	return (fieldInt == rhs.fieldInt);
}

bool FTestbed1StructInt::operator!=(const FTestbed1StructInt& rhs) const
{
	return !operator==(rhs);
}
bool FTestbed1StructFloat::operator==(const FTestbed1StructFloat& rhs) const
{
	return (fieldFloat == rhs.fieldFloat);
}

bool FTestbed1StructFloat::operator!=(const FTestbed1StructFloat& rhs) const
{
	return !operator==(rhs);
}
bool FTestbed1StructString::operator==(const FTestbed1StructString& rhs) const
{
	return (fieldString == rhs.fieldString);
}

bool FTestbed1StructString::operator!=(const FTestbed1StructString& rhs) const
{
	return !operator==(rhs);
}
