cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 20)

# Set the source dir
add_executable(MyProject 
    main.cpp
    language_issues/oop.cpp
    language_issues/oop.h
    language_issues/const.cpp
    language_issues/const.h
    leet/leet.cpp
    leet/leet.h
    leet/leet_test.cpp
    leet/leet_test.h
)