cmake_minimum_required(VERSION 3.15.x)

project(ArduinoPlaygroundSupport LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/lib/cmake)


if (CMAKE_SYSTEM_NAME STREQUAL "Arduino")
	set(BUILD_ARDUINO ON)
	set(BUILD_TESTS OFF)

	add_executable(project
		project.cpp
	)
	target_link_arduino_libraries(project PRIVATE core)
	target_enable_arduino_upload(project)

else()
	set(BUILD_ARDUINO OFF)
	set(BUILD_TESTS ON)

	include(CTest)
endif()

add_subdirectory(lib)
