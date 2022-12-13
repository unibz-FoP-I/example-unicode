# see <https://cliutils.gitlab.io/modern-cmake/chapters/basics.html#minimum-version>
cmake_minimum_required(VERSION 3.7...3.25)
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(example-unicode VERSION 0.1.0
                        DESCRIPTION "Demonstrates the handling of Unicode strings in C")

add_compile_options(-Wall -Wextra)


# include(CTest)
# enable_testing()

add_library(utf8 INTERFACE)
target_include_directories(utf8 INTERFACE src/utf8)

add_executable(main src/main.c src/input.c src/sort.c)
target_link_libraries(main PRIVATE utf8)
