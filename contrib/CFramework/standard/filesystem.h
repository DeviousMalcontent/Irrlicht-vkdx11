#ifndef __CLIENT_FILESYSTEM_INTERFACE_H__
#define __CLIENT_FILESYSTEM_INTERFACE_H__

#include "Platform/Common.h"
#include <filesystem>
#include <regex>
#include <vector>

namespace System
{
    namespace Platform
    {
        // Returns the last Win32 error, in string format. Returns an empty string if there is no error.
        std::string TC_CFRAMEWORK_API GetLastErrorAsString(DWORD errorMessageID);
    }

    namespace FileSystem
    {
        // Use a safe namespace alias mapping directly to native standard C++17
        namespace fs = std::filesystem;

        typedef std::vector<fs::path> TFileList;
        
        void TC_CFRAMEWORK_API GetFileList(fs::path const& path, TFileList& result_set, bool recurisve, const std::regex* filter = nullptr);
        void TC_CFRAMEWORK_API CreateDir(fs::path const& path);

        inline bool FileExists(char const* fileName)
        {
            return fs::exists(fileName);
        }
    }
}

#endif //__CLIENT_FILESYSTEM_INTERFACE_H__
