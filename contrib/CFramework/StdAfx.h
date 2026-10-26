#ifndef __STDAFX_H__
#define __STDAFX_H__

#define NOMINMAX
#ifndef WIN32
#   define GLEW_STATIC 1
#   define GL_GLEXT_LEGACY 1
#   define GLX_GLXEXT_LEGACY 1
#   define __glext_h_ 1
#   define __glxext_h_ 1
#   define __glext_h_ festival_bypass
#   define __glxext_h_ festival_bypass
#   define GL_GLEXT_PROTOTYPES 0
#   include <GL/glew.h>
#endif

#ifdef max
  #undef max
#endif
#ifdef min
  #undef min
#endif

#include <algorithm>
#include <string>

#include <atomic>
#include <future>
#include "System/System.h"
#include "standard/events.h"
#include "Threading/Threading.h"
#include "standard/concurrentQueue.h"

#include "standard/Platform/Common.h"
#include "standard/client/DataSource_Standard.h"

#endif
