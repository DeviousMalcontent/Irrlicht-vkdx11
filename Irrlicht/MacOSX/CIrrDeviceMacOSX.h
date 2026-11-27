#ifndef __C_IRR_DEVICE_MACOSX_H_INCLUDED__
#define __C_IRR_DEVICE_MACOSX_H_INCLUDED__

#include "IrrCompileConfig.h"

#ifdef _IRR_COMPILE_WITH_OSX_DEVICE_

#include "SIrrCreationParameters.h"
#include "CIrrDeviceStub.h"
#include "IImagePresenter.h"
#include <unistd.h>

namespace irr
{
    class CIrrDeviceMacOSX : public CIrrDeviceStub, public video::IImagePresenter
    {
    public:
        CIrrDeviceMacOSX(const SIrrlichtCreationParameters& params)
            : CIrrDeviceStub(params)
        {
            createDriver();
            if (VideoDriver)
                createGUIAndScene();
        }

        virtual ~CIrrDeviceMacOSX() {}

        virtual bool run() override { return !Close; }
        virtual void yield() override { usleep(0); }
        virtual void sleep(u32 timeMs, bool pauseTimer = false) override
        {
            if (pauseTimer && Timer) Timer->stop();
            usleep(timeMs * 1000);
            if (pauseTimer && Timer) Timer->start();
        }
        virtual void setWindowCaption(const wchar_t* text) override {}
        virtual bool isWindowActive() const override { return true; }
        virtual bool isWindowFocused() const override { return true; }
        virtual bool isWindowMinimized() const override { return false; }
        virtual bool present(video::IImage* surface, void* windowId = 0, core::rect<s32>* src = 0) override { return true; }
        virtual void closeDevice() override { Close = true; }
        virtual void setResizable(bool resize = false) override {}
        virtual void minimizeWindow() override {}
        virtual void maximizeWindow() override {}
        virtual void restoreWindow() override {}
        virtual E_DEVICE_TYPE getType() const override { return EIDT_OSX; }
    };
}

#endif // _IRR_COMPILE_WITH_OSX_DEVICE_

#endif // __C_IRR_DEVICE_MACOSX_H_INCLUDED__
