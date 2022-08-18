set(SRCS

)

set(HDRS
${CMAKE_CURRENT_LIST_DIR}/compiler.h
${CMAKE_CURRENT_LIST_DIR}/status_code.h
)

target_include_directories(ASF PUBLIC ${CMAKE_CURRENT_LIST_DIR})
# target_sources(ASF ${SRCS})

add_subdirectory(cmsis)
add_subdirectory(header_files)
add_subdirectory(preprocessor)
if(ASF_SYSCALLS)
add_subdirectory(syscalls)
endif()
add_subdirectory(stdio)