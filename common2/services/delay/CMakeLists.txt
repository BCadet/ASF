set(SRCS
# ${CMAKE_CURRENT_LIST_DIR}/sam0/cycle_counter.c
${CMAKE_CURRENT_LIST_DIR}/sam0/systick_counter.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/delay.h
)

set_source_files_properties(${CMAKE_CURRENT_LIST_DIR}/sam0/systick_counter.c COMPILE_FLAGS "-include asf.h")
target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR}/sam0)
target_sources(ASF PUBLIC ${SRCS})