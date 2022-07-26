set(SRCS
${CMAKE_CURRENT_LIST_DIR}/tcc.c
${CMAKE_CURRENT_LIST_DIR}/tcc_callback.c
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})