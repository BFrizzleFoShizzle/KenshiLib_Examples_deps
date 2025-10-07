#pragma once

#include <Defines.h>

#include "mygui/MyGUI_Gui.h"
class GameWorld;
class InputHandler;
class GlobalConstants;
class OptionsHolder;
class SaveManager;
class SaveFileSystem;

namespace Kenshi 
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

    KLIB_EXPORT void Init();
    // TODO pointer so we can make it an interface?
    KLIB_EXPORT BinaryVersion GetKenshiVersion();
    // returns true on success
    KLIB_EXPORT bool OverrideKenshiVersion(BinaryVersion newVersion);

    // GameWorld looks to be an object of all game state, whether its loaded or not.
    // Has things like a list of loaded mods and all the GameData loaded in, probably saves too.
    // GameWorld ou;
    KLIB_EXPORT GameWorld& GetGameWorld();

    // default 2000
    KLIB_EXPORT float& GetMaxCameraDistance();
    // default 10
    KLIB_EXPORT float& GetMinCameraDistance();

    // Not 100% sure what this is called
    KLIB_EXPORT InputHandler& GetInputHandler();

    // Static var separate to GameWorld
    // GlobalConstants con;
    KLIB_EXPORT GlobalConstants* GetCon();

    // OptionsHolder options;
    KLIB_EXPORT OptionsHolder* GetOptions();

    KLIB_EXPORT SaveManager* GetSaveManager();
    KLIB_EXPORT SaveFileSystem* GetSaveFileSystem();
}