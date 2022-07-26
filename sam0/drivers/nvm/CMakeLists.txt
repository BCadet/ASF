set(SRCS
${CMAKE_CURRENT_LIST_DIR}/nvm.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/nvm.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})