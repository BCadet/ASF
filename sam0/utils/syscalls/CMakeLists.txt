set(SRCS
${CMAKE_CURRENT_LIST_DIR}/gcc/syscalls.c
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})