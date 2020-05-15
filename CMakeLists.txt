cmake_minimum_required(VERSION 3.15)
project(calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(calculator main.cpp BinaryOperation.h BinaryBlock.h UnaryOperation.h UnaryBlock.h Read_expression.h Result_function.h Enum_operations.h)