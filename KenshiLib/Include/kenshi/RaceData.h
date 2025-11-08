#pragma once


#include <string>
#include <ogre/OgreColourValue.h>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/Enums.h>
#include <kenshi/Item.h>


class GameData;
class RaceGroupData;

class RaceData
{
public:
    ogre_unordered_set<GameData*>::type specialFoods; // 0x0 Member
    static boost::unordered::unordered_map<std::string, RaceData*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, RaceData*>, Ogre::GeneralAllocPolicy > > AllRaces; // RVA = 0x1D81CC0 Static Member
    static RaceData* getRaceData(const std::string& stringID);// public RVA = 0x42F7D0
    static RaceData* getRaceData(GameData* data);// public RVA = 0x42FC70
    // no_addr void RaceData(const class RaceData & _a1);// public missing arg names
    RaceData(GameData* data);// public RVA = 0x42E820
    RaceData* _CONSTRUCTOR(GameData* data);// public RVA = 0x42E820
    bool isRelatedRace(RaceData* data);// public RVA = 0x670A20
    bool isRelatedRace(GameData* d);// public RVA = 0x42E550
    bool isSpecificRace(GameData* subrace);// public RVA = 0x670A10
    float getStatMod(StatsEnumerated stat);// public RVA = 0x65CE70
    bool canEat(GameData* food, bool isAnimal) const;// public RVA = 0x42E6D0
    bool canEat(Item* food, bool isAnimal) const;// public RVA = 0x42E5B0
    GameData* data; // 0x40 Member
    float runSpeedMaxSkill; // 0x48 Member
    float runSpeedMinSkill; // 0x4C Member
    float originalBloodMin; // 0x50 Member
    float originalBloodMax; // 0x54 Member
    float healRate; // 0x58 Member
    float bleedRate; // 0x5C Member
    float swimSpeed; // 0x60 Member
    float walkSpeed; // 0x64 Member
    float swimOffset; // 0x68 Member
    float waterAvoidance; // 0x6C Member
    float hungerRate; // 0x70 Member
    float visionMultiplier; // 0x74 Member
    bool gigantic; // 0x78 Member
    bool swims; // 0x79 Member
    bool carriable; // 0x7A Member
    bool singleGender; // 0x7B Member
    bool robot; // 0x7C Member
    bool vampiric; // 0x7D Member
    bool noHats; // 0x7E Member
    bool noShirts; // 0x7F Member
    bool noShoes; // 0x80 Member
    int extraAttackSlots; // 0x84 Member
    StatsEnumerated firstAidSkill; // 0x88 Member
    Ogre::ColourValue bloodColour; // 0x8C Member
    bool canGoIndoors; // 0x9C Member
    ogre_unordered_map<StatsEnumerated, float>::type statMods; // 0xA0 Member
    ogre_unordered_set<WeatherAffecting>::type weatherImmunities; // 0xE0 Member
    bool isImmune(WeatherAffecting w) const;// public RVA = 0x5E75A0
    RaceGroupData* raceGroup; // 0x120 Member
    // no_addr void ~RaceData();// public
    // no_addr class RaceData & operator=(const class RaceData & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};