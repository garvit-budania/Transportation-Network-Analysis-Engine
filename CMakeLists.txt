cmake_minimum_required(VERSION 3.20)

project(
    TransportationNetworkAnalysisEngine
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    tnae
    src/app/main.cpp
    src/core/Graph.cpp
    src/io/CSVReader.cpp
    src/algorithms/BFS.cpp
)

target_include_directories(
    tnae
    PRIVATE
    include
)