set(SRCS
${CMAKE_CURRENT_LIST_DIR}/system_samc21.c
)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/system_samc21.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_sources(ASF PUBLIC ${SRCS})

option(EXTERNAL_STARTUP "use external startup file" OFF)

if(NOT EXTERNAL_STARTUP)
add_subdirectory(gcc)
endif()