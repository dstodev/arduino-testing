# 2020 Daniel Stotts

include(GoogleTest)

function(util_add_test name)
	set(options "")
	set(oneValueArgs "")
	set(multiValueArgs FILES INCLUDES LIBRARIES)
	cmake_parse_arguments(${name} "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	if(NOT ${name}_FILES)
		message(FATAL_ERROR "Missing required parameter: FILES")
	endif()

	add_executable(${name}
		${${name}_FILES}
	)

	target_link_libraries(${name}
		PRIVATE
			gtest_main
			${${name}_LIBRARIES}
	)

	target_include_directories(${name}
		PRIVATE
			${${name}_INCLUDES}
	)

	gtest_discover_tests(${name})
endfunction()
