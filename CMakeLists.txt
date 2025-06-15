cmake_minimum_required(VERSION 3.10)
project(dsa_toolbox)

set(CMAKE_CXX_STANDARD 17)

add_executable(dsa_toolbox
    main.cpp
    src/sort/quickSort.cpp
    src/sort/mergeSort.cpp
    src/graph/graph.cpp
    utils/input_parser.cpp
)

target_include_directories(dsa_toolbox PRIVATE src utils)