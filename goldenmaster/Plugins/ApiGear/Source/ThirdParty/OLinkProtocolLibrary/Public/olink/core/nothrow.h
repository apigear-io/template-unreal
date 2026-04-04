#pragma once

// Detect whether C++ exceptions are enabled.
// Used to guard try-catch blocks so the library compiles with -fno-exceptions
// (e.g. Unreal Engine, embedded systems).
#if defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(_CPPUNWIND)
#  define OLINK_HAS_EXCEPTIONS 1
#else
#  define OLINK_HAS_EXCEPTIONS 0
#endif
