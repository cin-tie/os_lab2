project(os_lab2)

set(CMAKE_CXX_STANDART 15)

add_executable(run main.cpp min_max.cpp average.cpp)

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests tests.cpp min_max.cpp average.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
