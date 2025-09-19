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

#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"

UTbRefIfacesSimpleLocalIfImplementation::~UTbRefIfacesSimpleLocalIfImplementation() = default;
int32 UTbRefIfacesSimpleLocalIfImplementation::GetIntProperty() const
{
	return IntProperty;
}

void UTbRefIfacesSimpleLocalIfImplementation::SetIntProperty(int32 InIntProperty)
{
	if (IntProperty != InIntProperty)
	{
		IntProperty = InIntProperty;
		_GetPublisher()->BroadcastIntPropertyChanged(IntProperty);
	}
}

int32 UTbRefIfacesSimpleLocalIfImplementation::IntMethod(int32 Param)
{
	(void)Param;
	// do business logic here
	return 0;
}

void UTbRefIfacesSimpleLocalIfImplementation::_ResetProperties()
{
	if (IntProperty != 0)
	{
		IntProperty = 0;
		_GetPublisher()->BroadcastIntPropertyChanged(IntProperty);
	}
}
