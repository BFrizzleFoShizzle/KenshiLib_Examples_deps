#pragma once

#include <Defines.h>

#include "mygui/MyGUI_Gui.h"

namespace KenshiLib
{
    class KLIB_EXPORT BinaryVersion
    {
    public:
        enum KenshiPlatform
        {
            GOG,
            STEAM,
            UNKNOWN
        };

        BinaryVersion(KenshiPlatform platform, std::string version)
            : platform(platform), version(version)
        {

        }

        KenshiPlatform GetPlatform()
        {
            return platform;
        }

        std::string GetPlatformStr()
        {
            if (platform == KenshiPlatform::STEAM)
                return "Steam";
            if (platform == KenshiPlatform::GOG)
                return "GOG";
            return "Unknown";
        }

        std::string GetBinaryName()
        {
            if (platform == KenshiPlatform::STEAM)
                return "Kenshi_x64.exe";
            if (platform == KenshiPlatform::GOG)
                return "Kenshi_GOG_x64.exe";
            return "Unknown";
        }

        std::string ToString()
        {
            return version + " " + GetPlatformStr();
        }

        std::string GetVersion()
        {
            return version;
        }

        // used for sorting/map
        // TODO should use unordered map?
        bool operator< (const BinaryVersion& b) const
        {
            if (this->version != b.version)
                return this->version < b.version;
            return this->platform < b.platform;
        }

        bool operator== (const BinaryVersion& b) const
        {
            return this->version == b.version && this->platform == b.platform;
        }

    private:
        KenshiPlatform platform;
        // TODO should this be ints?
        std::string version;
    };

    // TODO pointer so we can make it an interface?
    KLIB_EXPORT BinaryVersion GetKenshiVersion();

    // *********** DO NOT USE ***********
    // BACKWARDS COMPATIBILITY WILL NOT BE MAINTAINED FOR INTERNAL FUNCTIONS
#ifdef KENSHILIB_INTERNAL
    KLIB_EXPORT void Init();
    // returns true on success
    KLIB_EXPORT bool OverrideKenshiVersion(BinaryVersion newVersion);

    // default 2000
    KLIB_EXPORT float& GetMaxCameraDistance();
    // default 10
    KLIB_EXPORT float& GetMinCameraDistance();
#endif
}