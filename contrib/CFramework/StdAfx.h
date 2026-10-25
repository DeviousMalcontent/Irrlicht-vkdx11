#ifndef __STDAFX_H__
#define __STDAFX_H__

#define NOMINMAX
#define GLEW_STATIC 1
#define GL_GLEXT_LEGACY 1

#ifdef max
  #undef max
#endif
#ifdef min
  #undef min
#endif

#ifndef WIN32
#   include <GL/glew.h>
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
