/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOSSERVER_ERRORS_H
#define MANGOSSERVER_ERRORS_H

#include "Platform/Define.h"
#include "Preprocessor/pp_platform.h"
#include <csignal>
#include <stdexcept>
#include <cassert>

#ifdef WIN32
#   define ASSUME(CONDITION) __assume(CONDITION)
#else
#   define __assume(cond) do { if (!(cond)) __builtin_unreachable(); } while (0)
#   define ASSUME(CONDITION) __assume(CONDITION)
#endif

// Normal assert.
#define WPError(CONDITION) \
if (!(CONDITION)) \
{ \
    printf("%s:%i: Error: Assertion in %s failed: %s\n", \
        __FILE__, __LINE__, __FUNCTION__, STRINGIFY(CONDITION)); \
    assert(STRINGIFY(CONDITION) && 0); \
}

// Just warn.
#define WPWarning(CONDITION) \
if (!(CONDITION)) \
{ \
    printf("%s:%i: Warning: Assertion in %s failed: %s\n",\
        __FILE__, __LINE__, __FUNCTION__, STRINGIFY(CONDITION)); \
}

#ifdef NDEBUG
#  define DEBUG_ASSERT __assume
#else
#  define DEBUG_ASSERT WPError                             // Error even if in release mode.
#endif

#define ASSERT DEBUG_ASSERT
#define EXCEPT WPError

namespace System
{
	namespace Debug
	{
		TC_CFRAMEWORK_API DECLSPEC_NORETURN void Assert(char const* file, int line, char const* function, char const* message) ATTR_NORETURN;
		TC_CFRAMEWORK_API DECLSPEC_NORETURN void Assert(char const* file, int line, char const* function, char const* message, FORMAT_STRING(char const* format), ...) ATTR_NORETURN ATTR_PRINTF(5, 6);

		TC_CFRAMEWORK_API DECLSPEC_NORETURN void Fatal(char const* file, int line, char const* function, FORMAT_STRING(char const* message), ...) ATTR_NORETURN ATTR_PRINTF(4, 5);

		TC_CFRAMEWORK_API DECLSPEC_NORETURN void Error(char const* file, int line, char const* function, char const* message) ATTR_NORETURN;

		TC_CFRAMEWORK_API DECLSPEC_NORETURN void Warning(char const* file, int line, char const* function, char const* message) ATTR_NORETURN;
	} // namespace Tauri
}

namespace System
{
    //namespace Runtime
    //{
    //    TC_CFRAMEWORK_API std::string Backtrace();
    //}

struct ArgumentNullException : std::runtime_error
    {
        ArgumentNullException() : std::runtime_error("") {}
        ArgumentNullException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct ArgumentException : std::runtime_error
    {
        ArgumentException() : std::runtime_error("") {}
        ArgumentException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct AggregateException : std::runtime_error
    {
        AggregateException() : std::runtime_error("") {}
        AggregateException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct KeyNotFoundException : std::runtime_error
    {
        KeyNotFoundException() : std::runtime_error("") {}
        KeyNotFoundException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct InvalidOperationException : std::runtime_error
    {
        InvalidOperationException() : std::runtime_error("") {}
        InvalidOperationException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct NotSupportedException : std::runtime_error
    {
        NotSupportedException() : std::runtime_error("") {}
        NotSupportedException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct FormatException : std::runtime_error
    {
        FormatException() : std::runtime_error("") {}
        FormatException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct InvalidCastException : std::runtime_error
    {
        InvalidCastException() : std::runtime_error("") {}
        InvalidCastException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct TargetInvocationException : std::runtime_error
    {
        TargetInvocationException() : std::runtime_error("") {}
        TargetInvocationException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct NotImplementedException : std::runtime_error
    {
        NotImplementedException() : std::runtime_error("") {}
        NotImplementedException(const char* msg)
            : std::runtime_error(msg) {}
    };

    struct ArgumentOutOfRangeException : std::runtime_error
    {
        ArgumentOutOfRangeException() : std::runtime_error("") {}
        ArgumentOutOfRangeException(const char* msg)
            : std::runtime_error(msg) {}
    };

    template<typename TException>
    void ThrowIfFailed(bool condition, void(*actionOnFailed)() = nullptr)
    {
        if (!condition)
        {
            if (actionOnFailed != nullptr)
                actionOnFailed();
            throw TException();
        }
    }

    template<typename TException>
    void ThrowIfFailed(bool condition, const char* message, void(*actionOnFailed)() = nullptr)
    {
        if (!condition)
        {
            if (actionOnFailed != nullptr)
                actionOnFailed();
            throw TException(message);
        }
    }
}

namespace boost
{
    TC_CFRAMEWORK_API DECLSPEC_NORETURN void OutException(FORMAT_STRING(const char* fmt), ...) ATTR_NORETURN ATTR_PRINTF(1, 2);

#ifdef BOOST_ENABLE_ASSERT_HANDLER
    inline void assertion_failed(char const * expr, char const * function, char const * file, long line)
    {
        boost::OutException("[BOOST Assertion Fault]: expr %s  %s %s:%d", expr, function, file, line);
        ((IsDebuggerPresent() ? __debugbreak() : raise(SIGINT)), 0);
    }

    inline void assertion_failed_msg(char const * expr, char const * msg, char const * function, char const * file, long line)
    {
        boost::OutException("[BOOST Assertion Fault]: %s expr %s  %s %s:%d", msg, expr, function, file, line);
        ((IsDebuggerPresent() ? __debugbreak() : raise(SIGINT)), 0);
    }
#endif

} // namespace boost


#if COMPILER == COMPILER_MICROSOFT
#define ASSERT_BEGIN __pragma(warning(push)) __pragma(warning(disable: 4127))
#define ASSERT_END __pragma(warning(pop))
#else
#define ASSERT_BEGIN
#define ASSERT_END
#endif

#define WPAssert(cond, ...) ASSERT_BEGIN do { if (!(cond)) System::Debug::Assert(__FILE__, __LINE__, __FUNCTION__, #cond, ##__VA_ARGS__); } while(0) ASSERT_END
#define WPFatal(cond, ...) ASSERT_BEGIN do { if (!(cond)) System::Debug::Fatal(__FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); } while(0) ASSERT_END

template <typename T> inline T* ASSERT_NOTNULL(T* pointer)
{
    EXCEPT(pointer);
    return pointer;
}

#ifndef _WIN32
#   define DEBUG_ASM_BREAK asm("int $3")
#   define DEBUG_BREAK raise(SIGTRAP)
#else
#   define DEBUG_ASM_BREAK __asm { int 3 }
#   define DEBUG_BREAK ((IsDebuggerPresent() ? __debugbreak() : raise(SIGINT)), 0)
#endif

#define ABORT() WPAssert(false)

#endif
