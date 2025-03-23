# CMake generated Testfile for 
# Source directory: D:/ControlTheory/ControlTheory
# Build directory: D:/ControlTheory/ControlTheory/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RunUnitTests "D:/ControlTheory/ControlTheory/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/Tests.exe")
set_tests_properties(RunUnitTests PROPERTIES  _BACKTRACE_TRIPLES "D:/ControlTheory/ControlTheory/CMakeLists.txt;95;add_test;D:/ControlTheory/ControlTheory/CMakeLists.txt;0;")
subdirs("libs/MathsAlgebreLineaire")
subdirs("libs/googletest")
