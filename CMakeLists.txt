cmake_minimum_required(VERSION 3.10)

project(projeto_c_interfaceamento C)


add_executable(projeto_c_interfaceamento main.c)

add_library(levenshtein levenshtein/levenshtein.c)

add_subdirectory(pocketpy)

target_link_libraries(projeto_c_interfaceamento pocketpy levenshtein)