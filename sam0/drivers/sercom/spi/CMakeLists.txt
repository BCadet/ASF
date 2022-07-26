set(SRCS
${CMAKE_CURRENT_LIST_DIR}/spi_interrupt.c
${CMAKE_CURRENT_LIST_DIR}/spi.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/spi_interrupt.h
${CMAKE_CURRENT_LIST_DIR}/spi.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})