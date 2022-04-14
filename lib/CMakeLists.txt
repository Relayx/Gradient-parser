cmake_minimum_required(VERSION 3.0.0)
project(ParserLogic VERSION 1.0.0)

include(CTest)
enable_testing()

set(PUBLIC_INCLUDES 
  ./includes/Image.hpp 
  ./includes/GradientParser.hpp
)

set(FILES
  ./GradientParser.cpp
  ./Image.cpp
)

add_library(ParserLogic STATIC ${FILES} ${PUBLIC_INCLUDES})
target_include_directories(ParserLogic PUBLIC ./includes)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties(ParserLogic PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)