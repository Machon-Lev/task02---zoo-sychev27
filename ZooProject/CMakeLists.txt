# CMakeList.txt : CMake project for ZooProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

project (ZooProject)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif() 

# Add source to this project's executable.
add_executable (ZooProject "src/ZooProject.cpp" "include/Animal.h" "src/Animal.cpp" "include/Location.h" "src/Location.cpp" "include/Lion.h" "src/Lion.cpp" "include/Dog.h" "src/Dog.cpp" "include/Owl.h" "src/Owl.cpp" "include/Zoo.h" "src/Zoo.cpp")

add_subdirectory (include)
add_subdirectory (src)

# TODO: Add tests and install targets if needed.
