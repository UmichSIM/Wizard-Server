cmake_minimum_required(VERSION 3.5.1)
project(wizard-server)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
add_executable(${PROJECT_NAME} server.cpp)
target_link_libraries(${PROJECT_NAME} librpc.a)

# set the exe position to bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# NOTE: Adding CLI11{{
# if(NOT DEFINED CLI11_DIR)
# set (CLI11_DIR "/opt/CLI11" CACHE STRING "CLI11 git repository")
# endif()
# include_directories(${CLI11_DIR}/include)
# }}
