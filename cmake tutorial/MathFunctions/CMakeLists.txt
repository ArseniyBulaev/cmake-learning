add_library(MathFunctions
 MathFunctions.cxx 
)
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

if (USE_MYMATH)
  add_library(SqrtLibrary STATIC
    mysqrt.cxx
  )
  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()

