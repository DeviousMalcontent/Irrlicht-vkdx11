SET(MODUL_NAME "CFramework")
SET(MODUL_LINKAGE "SHARED")
SET(MODUL_LINK_LIBS "")
SET(MODUL_LINK_FLAGS "")

list(APPEND MODUL_LINK_LIBS
PRIVATE
    ZLIB
	glm
)

# Glob only and not recurse, there are other libs for that
file(GLOB_RECURSE MODUL_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.c *.cc *.hpp *.h)

CreateLibrary("CFramework" "${MODUL_SRCS}" "${MODUL_LINKAGE}" "${MODUL_LINK_LIBS}" "${MODUL_LINK_FLAGS}")
CreateCxxPch("CFramework" "${CMAKE_CURRENT_SOURCE_DIR}/StdAfx.h" "${CMAKE_CURRENT_SOURCE_DIR}/StdAfx.cpp")

find_package(fmt CONFIG QUIET)
if(fmt_FOUND)
    target_include_directories(CFramework PUBLIC $<TARGET_PROPERTY:fmt::fmt-header-only,INTERFACE_INCLUDE_DIRECTORIES>)
    target_compile_definitions(CFramework PUBLIC $<TARGET_PROPERTY:fmt::fmt-header-only,INTERFACE_COMPILE_DEFINITIONS>)
    target_compile_options(CFramework PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/utf-8>)
endif()

target_include_directories(CFramework
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}/.Assembly
        ${CMAKE_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}/dep
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(CFramework
    PUBLIC  TC_DYNAMIC_CFRAMEWORK
    PRIVATE TC_API_EXPORT_CFRAMEWORK)

target_include_directories(CFramework INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(CFramework
    PROPERTIES
      FOLDER
        "Contrib")
