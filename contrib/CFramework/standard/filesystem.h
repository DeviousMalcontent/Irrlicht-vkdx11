#ifndef __SYSTEM_FILESYSTEM_H__
#define __SYSTEM_FILESYSTEM_H__

#include <vector>
//#include "Platform/Common.h"
//#include <filesystem>
#include <regex>

#if defined(__has_include) && __has_include(<filesystem>)
#  include <filesystem>
#  // If the compiler is stuck in an older mode but has the header, 
#  // some versions map it to experimental instead. Let's make an alias.
   namespace std {
       #if __cplusplus < 201703L && defined(__cpp_lib_experimental_filesystem)
           namespace filesystem = experimental::filesystem;
       #endif
   }
#elif __has_include(<experimental/filesystem>)
#  include <experimental/filesystem>
   namespace std {
       namespace filesystem = experimental::filesystem;
   }
#endif

namespace System
{
    namespace FileSystem
    {
#if defined(__cpp_lib_filesystem) || (__cplusplus >= 201703L)
        namespace fs = std::filesystem;
#else
        namespace fs = std::experimental::filesystem;
#endif
        typedef std::vector<fs::path> TFileList;
        
        void TC_CFRAMEWORK_API GetFileList(fs::path const& path, TFileList& result_set, bool recurisve, const std::regex* filter = nullptr);
        void TC_CFRAMEWORK_API CreateDir(fs::path const& path);

        inline bool FileExists(const char* fileName)
        {
            return fs::exists(fileName);
        }
    }
}

#endif //__CLIENT_FILESYSTEM_INTERFACE_H__
