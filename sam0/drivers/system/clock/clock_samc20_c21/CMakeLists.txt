set(SRCS
${CMAKE_CURRENT_LIST_DIR}/clock.c
${CMAKE_CURRENT_LIST_DIR}/gclk.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/clock_config_check.h
${CMAKE_CURRENT_LIST_DIR}/clock_feature.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})
