AddBuildInLibrary( glm glm )
AddBuildInLibrary( jpeglib jpeglib )
AddBuildInLibrary( libpng libpng )
add_subdirectory( threads )
AddBuildInLibrary( zlib zlib )

IF (BUILD_IN_USE_GLSLANG)

    # Set Glslang settings and connections
    SET(SPIRV-Headers_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/SPIRV/SPIRV-Headers)
    
    add_subdirectory(SPIRV/SPIRV-Tools)
    add_subdirectory(SPIRV/Glslang)

ENDIF(BUILD_IN_USE_GLSLANG)
