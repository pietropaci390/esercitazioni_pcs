cmake_minimum_required(VERSION 3.20)
project(esercitazione2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


add_executable(esercizio_di_prova2 prova.cpp)
add_executable(secondo_esercizio codice_esercizio_2.cpp)
add_executable(esercizio_facoltativo bubblesort.cpp)