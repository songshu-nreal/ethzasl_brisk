set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHAVE_OPENCV -std=c++0x")

# Detect the preprocessor directives which are set by the compiler.
  if(ANDROID_NREAL)
  if (ANDROID_ABI MATCHES "arm64-v8a")
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} --target=armv8a -dM -E -x c /dev/null
            OUTPUT_VARIABLE PREPROCESSOR_DIRECTIVES)
  elseif(ANDROID_ABI MATCHES "armeabi-v7a")
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} --target=armv7 -dM -E -x c /dev/null
            OUTPUT_VARIABLE PREPROCESSOR_DIRECTIVES)
  else()
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -march=native -dM -E -x c /dev/null
            OUTPUT_VARIABLE PREPROCESSOR_DIRECTIVES)
  endif()
else()
  execute_process(COMMAND ${CMAKE_CXX_COMPILER} -march=native -dM -E -x c /dev/null
          OUTPUT_VARIABLE PREPROCESSOR_DIRECTIVES)
endif()

set(IS_SSE_ENABLED FALSE)
set(IS_NEON_ENABLED FALSE)
if (PREPROCESSOR_DIRECTIVES MATCHES "__SSSE3__")
  add_definitions(-mssse3)
  set(IS_SSE_ENABLED TRUE)
# For both armv7 and armv8, __ARM_NEON is used as preprocessor directive.
elseif (PREPROCESSOR_DIRECTIVES MATCHES "__ARM_ARCH 7")
  add_definitions(-mfpu=neon) # Needs to be set for armv7.
  set(IS_NEON_ENABLED TRUE)
elseif (PREPROCESSOR_DIRECTIVES MATCHES "__ARM_ARCH 8")
  set(IS_NEON_ENABLED TRUE)
else()
  message(WARNING "No SIMD instruction set detected.")
endif()

