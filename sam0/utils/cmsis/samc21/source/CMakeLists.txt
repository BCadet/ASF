set(SRCS
${CMAKE_CURRENT_LIST_DIR}/system_samc21.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/system_samc21.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})

add_subdirectory(gcc)