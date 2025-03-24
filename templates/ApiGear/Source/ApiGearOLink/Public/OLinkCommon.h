#pragma once

#include "HAL/Platform.h"

// only needed for UE4.27 QNX support - can be removed once support is dropped
#if !defined(PLATFORM_QNX)
#define PLATFORM_QNX 0
#endif
