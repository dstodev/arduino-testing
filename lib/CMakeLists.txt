# Third-party libraries
if (BUILD_TESTS)
	add_subdirectory(googletest EXCLUDE_FROM_ALL)
endif()

# My libraries
add_subdirectory(support)
