set(LIB_NAME playground)


add_library(${LIB_NAME})

target_include_directories(${LIB_NAME}
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}/include
)
target_sources(${LIB_NAME}
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}/src/adder
)

if (BUILD_ARDUINO)
	target_link_libraries(${PROJECT_MAIN}
		PRIVATE
			${LIB_NAME}
	)
endif()

if (BUILD_TESTS)
	message("Building tests for library: ${LIB_NAME}")

	add_subdirectory(tests)
endif()
