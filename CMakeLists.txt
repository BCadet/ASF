# cmake_minimum_required(VERSION 3.16)

# SET(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/../cmake/gcc-arm-cortex.cmake)
# SET(TOOLCHAIN_PREFIX ${CMAKE_CURRENT_LIST_DIR}/../gcc-arm-none-eabi-10.3-2021.10/)
# SET(CORTEX_TYPE M0P)

# project (ASF)

add_library(ASF)

target_include_directories(ASF PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/../CMSIS/Core/Include
${PROJECT_HDRS}
)

add_subdirectory(common)
add_subdirectory(common2)
add_subdirectory(sam0)
add_subdirectory(thirdparty)

# install(
#   EXPORT ASFTargets
#   DESTINATION ${CMAKE_BINARY_DIR}/cmake/ASF
#   NAMESPACE ASF::
#   FILE ASFTargets.cmake # Not sure if this is still needed
#   )

# include(CMakePackageConfigHelpers)
# configure_package_config_file( 
#   "Config.cmake.in" 
#   "ASFConfig.cmake"
#   INSTALL_DESTINATION ${CMAKE_BINARY_DIR}/cmake/ASF
#   PATH_VARS
#     CMAKE_BINARY_DIR
#   )

# write_basic_package_version_file(
#   ${CMAKE_CURRENT_BINARY_DIR}/ASFConfigVersion.cmake
#   VERSION 1.0.0
#   COMPATIBILITY SameMajorVersion
#   )

# ### Install Config and ConfigVersion files
# install(
#   FILES "${CMAKE_CURRENT_BINARY_DIR}/ASFConfig.cmake"
#         "${CMAKE_CURRENT_BINARY_DIR}/ASFConfigVersion.cmake"
#   DESTINATION "${CMAKE_BINARY_DIR}/cmake/ASF"
#   )

