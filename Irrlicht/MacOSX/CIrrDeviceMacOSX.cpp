#include "CIrrDeviceMacOSX.h"

#ifdef _IRR_COMPILE_WITH_OSX_DEVICE_

namespace irr
{
    CIrrDeviceMacOSX::CIrrDeviceMacOSX(const SIrrlichtCreationParameters& params)
        : CIrrDeviceStub(params)
    {
        createDriver();
        if (VideoDriver)
            createGUIAndScene();
    }

    CIrrDeviceMacOSX::~CIrrDeviceMacOSX()
    {
    }
}

#endif // _IRR_COMPILE_WITH_OSX_DEVICE_
