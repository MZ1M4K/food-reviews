cmake_minimum_required(VERSION 3.0.0)
project(rest VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(restaurace "main.cpp" "display.h" "serialization.h""edit.h""sort.h""display.cpp" "serialization.cpp""edit.cpp""sort.cpp")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
