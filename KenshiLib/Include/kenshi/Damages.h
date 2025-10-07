#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>

class Damages : private Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    Damages(const Damages& t);// public RVA = 0x43FB00
    void _CONSTRUCTOR(const Damages& t);// public RVA = 0x43FB00
    Damages(float _cut, float _blunt, float _pierce, float bleed, float armour);// public RVA = 0x296720
    void _CONSTRUCTOR(float _cut, float _blunt, float _pierce, float bleed, float armour);// public RVA = 0x296720
    Damages();// public RVA = 0x643170
    void _CONSTRUCTOR();// public RVA = 0x643170
    void multiply(float mult);// public RVA = 0x337610
    float total() const;// public RVA = 0x43FB60
    // no_addr float highest();// public
    float cut; // 0x0 Member
    float blunt; // 0x4 Member
    float pierce; // 0x8 Member
    float extraStun; // 0xC Member
    float bleedMult; // 0x10 Member
    float armourPenetration; // 0x14 Member
    ~Damages();// public RVA = 0x2A9B30
    void _DESTRUCTOR();// public RVA = 0x2A9B30
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};