add_executable(unit_tests
    test_nodes.cpp
    ${PROJECT_SOURCE_DIR}/src/nodes/Disk.cpp
    ${PROJECT_SOURCE_DIR}/src/nodes/Directory.cpp
    ${PROJECT_SOURCE_DIR}/src/nodes/TextFile.cpp
    ${PROJECT_SOURCE_DIR}/src/nodes/ImageFile.cpp
    ${PROJECT_SOURCE_DIR}/src/visitors/CalculateSizeVisitor.cpp
    ${PROJECT_SOURCE_DIR}/src/visitors/PrintStructureVisitor.cpp
)
target_link_libraries(unit_tests GTest::GTest)
add_test(NAME unit_tests COMMAND unit_tests)