cmake_minimum_required(VERSION 3.10)
project(fileorganizer)

# Set C++17 as required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Windows-specific configurations
if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -municode")
endif()

# Add executables
add_executable(fileorganizer main.cpp)
add_executable(test_generator testing.cpp)

# Windows-specific libraries for the main executable
if(WIN32)
    target_link_libraries(fileorganizer PRIVATE ole32 shell32)
endif()