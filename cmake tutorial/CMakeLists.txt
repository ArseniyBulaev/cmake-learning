cmake_minimum_required(VERSION 3.10)
project(basic_project VERSION 1.0)
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)
add_executable(basic_project main.cpp)
configure_file(TutorialConfig.h.in TutorialConfig.h)
target_include_directories(basic_project PUBLIC
    "${PROJECT_BINARY_DIR}"
 )
add_subdirectory(MathFunctions)
target_link_libraries(basic_project PUBLIC MathFunctions tutorial_compiler_flags)