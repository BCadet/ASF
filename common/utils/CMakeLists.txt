set(SRCS

)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/interrupt.h
${CMAKE_CURRENT_LIST_DIR}/parts.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
# target_sources(ASF ${SRCS})

add_subdirectory(interrupt)