cmake_minimum_required(VERSION 3.10)

project(MapGenerator)

set(CMAKE_C_STANDARD 23)



file(GLOB SOURCES 
  "src/*.c"
  "src/Gui/*.c"
  "src/MapGenerator/*.c")
file(GLOB HEADERS 
  "includes/*.h"
  "includes/Gui/*.h"
  "includes/MapGenerator/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE
  includes
  src
  external)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

target_include_directories(${PROJECT_NAME} PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTK4_LIBRARIES})

target_link_libraries(${PROJECT_NAME} m)

target_compile_options(${PROJECT_NAME} PRIVATE ${GTK4_CFLAGS_OTHER})

