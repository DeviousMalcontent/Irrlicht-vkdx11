#ifndef __STDAFX_H__
#define __STDAFX_H__

#ifndef WIN32
#   define GLEW_STATIC 1
#   define GL_GLEXT_LEGACY 1
#   define GLX_GLXEXT_LEGACY 1
#   define GL_GLEXT_PROTOTYPES 0
#   define __glext_h_ 1
#   define __glxext_h_ 1
#   include <GL/glew.h>
#endif

#define NOMINMAX

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
