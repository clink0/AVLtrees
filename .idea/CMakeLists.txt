cmake_minimum_required(VERSION 3.29)
project(_idea)

set(CMAKE_CXX_STANDARD 14)

add_executable(_idea
    AVLTrees.iml
    editor.xml
    misc.xml
    modules.xml
    vcs.xml
    workspace.xml
        ../main.cpp
        ../AVL.cpp)
