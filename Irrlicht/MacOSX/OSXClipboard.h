#ifndef __C_OSX_CLIPBOARD_H_INCLUDED__
#define __C_OSX_CLIPBOARD_H_INCLUDED__

inline void OSXCopyToClipboard(const char* text)
{
    (void)text;
}

inline const char* OSXCopyFromClipboard()
{
    return nullptr;
}

#endif
