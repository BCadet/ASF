set(SRCS
${CMAKE_CURRENT_LIST_DIR}/system_interrupt.c
)

set(HDRS
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PRIVATE ${SRCS})

add_subdirectory(system_interrupt_samc20_c21)