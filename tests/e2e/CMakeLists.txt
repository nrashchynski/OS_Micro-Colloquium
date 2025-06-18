add_executable(e2e_tests
    test_threads.cpp
    ${PROJECT_SOURCE_DIR}/src/nodes/Disk.cpp
    ${PROJECT_SOURCE_DIR}/src/nodes/Directory.cpp
    ${PROJECT_SOURCE_DIR}/src/nodes/TextFile.cpp
    ${PROJECT_SOURCE_DIR}/src/strategies/MutexStrategy.cpp
    ${PROJECT_SOURCE_DIR}/src/ThreadSafeFileSystem.cpp
)
target_link_libraries(e2e_tests GTest::GTest Threads::Threads)
add_test(NAME e2e_tests COMMAND e2e_tests)