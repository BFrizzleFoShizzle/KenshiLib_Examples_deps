#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <string>
#include <boost/thread/shared_mutex.hpp>

#include "Enums.h"
#include "util/lektor.h"

class RootObjectBase;
class GameData;
class Faction;
class FactoryCallbackInterface;
class RootObjectContainer;
class GameSaveState;
class Building;
class Layout;
class TownBase;
class LocationNode;
class Item;
class hand;
class GameDataReference;

// TODO move?
class TripleInt
{
public:
    int value[0x3]; // 0x0 Member
    TripleInt(const TripleInt& who);// public RVA = 0x8AF30
    TripleInt* _CONSTRUCTOR(const TripleInt& who);// public RVA = 0x8AF30
    TripleInt(int a, int b, int c);// public RVA = 0x6DF10
    TripleInt* _CONSTRUCTOR(int a, int b, int c);// public RVA = 0x6DF10
    TripleInt();// public RVA = 0x2B49D0
    TripleInt* _CONSTRUCTOR();// public RVA = 0x2B49D0
    const TripleInt& operator=(const TripleInt& a);// public RVA = 0x6DF30
    int operator[](int i) const;// public RVA = 0x64530
    int& operator[](int i);// public RVA = 0x6DF50
    static TripleInt ZERO; // RVA = 0x212E9A0 Static Member
};

class RootObject;
class UnloadedPlatoon;
class Ownerships;
class Platoon;
class AreaBiomeGroup;
class RaceData;

class RootObjectFactory : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    RootObjectBase* create(GameData* data, Ogre::Vector3 position, bool isFromActiveLevelMod, Faction* owner, Ogre::Quaternion rotation, FactoryCallbackInterface* callbackObject, RootObjectContainer* certainContainer, GameSaveState* state, bool invisible, Building* homeBuilding, float age);// public RVA = 0x582C80
    Building* createBuilding(GameData* data, Ogre::Vector3 position, TownBase* t, Faction* owner, Ogre::Quaternion rotation, FactoryCallbackInterface* callbackObject, Layout* furnitureOf, Building* isDoorOf, GameSaveState* saveState, Building* isIndoorsOf, bool invisible, bool completed, bool isFoliage, int floorNumber, bool isOutsideFurniture);// public RVA = 0x57C4F0
    LocationNode* createLocationNode(bool addToNodeListAutomatically, GameData* data, Ogre::Vector3 position, Building* building, Faction* owner, Ogre::Quaternion rotation, GameSaveState* saveState, const std::string& nodeId);// public RVA = 0x57C0E0
    Item* createItem(GameData* gd, const hand& handle, GameData* weaponMesh, GameData* matData, int levelOverride, Faction* flagUniform);// public RVA = 0x57FFD0
    Item* createItem(GameData* itemState);// public RVA = 0x582900
    Item* copyItem(Item* from);// public RVA = 0x57B8B0
    GameData* chooseDataFromList(GameData* dataList, const std::string& listName, itemType materialDataType, int useVal012);// public RVA = 0x57FB90
    const GameDataReference* chooseDataFromListWithVals(GameData* dataList, const std::string& listName, itemType materialDataType, int useVal012);// public RVA = 0x57F5C0
    TripleInt getValsFromDataInList(GameData* dataList, GameData* itemInList, const std::string& listName);// public RVA = 0x57BE30
    void createCharacterForBuilding(Building* b);// public RVA = 0x585D90
    RootObject* createRandomCharacter(Faction* faction, Ogre::Vector3 position, RootObjectContainer* owner, GameData* characterTemplate, Building* home, float age);// public RVA = 0x582F60
    GameSaveState createRandomUnloadedCharacter(Faction* faction, UnloadedPlatoon* platoon, Ogre::Vector3 position, GameData* characterTemplate, Ownerships* owns);// public RVA = 0x57BE00
    Platoon* createRandomSquad(Faction* faction, Ogre::Vector3 position, TownBase* homeTown, int maxnum, Building* home, GameData* squad, RootObjectContainer* ownr, AreaBiomeGroup* maparea, Platoon* _activePlatoon, bool permanentsquad, const hand& AItarget, TownBase* targetTown, float sizeMultiplier, SquadType squadType, bool isJustARefresh);// public RVA = 0x583290
    Platoon* createRandomUnloadedSquad(Faction* faction, Ogre::Vector3 position, TownBase* homeTown, int maxnum, Building* home, GameData* squad, RootObjectContainer* owner, AreaBiomeGroup* maparea, bool permanentsquad, const hand& AItarget, TownBase* targetTown, SquadType squadType);// public RVA = 0x57ED40
    void mainThreadUpdate();// public RVA = 0x582B90
    void populateBuilding(Building* building);// public RVA = 0x57F0A0
    static void chooseMyClothing(lektor<GameData*>& gear, GameData* dataList, const std::string& listName, RaceData* race, bool noShoes);// public RVA = 0x580E20
    static GameData* _chooseClothingItemFromList(GameData* dataList, const std::string& listName, AttachSlot slot, RaceData* race);// private RVA = 0x57FC10
    class CreatelistItem
    {
    public:
        CreatelistItem(GameData* _data, Ogre::Vector3 _position, bool _isFromActiveLevelMod, Faction* _owner, Ogre::Quaternion _rotation, FactoryCallbackInterface* _callbackObject, GameSaveState* _saveStateDataSource, RootObjectContainer* certainContainer, Building* home, float _age);// public RVA = 0x5890E0
        CreatelistItem* _CONSTRUCTOR(GameData* _data, Ogre::Vector3 _position, bool _isFromActiveLevelMod, Faction* _owner, Ogre::Quaternion _rotation, FactoryCallbackInterface* _callbackObject, GameSaveState* _saveStateDataSource, RootObjectContainer* certainContainer, Building* home, float _age);// public RVA = 0x5890E0
        RootObjectContainer* container; // 0x0 Member
        Building* homeBuilding; // 0x8 Member
        Faction* faction; // 0x10 Member
        GameData* data; // 0x18 Member
        Ogre::Vector3 position; // 0x20 Member
        bool isFromActiveLevelMod; // 0x2C Member
        Ogre::Quaternion rotation; // 0x30 Member
        FactoryCallbackInterface* callbackObject; // 0x40 Member
        GameSaveState* saveState; // 0x48 Member
        float age; // 0x50 Member
        // no_addr class RootObjectFactory::CreatelistItem & operator=(const class RootObjectFactory::CreatelistItem & _a1);// public missing arg names
    };
    boost::shared_mutex todoMutex; // 0x0 Member
    std::deque<RootObjectFactory::CreatelistItem*, std::allocator<RootObjectFactory::CreatelistItem*> > todoList; // 0x20 Member
    RootObjectBase* process(RootObjectFactory::CreatelistItem* o);// private RVA = 0x580FF0
    // no_addr void RootObjectFactory(const class RootObjectFactory & _a1);// public missing arg names
    RootObjectFactory();// public RVA = 0x87EBF0
    RootObjectFactory* _CONSTRUCTOR();// public RVA = 0x87EBF0
    ~RootObjectFactory();// public RVA = 0x87CC10
    void _DESTRUCTOR();// public RVA = 0x87CC10
    // no_addr class RootObjectFactory & operator=(const class RootObjectFactory & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};