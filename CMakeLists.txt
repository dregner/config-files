cmake_minimum_required(VERSION 3.15)
project(teste_libconfig)

set(CMAKE_CXX_STANDARD 14)
find_library(libconfig libconfig++)

add_executable(set_cameras read_cameras_configure.cpp) # Arquivo executável que utiliza a biblioteca
target_link_libraries(set_cameras -lconfig++ -lconfig) # Referencia para o executável encontrar a biblioteca


