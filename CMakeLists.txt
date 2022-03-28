cmake_minimum_required(VERSION 3.5.1)
project(wizard-server)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
add_executable(${PROJECT_NAME} server.cpp)
# thread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} librpc.a Threads::Threads)

# set the exe position to bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# NOTE: Adding CLI11
include_directories(${PROJECT_SOURCE_DIR}/include)
