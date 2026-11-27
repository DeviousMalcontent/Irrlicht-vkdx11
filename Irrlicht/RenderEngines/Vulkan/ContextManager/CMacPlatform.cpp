#include "CMacPlatform.h"
#include "CVulkanDriver.h"
#include "CVulkanDevice.h"
#include "CVulkanSwapChain.h"

#ifdef _IRR_COMPILE_WITH_OSX_DEVICE_

#include <vulkan/vulkan_metal.h>

irr::video::CMacVulkanPlatform::~CMacVulkanPlatform()
{
}

void irr::video::CMacVulkanPlatform::initialize()
{
    VkMetalSurfaceCreateInfoEXT surfaceCreateInfo = {};
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT;
    surfaceCreateInfo.pNext = nullptr;
    surfaceCreateInfo.flags = 0;
    surfaceCreateInfo.pLayer = static_cast<const CAMetalLayer*>(mDriver->mCreateParams.WindowId);

    VkInstance instance = mDriver->_getInstance();
    auto fpCreateMetalSurfaceEXT = reinterpret_cast<PFN_vkCreateMetalSurfaceEXT>(
        vkGetInstanceProcAddr(instance, "vkCreateMetalSurfaceEXT"));
    if (!fpCreateMetalSurfaceEXT)
        throw std::runtime_error("VK_EXT_metal_surface extension is not available.");

    VkResult result = fpCreateMetalSurfaceEXT(instance, &surfaceCreateInfo, VulkanDevice::gVulkanAllocator, &mSurface);
    assert(result == VK_SUCCESS);

    VulkanDevice* presentDevice = mDriver->_getPrimaryDevice();
    VkPhysicalDevice physicalDevice = presentDevice->getPhysical();

    mPresentQueueFamily = presentDevice->getQueueFamily(GQT_GRAPHICS);

    VkBool32 supportsPresent = VK_FALSE;
    vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, mPresentQueueFamily, mSurface, &supportsPresent);

    if (!supportsPresent)
        throw std::runtime_error("Cannot find a graphics queue that also supports present operations.");

    SurfaceFormat format = presentDevice->getSurfaceFormat(mSurface, mDriver->mCreateParams.Stencilbuffer, false);
    mColorFormat = format.colorFormat;
    mColorSpace = format.colorSpace;
    mDepthFormat = format.depthFormat;

    mSwapChain = new VulkanSwapChain();
    mSwapChain->rebuild(presentDevice, mSurface, mDriver->getScreenSize().Width, mDriver->getScreenSize().Height, mDriver->mCreateParams.Vsync, mColorFormat, mColorSpace, true, mDepthFormat);
}

void irr::video::CMacVulkanPlatform::resizeSwapBuffers()
{
    mDriver->_getPrimaryDevice()->waitIdle();
    mSwapChain->rebuild(mDriver->_getPrimaryDevice(), mSurface, mDriver->getScreenSize().Width, mDriver->getScreenSize().Height, mDriver->mCreateParams.Vsync, mColorFormat, mColorSpace, true, mDepthFormat);
}

#endif // _IRR_COMPILE_WITH_OSX_DEVICE_
