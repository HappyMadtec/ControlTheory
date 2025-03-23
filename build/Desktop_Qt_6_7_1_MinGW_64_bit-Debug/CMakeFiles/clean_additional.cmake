# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ControlTheory_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ControlTheory_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\Tests_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Tests_autogen.dir\\ParseCache.txt"
  "ControlTheory_autogen"
  "Tests_autogen"
  "libs\\MathsAlgebreLineaire\\CMakeFiles\\MathMethodsExecutable_autogen.dir\\AutogenUsed.txt"
  "libs\\MathsAlgebreLineaire\\CMakeFiles\\MathMethodsExecutable_autogen.dir\\ParseCache.txt"
  "libs\\MathsAlgebreLineaire\\CMakeFiles\\MathMethods_autogen.dir\\AutogenUsed.txt"
  "libs\\MathsAlgebreLineaire\\CMakeFiles\\MathMethods_autogen.dir\\ParseCache.txt"
  "libs\\MathsAlgebreLineaire\\MathMethodsExecutable_autogen"
  "libs\\MathsAlgebreLineaire\\MathMethods_autogen"
  "libs\\googletest\\googlemock\\CMakeFiles\\gmock_autogen.dir\\AutogenUsed.txt"
  "libs\\googletest\\googlemock\\CMakeFiles\\gmock_autogen.dir\\ParseCache.txt"
  "libs\\googletest\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\AutogenUsed.txt"
  "libs\\googletest\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\ParseCache.txt"
  "libs\\googletest\\googlemock\\gmock_autogen"
  "libs\\googletest\\googlemock\\gmock_main_autogen"
  "libs\\googletest\\googletest\\CMakeFiles\\gtest_autogen.dir\\AutogenUsed.txt"
  "libs\\googletest\\googletest\\CMakeFiles\\gtest_autogen.dir\\ParseCache.txt"
  "libs\\googletest\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\AutogenUsed.txt"
  "libs\\googletest\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\ParseCache.txt"
  "libs\\googletest\\googletest\\gtest_autogen"
  "libs\\googletest\\googletest\\gtest_main_autogen"
  )
endif()
