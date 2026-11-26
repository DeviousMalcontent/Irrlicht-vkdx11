# set default configuration directory
if (PREFIX)
	set(CMAKE_INSTALL_PREFIX "${PREFIX}")
else()
    set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
	message(STATUS "UNIX: Using default library directory")
endif()

set(BIN_DIR    ${CMAKE_INSTALL_PREFIX}/bin)
set(LIBS_DIR   ${CMAKE_INSTALL_PREFIX}/lib)

# For Unix systems set the rpath so that libraries are found
set(CMAKE_INSTALL_RPATH    "$ORIGIN")
set(CMAKE_INSTALL_NAME_DIR ${LIBS_DIR})

if ( NOT dep)
	set(dep "${CMAKE_SOURCE_DIR}/dep")
endif()

# configure uninstaller
configure_file(
  "${CMAKE_SOURCE_DIR}/cmake/platform/cmake_uninstall.in.cmake"
  "${CMAKE_BINARY_DIR}/cmake_uninstall.cmake"
  @ONLY
)
message(STATUS "UNIX: Configuring uninstall target")

# create uninstaller target (allows for using "make uninstall")
add_custom_target(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_BINARY_DIR}/cmake_uninstall.cmake"
)
message(STATUS "UNIX: Created uninstall target")

message(STATUS "UNIX: Detected compiler: ${CMAKE_C_COMPILER}")
if(CMAKE_C_COMPILER MATCHES "clang" OR CMAKE_C_COMPILER_ID MATCHES "Clang")
  include(${CMAKE_SOURCE_DIR}/cmake/compiler/clang/settings.cmake)
elseif(CMAKE_C_COMPILER MATCHES "gcc" OR CMAKE_C_COMPILER MATCHES "cc")
  include(${CMAKE_SOURCE_DIR}/cmake/compiler/gcc/settings.cmake)
elseif(CMAKE_C_COMPILER MATCHES "icc")
  include(${CMAKE_SOURCE_DIR}/cmake/compiler/icc/settings.cmake)
endif()

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin/Linux)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin/Linux)