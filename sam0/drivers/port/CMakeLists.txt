set(SRCS
${CMAKE_CURRENT_LIST_DIR}/port.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/port.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})