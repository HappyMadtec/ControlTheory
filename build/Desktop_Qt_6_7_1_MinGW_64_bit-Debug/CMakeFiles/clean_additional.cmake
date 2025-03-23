# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ControlTheory_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ControlTheory_autogen.dir\\ParseCache.txt"
  "ControlTheory_autogen"
  "libs\\MathsAlgebreLineaire\\CMakeFiles\\MathMethodsExecutable_autogen.dir\\AutogenUsed.txt"
  "libs\\MathsAlgebreLineaire\\CMakeFiles\\MathMethodsExecutable_autogen.dir\\ParseCache.txt"
  "libs\\MathsAlgebreLineaire\\CMakeFiles\\MathMethods_autogen.dir\\AutogenUsed.txt"
  "libs\\MathsAlgebreLineaire\\CMakeFiles\\MathMethods_autogen.dir\\ParseCache.txt"
  "libs\\MathsAlgebreLineaire\\MathMethodsExecutable_autogen"
  "libs\\MathsAlgebreLineaire\\MathMethods_autogen"
  )
endif()
