set(SRCS
${CMAKE_CURRENT_LIST_DIR}/dma.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/dma.h
${CMAKE_CURRENT_LIST_DIR}/dma_crc.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})