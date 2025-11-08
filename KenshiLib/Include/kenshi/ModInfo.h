#pragma once

#include <kenshi/util/lektor.h>
#include <kenshi/GameData.h>

class ModInfo : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    ModInfo(const ModInfo& __that);// public RVA = 0x87EC40
    ModInfo* _CONSTRUCTOR(const ModInfo& __that);// public RVA = 0x87EC40
    ModInfo();// public RVA = 0x8675C0
    ModInfo* _CONSTRUCTOR();// public RVA = 0x8675C0
    std::string name; // 0x0 Member
    std::string file; // 0x28 Member
    std::string path; // 0x50 Member
    bool isWorkshop; // 0x78 Member
    bool isBaseMod; // 0x79 Member
    std::string leveldataFolder; // 0x80 Member
    GameDataHeader header; // 0xA8 Member
    bool getLocale(std::string& localeId, std::string& localePath) const;// public RVA = 0x86DCB0
    ~ModInfo();// public RVA = 0x87CB10
    void _DESTRUCTOR();// public RVA = 0x87CB10
    ModInfo& operator=(const ModInfo& __that);// public RVA = 0x87E500
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};