cmake_minimum_required( VERSION 3.0 )

SET(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/CMake
  ${CMAKE_CURRENT_SOURCE_DIR}/../../CMake
)

project(DemoApp)

include_directories(
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

SET(EXAMPLE_SOURCE_FILES
    main.cpp
    CDemo.cpp
    CMainMenu.cpp
)

if (WIN32)
    SET(EXAMPLE_SOURCE_FILES
        ${EXAMPLE_SOURCE_FILES}
        resscript.rc
    )
endif()

add_executable(Demo ${EXAMPLE_SOURCE_FILES})

target_link_libraries(Demo PRIVATE irrlicht)

if(UNIX)
    add_custom_command(TARGET Demo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/media"
        "$<TARGET_FILE_DIR:Demo>/media"
    )
endif()
