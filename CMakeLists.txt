cmake_minimum_required(VERSION 3.22.1)
project(des_cracker_mid-term)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

# Sanitizer Blocks
set(SANITIZE "" CACHE STRING "thread | address | undefined")
if(SANITIZE)
    add_compile_options(-fsanitize=${SANITIZE} -g -O1 -fno-omit-frame-pointer)
    add_link_options(-fsanitize=${SANITIZE})
endif()

add_executable(des-cracker main.cpp)

# Link OpenMP and libcrypt
target_link_libraries(des-cracker PRIVATE OpenMP::OpenMP_CXX crypt)