set(SRCS
${CMAKE_CURRENT_LIST_DIR}/events_hooks.c
${CMAKE_CURRENT_LIST_DIR}/events_sam_l_c/events.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/events_common.h
${CMAKE_CURRENT_LIST_DIR}/events.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})