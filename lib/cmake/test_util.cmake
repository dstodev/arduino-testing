# 2020 Daniel Stotts

include(GoogleTest)

function(util_add_test name)
	cmake_parse_arguments(${name} "" "" "FILES;INCLUDES;LIBRARIES" ${ARGN})

	if(NOT ${name}_FILES)
		message(FATAL_ERROR "Missing required parameter: FILES")
	endif()

	add_executable(${name}
		${${name}_FILES}
	)
	target_link_libraries(${name}
		PRIVATE
			gtest
			gtest_main
			${${name}_LIBRARIES}
	)

	if(${name}_INCLUDES)
		target_include_directories(${name}
		PRIVATE
			${${name}_INCLUDES}
		)
	endif()

	gtest_discover_tests(${name})
endfunction()
