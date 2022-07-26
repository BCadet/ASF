set(SRCS
${CMAKE_CURRENT_LIST_DIR}/extint_callback.c
${CMAKE_CURRENT_LIST_DIR}/extint_sam_l_c/extint.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/extint.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR}/module_config)
target_sources(ASF PUBLIC ${SRCS})