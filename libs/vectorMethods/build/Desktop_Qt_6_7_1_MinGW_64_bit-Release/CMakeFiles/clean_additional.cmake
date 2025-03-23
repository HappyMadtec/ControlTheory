# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\MathMethodsExecutable_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MathMethodsExecutable_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\MathMethods_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MathMethods_autogen.dir\\ParseCache.txt"
  "MathMethodsExecutable_autogen"
  "MathMethods_autogen"
  )
endif()
