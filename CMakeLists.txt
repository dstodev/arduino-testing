cmake_minimum_required(VERSION 3.15.x)
project(ArduinoPlaygroundSupport LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/lib/cmake)

include(CTest)

add_subdirectory(lib)
