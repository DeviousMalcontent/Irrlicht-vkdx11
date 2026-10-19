# Install script for directory: E:/irrlicht/Irrlicht-vkdx11/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/IrrlichtDV")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/01.HelloWorld/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/02.Quake3Map/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/03.CustomSceneNode/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/04.Movement/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/05.UserInterface/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/06.2DGraphics/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/07.Collision/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/08.SpecialFX/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/09.Meshviewer/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/11.PerPixelLighting/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/12.TerrainRendering/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/13.RenderToTexture/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/15.LoadIrrFile/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/16.Quake3MapShader/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/17.HelloWorld_Mobile/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/18.SplitScreen/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/19.MouseAndJoystick/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/20.ManagedLights/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/21.Quake3Explorer/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/22.MaterialViewer/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/23.SMeshHandling/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/24.CursorControl/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/25.XmlHandling/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/26.OcclusionQuery/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/32.NoesisGUI/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/33.NoesisGUIWindow/cmake_install.cmake")
  include("E:/irrlicht/Irrlicht-vkdx11/build/examples/Demo/cmake_install.cmake")

endif()

