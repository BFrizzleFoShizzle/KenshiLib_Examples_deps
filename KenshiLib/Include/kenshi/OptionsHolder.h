#pragma once

#include <string>
#include "util/lektor.h"

class OptionsHolder
{
public:
    // no_addr void OptionsHolder(const class OptionsHolder & _a1);// public missing arg names
    OptionsHolder();// public RVA = 0x3E83B0
    void _CONSTRUCTOR();// public RVA = 0x3E83B0
    float CAMERA_MOVE_SPEED; // 0x0 Member
    float CAMERA_PAN_SPEED; // 0x4 Member
    float CAMERA_TILT_SPEED; // 0x8 Member
    float CAMERA_ZOOM_SPEED; // 0xC Member
    float invertX; // 0x10 Member
    float invertY; // 0x14 Member
    float VIEW_DISTANCE; // 0x18 Member
    float terrainDetail; // 0x1C Member
    float terrainDistant; // 0x20 Member
    float terrainThreshold; // 0x24 Member
    int terrainPatchSize; // 0x28 Member
    float grassRange; // 0x2C Member
    float grassDensity; // 0x30 Member
    float foliageRange; // 0x34 Member
    float NPCRange; // 0x38 Member
    float smallBuildingRange; // 0x3C Member
    bool stencilsDisabled; // 0x40 Member
    bool fancyShaders; // 0x41 Member
    bool HWmouse; // 0x42 Member
    bool tutorials; // 0x43 Member
    bool enabledCivilians();// public RVA = 0x569980
    bool _enabledCivilians; // 0x44 Member
    float populationMult; // 0x48 Member
    float squadSizeMult; // 0x4C Member
    float raidSizeMult; // 0x50 Member
    float raidFrequencyMult; // 0x54 Member
    int passingAttacksOnBase; // 0x58 Member
    int shadowMode; // 0x5C Member
    int shadowQuality; // 0x60 Member
    float harpoonLimit; // 0x64 Member
    float decalRange; // 0x68 Member
    int decalResolution; // 0x6C Member
    bool characterMultithreading; // 0x70 Member
    bool characterMultithreadingEnabled();// public RVA = 0x785380
    int limbLossFrequency; // 0x74 Member
    bool showNames; // 0x78 Member
    bool edgeScrolling; // 0x79 Member
    int damageFloaters; // 0x7C Member
    bool showRotationMarker; // 0x80 Member
    bool showMoveMarker; // 0x81 Member
    float fontSize; // 0x84 Member
    bool manyActiveZones; // 0x88 Member
    float distantTownRange; // 0x8C Member
    float featureRange; // 0x90 Member
    bool generateDistantTowns; // 0x94 Member
    float shadowRange; // 0x98 Member
    int ddsTextureMipMapGimping; // 0x9C Member
    int reflectionMode; // 0xA0 Member
    float reflectionDistance; // 0xA4 Member
    // Typedef        : CompositorInfo
    lektor<std::pair<std::string, bool> > compositors; // 0xA8 Member
    bool compositiorEnabled(const std::string& name) const;// public RVA = 0x3E7730
    void loadCompositorSettings();// public RVA = 0x3EA670
    float musicVolume; // 0xC0 Member
    float ambientVolume; // 0xC4 Member
    float footstepVolume; // 0xC8 Member
    float sfxVolume; // 0xCC Member
    float uiVolume; // 0xD0 Member
    float voVolume; // 0xD4 Member
    float musicFrequency; // 0xD8 Member
    float autosavetime; // 0xDC Member
    bool fullscreen; // 0xE0 Member
    bool borderless; // 0xE1 Member
    bool autosave; // 0xE2 Member
    bool userSaves; // 0xE3 Member
    bool blood; // 0xE4 Member
    bool censorship; // 0xE5 Member
    ~OptionsHolder();// public RVA = 0x8227B0
    void _DESTRUCTOR();// public RVA = 0x8227B0
    // no_addr class OptionsHolder & operator=(const class OptionsHolder & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};