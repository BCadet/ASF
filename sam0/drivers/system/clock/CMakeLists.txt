set(SRCS

)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/clock.h
${CMAKE_CURRENT_LIST_DIR}/gclk.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
# target_sources(ASF ${SRCS})

add_subdirectory(clock_samc20_c21)