cmake_minimum_required(VERSION 3.14)
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp Test.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main core)
find_package(SFML 2 COMPONENTS system network graphics window audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(runAllTests ${SFML_LIBRARIES})

endif ()