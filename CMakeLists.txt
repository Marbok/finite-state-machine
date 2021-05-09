cmake_minimum_required(VERSION 3.16)

set(This fsm)

project(${This})

set(Headers
    fsm.h
    binary_code.h
    string_validation.h
)

set(Sources
    main.cpp
)

add_executable(${This}.exe ${Headers} ${Sources})