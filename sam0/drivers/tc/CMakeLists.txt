set(SRCS
${CMAKE_CURRENT_LIST_DIR}/tc_sam_l_c/tc.c
${CMAKE_CURRENT_LIST_DIR}/tc_interrupt.c
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})