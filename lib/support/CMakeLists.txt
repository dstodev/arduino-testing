add_library(support INTERFACE)
target_include_directories(support INTERFACE
	${CMAKE_CURRENT_LIST_DIR}/include
)
target_sources(support INTERFACE
	${CMAKE_CURRENT_LIST_DIR}/src/adder
)

add_library(support_host)
target_link_libraries(support_host PUBLIC support)

add_subdirectory(tests)
