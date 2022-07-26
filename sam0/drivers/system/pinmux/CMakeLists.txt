set(SRCS
${CMAKE_CURRENT_LIST_DIR}/pinmux.c
)

set(HDRS
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PRIVATE ${SRCS})