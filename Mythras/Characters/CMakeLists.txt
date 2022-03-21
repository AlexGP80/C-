cmake_minimum_required(VERSION 3.1.5)
project(mythras_characters)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

# Bring the headers into the project
include_directories(include)

# Bring the sources into the project
add_library(rollLib SHARED
  src/Roll.cpp)
set_target_properties(rollLib PROPERTIES PUBLIC_HEADER include/Roll.h)
target_include_directories(rollLib PRIVATE include)
target_include_directories(rollLib PRIVATE src)
install(TARGETS rollLib
    LIBRARY DESTINATION &{CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_executable(characters src/Roll.cpp src/mchars.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b007c54f2944e193ac44fba1bc997cb65826a0b9.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})

enable_testing()

include(GoogleTest)
add_subdirectory(./src/test)
