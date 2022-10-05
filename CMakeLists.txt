# cmake_minimum_required(VERSION 3.16)

# SET(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/../cmake/gcc-arm-cortex.cmake)
# SET(TOOLCHAIN_PREFIX ${CMAKE_CURRENT_LIST_DIR}/../gcc-arm-none-eabi-10.3-2021.10/)
# SET(CORTEX_TYPE M0P)

# project (ASF)

option(ASF_STDIO "enable stdio stubs in ASF" ON)
option(ASF_SYSCALLS "enable syscalls definitions in ASF" ON)
option(ASF_EXTERNAL_STARTUP "use external startup file" OFF)

add_library(ASF)

target_include_directories(ASF PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/../CMSIS/Core/Include
${PROJECT_HDRS}
)

add_subdirectory(common)
add_subdirectory(common2)
add_subdirectory(sam0)
add_subdirectory(thirdparty)

option(ASF_DOCUMENTATION "Build the asf documentation with Doxygen" OFF)
if(ASF_DOCUMENTATION)
    message(STATUS "[ASF] Documentation build enabled: asf-doc")
    get_target_property(ASF_SOURCES ASF SOURCES)
    get_target_property(ASF_HEADERS ASF INCLUDE_DIRECTORIES)
    find_package(Doxygen REQUIRED dot)
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/documentation/asf")
    set(DOXYGEN_PROJECT_NAME "ASF")
    set(DOXYGEN_GENERATE_TAGFILE "${CMAKE_BINARY_DIR}/documentation/asf.tag")
    set(DOXYGEN_GENERATE_TREEVIEW "YES")
    doxygen_add_docs(asf-doc "${ASF_SOURCES};${ASF_HEADERS}")
endif()
