add_library(support OBJECT)
target_include_directories(support PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)
target_sources(support PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/src/adder
)

if (BUILD_ARDUINO)
	target_link_libraries(${PROJECT_MAIN}
		PRIVATE
			support
	)
endif()

if (BUILD_TESTS)
	message(INFO "Building tests for library: support")

	add_subdirectory(tests)
endif()
