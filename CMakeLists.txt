cmake_minimum_required(VERSION 3.10)

project(MapGenerator)

set(CMAKE_C_STANDARD 23)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)
find_package(JPEG REQUIRED)
pkg_check_modules(JPEG REQUIRED IMPORTED_TARGET libjpeg)

file(GLOB SOURCES 
  "src/*.c"
  "src/Gui/*.c"
  "src/MapGenerator/*.c")
file(GLOB HEADERS 
  "includes/*.h"
  "includes/Gui/*.h"
  "includes/MapGenerator/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE includes)


target_include_directories(${PROJECT_NAME} PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${GTK4_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} ${GTK4_LIBRARIES})

target_compile_options(${PROJECT_NAME} PRIVATE ${GTK4_CFLAGS_OTHER})

target_link_libraries(${PROJECT_NAME} ${JPEG_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${JPEG_INCLUDE_DIRS})
