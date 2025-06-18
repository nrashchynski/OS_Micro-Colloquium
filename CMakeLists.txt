cmake_minimum_required(VERSION 3.10)
project(OS_Micro-Colloquium)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
    src/main.cpp
    src/nodes/Disk.cpp
    src/nodes/Directory.cpp
    src/nodes/TextFile.cpp
    src/nodes/ImageFile.cpp
    src/visitors/CalculateSizeVisitor.cpp
    src/strategies/MutexStrategy.cpp
)

target_include_directories(main PRIVATE src)

enable_testing()
add_subdirectory(tests/unit)
add_subdirectory(tests/e2e)