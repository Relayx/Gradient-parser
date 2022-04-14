cmake_minimum_required(VERSION 3.0.0)
project(Gradient-Parser VERSION 1.0.0)

add_executable(Gradient-Parser main.cpp)

add_subdirectory(lib)
target_link_libraries(Gradient-Parser ParserLogic)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set_target_properties(Gradient-Parser PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
