cmake_minimum_required(VERSION 3.27)
project(LaboratorOOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(LaboratorOOP Shop.cpp
        FruitUI.cpp
        Fruit.cpp
        FruitController.cpp
        FruitRepo.cpp
        Test.cpp)
