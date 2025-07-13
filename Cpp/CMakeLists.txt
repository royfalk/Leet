cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)

# Set the source dir
add_executable(MyProject 
    main.cpp
    language_issues/oop.cpp
    language_issues/oop.h
    leet/leet.cpp
    leet/leet.h
)