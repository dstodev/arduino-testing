set(LIB_NAME mocks)


add_library(${LIB_NAME})

target_include_directories(${LIB_NAME} PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)
target_sources(${LIB_NAME}
	PRIVATE
		src/serial.cpp
)
