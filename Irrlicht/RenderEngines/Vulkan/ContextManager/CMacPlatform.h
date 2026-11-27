#ifndef __C_MVK_MANAGER_H_INCLUDED__
#define __C_MVK_MANAGER_H_INCLUDED__

#include "IrrCompileConfig.h"

#ifdef _IRR_COMPILE_WITH_OSX_DEVICE_

#include "CVulkanPlatform.h"

namespace irr
{
namespace video
{
    class CMacVulkanPlatform : public CVulkanPlatform
    {
    public:
        //! Constructor.
        CMacVulkanPlatform(CVulkanDriver* driver)
            : CVulkanPlatform(driver)
        {}

        //! Destructor
        virtual ~CMacVulkanPlatform();

        // Inherited via CVulkanPlatform
        virtual void initialize() override;
        virtual void resizeSwapBuffers() override;

    protected:
        bool mIsFullScreen = false;
    };
}
}

#endif // _IRR_COMPILE_WITH_OSX_DEVICE_

#endif
