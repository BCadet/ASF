set(SRCS
${CMAKE_CURRENT_LIST_DIR}/sercom.c
${CMAKE_CURRENT_LIST_DIR}/sercom_interrupt.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/sercom.h
${CMAKE_CURRENT_LIST_DIR}/sercom_interrupt.h
${CMAKE_CURRENT_LIST_DIR}/sercom_pinout.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})

add_subdirectory(usart)
add_subdirectory(spi)