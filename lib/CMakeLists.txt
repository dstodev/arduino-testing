add_subdirectory(third-party)

add_subdirectory(playground)

if (BUILD_TESTS)
	add_subdirectory(mocks)
endif()
