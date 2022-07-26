set(SRCS
${CMAKE_CURRENT_LIST_DIR}/usart.c
${CMAKE_CURRENT_LIST_DIR}/usart_interrupt.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/usart.h
${CMAKE_CURRENT_LIST_DIR}/usart_interrupt.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})
