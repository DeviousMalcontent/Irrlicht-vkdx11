#ifndef __STDAFX_H__
#define __STDAFX_H__

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
