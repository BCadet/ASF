if(ASF_STDIO)
set(SRCS
${CMAKE_CURRENT_LIST_DIR}/read.c
${CMAKE_CURRENT_LIST_DIR}/write.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/stdio_serial/stdio_serial.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR}/stdio_serial)
target_sources(ASF PUBLIC ${SRCS})
endif()