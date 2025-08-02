cmake_minimum_required(VERSION 3.15)


# set the project name and version
project(Tutorial VERSION 1.0)

# specify the C++ standard
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)


# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
add_subdirectory(MathFunctions)

# add the executable
add_executable(Tutorial main.cpp)

target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
 )


# install directory used by install()
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install")

# install basic_project in the bin directory
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# enable testing
enable_testing()

# add a test called Runs which runs the following command:
add_test(NAME "Runs" COMMAND Tutorial 25)

# add a test called Usage which runs the following command:
add_test(NAME "Usage" COMMAND Tutorial)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION  ".*you haven't specified number to calculate square root.*")


# add a test which runs the following command:
# $ Tutorial 4
# Make sure the result is correct.
add_test(NAME "SqrtOf4Equals2" COMMAND Tutorial 4)
set_property(TEST "SqrtOf4Equals2" PROPERTY PASS_REGULAR_EXPRESSION "square root of 4 equals 2")
# Hint: Use the PASS_REGULAR_EXPRESSION property with "4 is 2"

# add more tests. Create a function called do_test to avoid copy +
# paste. Test the following values: 4, 9, 5, 7, 25, -25 and 0.0001.
function(do_test target input expected)
add_test(NAME SqrtOf${input} COMMAND ${target} ${input})
set_property(TEST ${name} PROPERTY PASS_REGULAR_EXPRESSION "square root of ${input} equals ${expected}")
endfunction()

do_test(Tutorial 4 2)
do_test(Tutorial 9 3)
do_test(Tutorial 5 2.23)
do_test(Tutorial 7 2.64)
do_test(Tutorial 25 5)
do_test(Tutorial -25 0)
do_test(Tutorial 0.0001 0.01)
do_test(Tutorial 0 0)

# to run tests
# ctest -N
# ctest -VV
# For multi-config generators (e.g. Visual Studio), the configuration type must be specified with the -C <mode> flag.
# For example, to run tests in Debug mode use ctest -C Debug -VV from the build directory (not the Debug subdirectory!).
# Release mode would be executed from the same location but with a -C Release. Alternatively, build the RUN_TESTS target from the IDE.