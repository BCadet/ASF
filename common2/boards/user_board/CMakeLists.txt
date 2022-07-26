set(SRCS
${CMAKE_CURRENT_LIST_DIR}/init.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/user_board.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})
