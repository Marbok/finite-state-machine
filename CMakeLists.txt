cmake_minimum_required(VERSION 3.16)

set(This fsm)

project(${This})

set(Headers
    fsm.h
)

set(Sources
    main.cpp
    fsm.cpp
)

add_executable(${This}.exe ${Headers} ${Sources})