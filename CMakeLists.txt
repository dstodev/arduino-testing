cmake_minimum_required(VERSION 3.15.x)

project(ArduinoPlayground LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/lib/cmake)

set(PROJECT_MAIN main)

if (CMAKE_SYSTEM_NAME STREQUAL "Arduino")
	# Building for arduino
	set(BUILD_ARDUINO ON)
	set(BUILD_TESTS OFF)

	add_executable(${PROJECT_MAIN}
		src/main.cpp
	)
	target_link_arduino_libraries(${PROJECT_MAIN} AUTO_PUBLIC)
	target_enable_arduino_upload(${PROJECT_MAIN})

else()
	# Building tests on the host system
	set(BUILD_ARDUINO OFF)
	set(BUILD_TESTS ON)

	include(CTest)
endif()

add_subdirectory(lib)
