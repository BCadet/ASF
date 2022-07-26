set(SRCS
${CMAKE_CURRENT_LIST_DIR}/system.c
)

set(HDRS
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PRIVATE ${SRCS})

add_subdirectory(clock)
add_subdirectory(interrupt)
add_subdirectory(pinmux)
add_subdirectory(power)
add_subdirectory(reset)