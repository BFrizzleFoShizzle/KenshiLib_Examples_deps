#pragma once

#include "RootObject.h"
#include <string>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <ogre/Math/Simple/OgreAabb.h>
#include <kenshi/InstanceID.h>
#include <kenshi/Enums.h>
#include <kenshi/PhysicsCollection.h>

enum BuildingFunction
{
    BF_ANY,
    BF_MINE,
    BF_RESOURCE_STORAGE,
    BF_RESEARCH,
    BF_REFINERY,
    BF_GENERATOR,
    BF_BED,
    BF_TRAINING,
    BF_CAGE,
    BF_SHOP,
    BF_CRAFTING,
    BF_CORPSE_DISPOSAL,
    BF_TURRET,
    BF_GENERAL_STORAGE,
    BF_ITEM_FURNACE,
    BF_LIGHT,
    BF_TABLE,
    BF_CHAIR,
    BF_FLUFF,
    BF_SHELL_WITH_INTERIOR,
    BF_WALL,
    BF_GATE,
    BF_DOOR,
    BF_BATTERY,
    BF_THRONE,
    BF_SKELETON_BED,
    BF_RAIN_COLLECTOR,
    BF_MINE_NATURAL,
    BF_STEERING,
    BF_ENGINE,
    BF_LIQUID_TANK
};

enum BuildingDesignation
{
    BD_NONE,
    BD_SHOP,
    BD_BARRACKS,
    BD_BAR,
    BD_HOSPITAL,
    BD_ARMOURY,
    BD_TREASURE,
    BD_PRISON,
    BD_HQ,
    BD_RESIDENTIAL,
    BD_SLAVE_STORAGE,
    BD_RESIDENTIAL_SMALL
};

enum BuildingClassType
{
    BCTYPE_FLUFF,
    BCTYPE_DOOR,
    BCTYPE_USABLE,
    BCTYPE_STORAGE,
    BCTYPE_PRODUCTION,
    BCTYPE_RESEARCH,
    BCTYPE_CRAFTING,
    BCTYPE_GATEWAY,
    BCTYPE_TURRET,
    BCTYPE_WALL,
    BCTYPE_ITEM_FURNACE,
    BCTYPE_LIGHT,
    BCTYPE_SHELL_WITH_INTERIOR,
    BCTYPE_FARM
};

// TODO move?
enum CursorType
{
    DEFAULT_CURSOR,
    MEDIC_CURSOR,
    LOOT_CURSOR,
    LIFT_CURSOR,
    PICKUP_ITEM_CURSOR,
    ATTACK_CURSOR,
    GUARD_CURSOR,
    TALK_CURSOR,
    SPECIAL_TALK_CURSOR,
    USE_CURSOR,
    TRADER_CURSOR,
    BUILD_CURSOR,
    OPEN_DOOR_CURSOR,
    DOOR_ESCAPE_CURSOR,
    LOCKED_CURSOR,
    PICK_LOCK_CURSOR,
    BUY_HOUSE_CURSOR,
    GREEN_CURSOR,
    MINE_CURSOR,
    REPAIR_CURSOR,
    LIGHT_CURSOR,
    STEAL_CURSOR,
    HAND_CURSOR,
    INVALID_MOVEMENT_CURSOR,
    LOOT_CURSOR_RED,
    KNOCKOUT_CURSOR
};

class DataPanelLine;
class WallBuilding;
class StorageBuilding;
class UseableStuff;
class BuildingItemGroup;
class Layout;
class GameData;
class ProductionBuilding;
class DoorStuff;
class GatewayBuilding;
class DoorLock;
class Town;
class BuildingInterior;
class TownBuildingsManager;
class SoundEmitter;
class Effect;
class UsageNode;

// WindGeneratorBuilding extends GeneratorBuilding
// GeneratorBuilding extends ProductionBuilding
// CraftingBuilding extends ProductionBuilding
// FurnaceBuilding extends ProductionBuilding
// RainCollectorBuilding extends ProductionBuilding
// TortureBuilding extends ProductionBuilding
// FarmBuilding extends ProductionBuilding
// ProductionBuilding extends StorageBuilding
// StorageBuilding extends UsableStuff
// ResearchBuilding extends UsableStuff
// TurretBuilding extends UsableStuff
// UsableStuff extends Building
// LightBuilding extends Building
// DoorStuff extends Building 
// WallBuilding extends Building
// GatewayBuilding extends Building
// Building extends RootObject, Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0>>
class Building : public RootObject, public Ogre::GeneralAllocatedObject
{
public:
    // RootObject offset = 0x0, length = 0xC0
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0xC0, length = 0x1
    bool isFoliage; // 0xC0 Member
    bool hasTerrainInside; // 0xC1 Member
    bool isCavernous; // 0xC2 Member
    bool enforceCeiling; // 0xC3 Member
    float getScale() const;// public RVA = 0xDC3B0
    class ConstructionState : public Ogre::GeneralAllocatedObject
    {
    public:
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
        ConstructionState(const Building::ConstructionState& c);// public RVA = 0x549AE0
        ConstructionState* _CONSTRUCTOR(const Building::ConstructionState& c);// public RVA = 0x549AE0
        ConstructionState();// public RVA = 0x549A40
        ConstructionState* _CONSTRUCTOR();// public RVA = 0x549A40
        ~ConstructionState();// public RVA = 0x55C2B0
        void _DESTRUCTOR();// public RVA = 0x55C2B0
        void addMaterials(GameData* mat);// public RVA = 0x549C20
        bool materialsEmpty() const;// public RVA = 0x549C70
        bool isOverThreshold() const;// public RVA = 0x546A60
        float getHealthBarProgress() const;// public RVA = 0x546A80
        float getConstructionMaterialProgress() const;// public RVA = 0x546AB0
        std::string getHealthBarActual() const;// public RVA = 0x551200
        bool isComplete; // 0x0 Member
        bool isPaused; // 0x1 Member
        bool isDismantled; // 0x2 Member
        float constructionProgress; // 0x4 Member
        float msgDismantleAmount; // 0x8 Member
        class BuildMaterial
        {
        public:
            GameData* mat; // 0x0 Member
            float buildMatsTotal; // 0x8 Member
            float amountOfMaterials; // 0xC Member
            float getMaterialsBarProgress() const;// public RVA = 0x2FD860
            float getNumRemaining() const;// public RVA = 0x2963D0
        };
        Building::ConstructionState::BuildMaterial* getMaterial(const GameData* d);// public RVA = 0x548AA0
        void setup(GameData* buildingdata);// public RVA = 0x55B2A0
        float getTotalMats() const;// public RVA = 0xF6AC0
        float getTotalMatsPresent() const;// public RVA = 0x548AE0
        void getNeededMats(lektor<Building::ConstructionState::BuildMaterial*>& out);// public RVA = 0x549CD0
        int needsMat(GameData* what);// public RVA = 0x548B20
        bool needMats();// public RVA = 0x2963E0
        static float getBuildingSpeedMultiplier(GameData* data);// public RVA = 0x553CF0
        static float getBuildingTimeInHours(GameData* data);// public RVA = 0x55B790
        lektor<Building::ConstructionState::BuildMaterial*> mats; // 0x10 Member
        float totalMats; // 0x28 Member
        float buildTimeMult; // 0x2C Member
        int buildersThisFrame; // 0x30 Member
        float pathThreshold; // 0x34 Member
        // no_addr class Building::ConstructionState & operator=(const class Building::ConstructionState & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    virtual Building::ConstructionState* getBuildState();// public RVA = 0xF6AD0 vtable offset = 0x228
    Building::ConstructionState* _NV_getBuildState();// public RVA = 0xF6AD0 vtable offset = 0x228
    Building::ConstructionState* getBuildState_ActualNonShared();// public RVA = 0x296420
    virtual void select();// public RVA = 0x54FD20 vtable offset = 0x0
    void _NV_select();// public RVA = 0x54FD20 vtable offset = 0x0
    BuildingDesignation designation; // 0xC4 Member
    BuildingDesignation getBuildingDesignation() const;// public RVA = 0x8C8910
    virtual void addConstructionProgress(float amount);// public RVA = 0x558E20 vtable offset = 0x230
    void _NV_addConstructionProgress(float amount);// public RVA = 0x558E20 vtable offset = 0x230
    virtual void setConstructionProgress(float amount);// public RVA = 0x559350 vtable offset = 0x238
    void _NV_setConstructionProgress(float amount);// public RVA = 0x559350 vtable offset = 0x238
    virtual void notifyConstructionComplete();// public RVA = 0x561BC0 vtable offset = 0x240
    void _NV_notifyConstructionComplete();// public RVA = 0x561BC0 vtable offset = 0x240
    virtual bool addDismantleProgress(float amount);// public RVA = 0x2A23B0 vtable offset = 0x248
    bool _NV_addDismantleProgress(float amount);// public RVA = 0x2A23B0 vtable offset = 0x248
    virtual void notifyConstructionDismantling();// public RVA = 0x548CA0 vtable offset = 0x250
    void _NV_notifyConstructionDismantling();// public RVA = 0x548CA0 vtable offset = 0x250
    void dropMats();// public RVA = 0x29D760
    virtual void upgrade(DataPanelLine* _a1);// public RVA = 0x2A4530 vtable offset = 0x258 missing arg names
    void _NV_upgrade(DataPanelLine* _a1);// public RVA = 0x2A4530 vtable offset = 0x258 missing arg names
    virtual void downgrade(DataPanelLine* _a1);// public RVA = 0x2A4900 vtable offset = 0x260 missing arg names
    void _NV_downgrade(DataPanelLine* _a1);// public RVA = 0x2A4900 vtable offset = 0x260 missing arg names
    virtual GameData* canUpgrade();// public RVA = 0x29BA70 vtable offset = 0x268
    GameData* _NV_canUpgrade();// public RVA = 0x29BA70 vtable offset = 0x268
    virtual GameData* canDowngrade();// public RVA = 0x2A4B40 vtable offset = 0x270
    GameData* _NV_canDowngrade();// public RVA = 0x2A4B40 vtable offset = 0x270
    virtual bool canDismantle() const;// public RVA = 0x29BED0 vtable offset = 0x278
    bool _NV_canDismantle() const;// public RVA = 0x29BED0 vtable offset = 0x278
    virtual void buyMeAsk(DataPanelLine* _a1);// public RVA = 0x7AC1B0 vtable offset = 0x280 missing arg names
    void _NV_buyMeAsk(DataPanelLine* _a1);// public RVA = 0x7AC1B0 vtable offset = 0x280 missing arg names
    virtual void buyMeCallback(int result);// public RVA = 0x7AC460 vtable offset = 0x288
    void _NV_buyMeCallback(int result);// public RVA = 0x7AC460 vtable offset = 0x288
    int calculateSaleValue();// public RVA = 0x7AC0A0
    void loadNodes();// public RVA = 0x54F8B0
    virtual bool isPublic() const;// public RVA = 0x547FD0 vtable offset = 0x290
    bool _NV_isPublic() const;// public RVA = 0x547FD0 vtable offset = 0x290
    virtual void togglePublic(DataPanelLine* _a1);// public RVA = 0x546770 vtable offset = 0x298 missing arg names
    void _NV_togglePublic(DataPanelLine* _a1);// public RVA = 0x546770 vtable offset = 0x298 missing arg names
    virtual void dismantleButton(DataPanelLine* _a1);// public RVA = 0x54D3B0 vtable offset = 0x2A0 missing arg names
    void _NV_dismantleButton(DataPanelLine* _a1);// public RVA = 0x54D3B0 vtable offset = 0x2A0 missing arg names
    virtual void pauseButton(DataPanelLine* _a1);// public RVA = 0x5467C0 vtable offset = 0x2A8 missing arg names
    void _NV_pauseButton(DataPanelLine* _a1);// public RVA = 0x5467C0 vtable offset = 0x2A8 missing arg names
    virtual void confirmDismantle(int r);// public RVA = 0x54F720 vtable offset = 0x2B0
    void _NV_confirmDismantle(int r);// public RVA = 0x54F720 vtable offset = 0x2B0
    bool publicDaytime; // 0xC8 Member
    virtual bool isAShop();// public RVA = 0x996F30 vtable offset = 0x2B8
    bool _NV_isAShop();// public RVA = 0x996F30 vtable offset = 0x2B8
    virtual bool isForSale();// public RVA = 0x29C050 vtable offset = 0x2C0
    bool _NV_isForSale();// public RVA = 0x29C050 vtable offset = 0x2C0
    virtual WallBuilding* isAWall();// public RVA = 0xF6AE0 vtable offset = 0x2C8
    WallBuilding* _NV_isAWall();// public RVA = 0xF6AE0 vtable offset = 0x2C8
    virtual bool isAWallRamp();// public RVA = 0x2A5710 vtable offset = 0x2D0
    bool _NV_isAWallRamp();// public RVA = 0x2A5710 vtable offset = 0x2D0
    bool hasInterior();// public RVA = 0x2911A0
    bool affectsNavmesh() const;// public RVA = 0x3B2A10
    hand residentSquad; // 0xD0 Member
    GameData* residentSquadTemplate; // 0xF0 Member
    void setResidentSquad(Platoon* who);// public RVA = 0x552A90
    Character* getResidentSquadLeader() const;// public RVA = 0x547420
    void setDesignation(BuildingDesignation d);// public RVA = 0x569C30
    Ogre::Vector3 getWallEndPosition();// public RVA = 0x4D0890
    virtual void setupMiningResourceLevel();// public RVA = 0x2AAEE0 vtable offset = 0x2D8
    void _NV_setupMiningResourceLevel();// public RVA = 0x2AAEE0 vtable offset = 0x2D8
    virtual float getMiningResourceLevel() const;// public RVA = 0x2AAEF0 vtable offset = 0x2E0
    float _NV_getMiningResourceLevel() const;// public RVA = 0x2AAEF0 vtable offset = 0x2E0
    void addAnInternalBuilding(Building* b);// public RVA = 0x588E30
    void removeAnInternalBuilding(const hand& h);// public RVA = 0x7CC2E0
    int getNumInternalBuildings() const;// public RVA = 0x339E10
    void addAnInternalItem(BuildingItemGroup* item);// public RVA = 0x54FB90
    void removeAnInternalItem(BuildingItemGroup* item);// public RVA = 0x576020
    // no_addr int getNumInternalItems();// public
    int getMountedBuildings(lektor<Building*>* out);// public RVA = 0x54B250
    void moveMountedBuildings();// public RVA = 0x54C090
    virtual void setHandle(const hand& h);// public RVA = 0x556980 vtable offset = 0x0
    void _NV_setHandle(const hand& h);// public RVA = 0x556980 vtable offset = 0x0
    void reCheckInsideOutsideFortificationStatus();// public RVA = 0x555850
    virtual void setInsideTownWalls(int code);// public RVA = 0x54DCD0 vtable offset = 0x0
    void _NV_setInsideTownWalls(int code);// public RVA = 0x54DCD0 vtable offset = 0x0
    virtual void postCreationPathfinderSetupStuff();// public RVA = 0x555AB0 vtable offset = 0x2E8
    void _NV_postCreationPathfinderSetupStuff();// public RVA = 0x555AB0 vtable offset = 0x2E8
    virtual BuildingFunction getSpecialFunction() const;// public RVA = 0xF6AF0 vtable offset = 0x2F0
    BuildingFunction _NV_getSpecialFunction() const;// public RVA = 0xF6AF0 vtable offset = 0x2F0
    virtual StorageBuilding* getFunctionStuff();// public RVA = 0x2AD660 vtable offset = 0x2F8
    StorageBuilding* _NV_getFunctionStuff();// public RVA = 0x2AD660 vtable offset = 0x2F8
    virtual UseableStuff* getUseableStuff();// public RVA = 0x2AD670 vtable offset = 0x300
    UseableStuff* _NV_getUseableStuff();// public RVA = 0x2AD670 vtable offset = 0x300
    virtual bool isBroken() const;// public RVA = 0x57B470 vtable offset = 0x308
    bool _NV_isBroken() const;// public RVA = 0x57B470 vtable offset = 0x308
    virtual void setBroken(bool _a1);// public RVA = 0x57B480 vtable offset = 0x310 missing arg names
    void _NV_setBroken(bool _a1);// public RVA = 0x57B480 vtable offset = 0x310 missing arg names
    virtual void switchPowerOn(bool on);// public RVA = 0x2AD680 vtable offset = 0x318
    void _NV_switchPowerOn(bool on);// public RVA = 0x2AD680 vtable offset = 0x318
    virtual bool isPowerOn() const;// public RVA = 0x2AD690 vtable offset = 0x320
    bool _NV_isPowerOn() const;// public RVA = 0x2AD690 vtable offset = 0x320
    virtual bool isDamaged();// public RVA = 0xF6B30 vtable offset = 0x328
    bool _NV_isDamaged();// public RVA = 0xF6B30 vtable offset = 0x328
    virtual bool isDestroyed() const;// public RVA = 0xF6B50 vtable offset = 0x330
    bool _NV_isDestroyed() const;// public RVA = 0xF6B50 vtable offset = 0x330
    virtual bool isSign() const;// public RVA = 0xF80B0 vtable offset = 0x338
    bool _NV_isSign() const;// public RVA = 0xF80B0 vtable offset = 0x338
    virtual void setDestroyed(bool d);// public RVA = 0x556B00 vtable offset = 0x340
    void _NV_setDestroyed(bool d);// public RVA = 0x556B00 vtable offset = 0x340
    virtual bool canBeDestroyed() const;// public RVA = 0x55ADA0 vtable offset = 0x348
    bool _NV_canBeDestroyed() const;// public RVA = 0x55ADA0 vtable offset = 0x348
    void setNestTag();// public RVA = 0x9254D0
    virtual float getReachRange() const;// public RVA = 0x57B490 vtable offset = 0x350
    float _NV_getReachRange() const;// public RVA = 0x57B490 vtable offset = 0x350
    bool isAnInteriorObject; // 0xF8 Member
    bool hasShopCountersSelling(ItemFunction type);// public RVA = 0x54A650
    virtual BuildingClassType getBuildingClass() const;// public RVA = 0xF6B60 vtable offset = 0x358
    BuildingClassType _NV_getBuildingClass() const;// public RVA = 0xF6B60 vtable offset = 0x358
    InstanceID instanceID; // 0x100 Member
    virtual bool needsSaving(const std::string& mod) const;// public RVA = 0x54F9A0 vtable offset = 0x0
    bool _NV_needsSaving(const std::string& mod) const;// public RVA = 0x54F9A0 vtable offset = 0x0
    void notifyChange();// public RVA = 0x7809A0
    virtual InstanceID* getInstanceID();// public RVA = 0xF6B70 vtable offset = 0x0
    InstanceID* _NV_getInstanceID();// public RVA = 0xF6B70 vtable offset = 0x0
    virtual const std::string& getLayoutInstanceID();// public RVA = 0xF6B80 vtable offset = 0x0
    const std::string& _NV_getLayoutInstanceID();// public RVA = 0xF6B80 vtable offset = 0x0
    std::string layoutInstanceID; // 0x130 Member
    BuildingFunction specialFunction; // 0x158 Member
    Building::ConstructionState _buildState; // 0x160 Member
    BuildingClassType classType; // 0x198 Member
    // no_addr void Building(const class Building & _a1);// public missing arg names
    Building(GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors);// protected RVA = 0x55C310
    Building* _CONSTRUCTOR(GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& orientation, Faction* _participant, const hand& town, const hand& _handle, Layout* __isfurnitureOf, Building* _indoors);// protected RVA = 0x55C310
    void setToDefaultFactionDivision();// protected RVA = 0x55B9B0
    bool updateNavmesh; // 0x19C Member
    bool visible; // 0x19D Member
    bool interiorVisibility; // 0x19E Member
    bool justBeenUpgradedFlag; // 0x19F Member
    bool imADoor; // 0x1A0 Member
    bool destroyed; // 0x1A1 Member
    float productionMult; // 0x1A4 Member
    float productionMult_baseData; // 0x1A8 Member
    bool hasMovingParts; // 0x1AC Member
    virtual float getOutputBasedRotationSpeedMult();// protected RVA = 0x2AD6A0 vtable offset = 0x360
    float _NV_getOutputBasedRotationSpeedMult();// protected RVA = 0x2AD6A0 vtable offset = 0x360
    virtual float calculateEfficiencyMult() const;// protected RVA = 0x2AD6B0 vtable offset = 0x368
    float _NV_calculateEfficiencyMult() const;// protected RVA = 0x2AD6B0 vtable offset = 0x368
    virtual float getSoundIntensity();// protected RVA = 0xF6B90 vtable offset = 0x370
    float _NV_getSoundIntensity();// protected RVA = 0xF6B90 vtable offset = 0x370
    virtual void loadUnloadCheck();// protected RVA = 0x546AF0 vtable offset = 0x0
    void _NV_loadUnloadCheck();// protected RVA = 0x546AF0 vtable offset = 0x0
    int saveVersion; // 0x1B0 Member
    virtual ~Building();// protected RVA = 0x5625A0 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x5625A0 vtable offset = 0x0
    virtual void _saveBuildingState(GameData* state, const std::string& doorID);// protected RVA = 0x554070 vtable offset = 0x378
    void _NV__saveBuildingState(GameData* state, const std::string& doorID);// protected RVA = 0x554070 vtable offset = 0x378
    virtual void _loadBuildingState(GameData* state, const std::string& doorID);// protected RVA = 0x554ED0 vtable offset = 0x380
    void _NV__loadBuildingState(GameData* state, const std::string& doorID);// protected RVA = 0x554ED0 vtable offset = 0x380
    virtual void getGUIName(DatapanelGUI* datapanel, int category);// protected RVA = 0x2FD9F0 vtable offset = 0x388
    void _NV_getGUIName(DatapanelGUI* datapanel, int category);// protected RVA = 0x2FD9F0 vtable offset = 0x388
    virtual void getGUIState(DatapanelGUI* datapanel, int category);// protected RVA = 0x2FDB90 vtable offset = 0x390
    void _NV_getGUIState(DatapanelGUI* datapanel, int category);// protected RVA = 0x2FDB90 vtable offset = 0x390
    virtual void getGUICondition(DatapanelGUI* datapanel, int category);// protected RVA = 0x301ED0 vtable offset = 0x398
    void _NV_getGUICondition(DatapanelGUI* datapanel, int category);// protected RVA = 0x301ED0 vtable offset = 0x398
    virtual void getGUIUpgrade(DatapanelGUI* datapanel, int category);// protected RVA = 0x302B80 vtable offset = 0x3A0
    void _NV_getGUIUpgrade(DatapanelGUI* datapanel, int category);// protected RVA = 0x302B80 vtable offset = 0x3A0
    virtual void getGUIDestroyButton(DatapanelGUI* datapanel, int category);// protected RVA = 0x2FE560 vtable offset = 0x3A8
    void _NV_getGUIDestroyButton(DatapanelGUI* datapanel, int category);// protected RVA = 0x2FE560 vtable offset = 0x3A8
    static bool refreshGUIChangesFlag; // RVA = 0x212AD50 Static Member
    void findAllFurnitureWithFunction(lektor<Building*>& out, BuildingFunction func);// public RVA = 0x8C8D70
    virtual ProductionBuilding* getProductionBuilding();// public RVA = 0x2AAF00 vtable offset = 0x3B0
    ProductionBuilding* _NV_getProductionBuilding();// public RVA = 0x2AAF00 vtable offset = 0x3B0
    virtual float getProductionMultForGUI();// public RVA = 0x2976C0 vtable offset = 0x3B8
    float _NV_getProductionMultForGUI();// public RVA = 0x2976C0 vtable offset = 0x3B8
    virtual float getProductionMult();// public RVA = 0x297680 vtable offset = 0x3C0
    float _NV_getProductionMult();// public RVA = 0x297680 vtable offset = 0x3C0
    bool isThePlayer() const;// public RVA = 0x546650
    lektor<Building*> doors; // 0x1B8 Member
    virtual DoorStuff* doorStuff();// public RVA = 0xF6BA0 vtable offset = 0x3C8
    DoorStuff* _NV_doorStuff();// public RVA = 0xF6BA0 vtable offset = 0x3C8
    virtual Building* doorParentBuilding() const;// public RVA = 0xF6BB0 vtable offset = 0x3D0
    Building* _NV_doorParentBuilding() const;// public RVA = 0xF6BB0 vtable offset = 0x3D0
    bool isDoor() const;// public RVA = 0x296430
    virtual GatewayBuilding* isGate();// public RVA = 0xF6BC0 vtable offset = 0x3D8
    GatewayBuilding* _NV_isGate();// public RVA = 0xF6BC0 vtable offset = 0x3D8
    virtual DoorStuff* getDoor();// public RVA = 0xF7040 vtable offset = 0x3E0
    DoorStuff* _NV_getDoor();// public RVA = 0xF7040 vtable offset = 0x3E0
    Layout* getParentLayout();// public RVA = 0x7809B0
    bool isFurniture() const;// public RVA = 0x296440
    bool isFurnitureOrDoor() const;// public RVA = 0x296460
    bool getIsOutsideFurniture() const;// public RVA = 0x7809C0
    void setIsOutsideFurniture(bool value);// public RVA = 0x4EB9D0
    virtual TownBase* getCurrentTownLocation();// public RVA = 0xF7070 vtable offset = 0x0
    TownBase* _NV_getCurrentTownLocation();// public RVA = 0xF7070 vtable offset = 0x0
    Building* furnitureParentBuilding() const;// public RVA = 0xD5F60
    bool hasAnOpenDoor() const;// public RVA = 0x549220
    bool allowAnimals() const;// public RVA = 0x546D80
    virtual void update();// public RVA = 0x561F20 vtable offset = 0x0
    void _NV_update();// public RVA = 0x561F20 vtable offset = 0x0
    virtual void threadedUpdate();// public RVA = 0x54A990 vtable offset = 0x0
    void _NV_threadedUpdate();// public RVA = 0x54A990 vtable offset = 0x0
    virtual bool needsUpdate();// public RVA = 0x9F9720 vtable offset = 0x3E8
    bool _NV_needsUpdate();// public RVA = 0x9F9720 vtable offset = 0x3E8
    virtual bool isPhysical() const;// public RVA = 0xF6BD0 vtable offset = 0x0
    bool _NV_isPhysical() const;// public RVA = 0xF6BD0 vtable offset = 0x0
    virtual void checkLoadedProperly();// public RVA = 0x5463F0 vtable offset = 0x3F0
    void _NV_checkLoadedProperly();// public RVA = 0x5463F0 vtable offset = 0x3F0
    virtual GameSaveState serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0x551BA0 vtable offset = 0x0
    GameSaveState _NV_serialise(GameDataContainer* container, GameData* refList, PosRotPair* offsetPosToSubtract);// public RVA = 0x551BA0 vtable offset = 0x0
    virtual void loadFromSerialise(GameSaveState* savestate);// public RVA = 0x5523F0 vtable offset = 0x0
    void _NV_loadFromSerialise(GameSaveState* savestate);// public RVA = 0x5523F0 vtable offset = 0x0
    virtual void loadFromSerialise_TheDoors(GameSaveState* savestate);// public RVA = 0x54BF30 vtable offset = 0x3F8
    void _NV_loadFromSerialise_TheDoors(GameSaveState* savestate);// public RVA = 0x54BF30 vtable offset = 0x3F8
    virtual void getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x301390 vtable offset = 0x0
    void _NV_getGUIData(DatapanelGUI* datapanel, int category);// public RVA = 0x301390 vtable offset = 0x0
    virtual void setVisible(bool on);// public RVA = 0x5487F0 vtable offset = 0x0
    void _NV_setVisible(bool on);// public RVA = 0x5487F0 vtable offset = 0x0
    virtual bool getVisible() const;// public RVA = 0x5469C0 vtable offset = 0x0
    bool _NV_getVisible() const;// public RVA = 0x5469C0 vtable offset = 0x0
    virtual DoorLock* getDoorLock();// public RVA = 0x297810 vtable offset = 0x400
    DoorLock* _NV_getDoorLock();// public RVA = 0x297810 vtable offset = 0x400
    virtual bool hasDoorLock() const;// public RVA = 0x57B4A0 vtable offset = 0x408
    bool _NV_hasDoorLock() const;// public RVA = 0x57B4A0 vtable offset = 0x408
    virtual CursorType getMouseCursor();// public RVA = 0x57B4B0 vtable offset = 0x410
    CursorType _NV_getMouseCursor();// public RVA = 0x57B4B0 vtable offset = 0x410
    virtual TaskType getDefaultTask();// public RVA = 0x57B4C0 vtable offset = 0x418
    TaskType _NV_getDefaultTask();// public RVA = 0x57B4C0 vtable offset = 0x418
    virtual Inventory* getInventory() const;// public RVA = 0x2AD6C0 vtable offset = 0x0
    Inventory* _NV_getInventory() const;// public RVA = 0x2AD6C0 vtable offset = 0x0
    virtual Ogre::Aabb getAABB(float scale) const;// public RVA = 0x546C10 vtable offset = 0x420
    Ogre::Aabb _NV_getAABB(float scale) const;// public RVA = 0x546C10 vtable offset = 0x420
    virtual const Ogre::Aabb& getAABB() const;// public RVA = 0x546C00 vtable offset = 0x0
    const Ogre::Aabb& _NV_getAABB() const;// public RVA = 0x546C00 vtable offset = 0x0
    void setAABB(const Ogre::Aabb& aabb);// public RVA = 0x546C70
    void _changeTown(Town* t);// public RVA = 0x9258B0
    hand _town; // 0x1D0 Member
    hand getTownHandle() const;// public RVA = 0xD9E70
    TownBase* getTown() const;// public RVA = 0xF6BE0
    Town* getRealTown() const;// public RVA = 0x296490
    virtual bool createPhysical();// public RVA = 0x560260 vtable offset = 0x0
    bool _NV_createPhysical();// public RVA = 0x560260 vtable offset = 0x0
    virtual void destroyPhysical();// public RVA = 0x562220 vtable offset = 0x0
    void _NV_destroyPhysical();// public RVA = 0x562220 vtable offset = 0x0
    void destroyDoors();// public RVA = 0x5480B0
    void createTriggerHull();// public RVA = 0x5530F0
    void destroyAudioObject();// public RVA = 0x5491A0
    unsigned __int64 getAudioObject();// public RVA = 0x55BF80
    GroundType getGroundType(bool inside) const;// public RVA = 0x663EC0
    virtual bool isCeilingMounted();// public RVA = 0xF8170 vtable offset = 0x428
    bool _NV_isCeilingMounted();// public RVA = 0xF8170 vtable offset = 0x428
    virtual const hand& isIndoors() const;// public RVA = 0x546DB0 vtable offset = 0x0
    const hand& _NV_isIndoors() const;// public RVA = 0x546DB0 vtable offset = 0x0
    virtual const hand& isIndoors_notDestroyed() const;// public RVA = 0x546E60 vtable offset = 0x430
    const hand& _NV_isIndoors_notDestroyed() const;// public RVA = 0x546E60 vtable offset = 0x430
    virtual const hand& getMountedBuilding() const;// public RVA = 0xF6C80 vtable offset = 0x438
    const hand& _NV_getMountedBuilding() const;// public RVA = 0xF6C80 vtable offset = 0x438
    int getLights(lektor<PhysicsCollection::LightEnt const*>& list, const Ogre::Vector3& pos, float radiusSquared) const;// public RVA = 0x5498F0
    void setFloorVisibility(int floor, bool vis);// public RVA = 0x547B60
    int getNumFloors() const;// public RVA = 0x547CA0
    void buildingComplete_RestoreMaterial();// public RVA = 0x5582F0
    void loadInteriorPhysical(bool on);// public RVA = 0x57B6C0
    void loadInteriorGraphics(bool on);// public RVA = 0x7809D0
    virtual void setFaction(Faction* p, ActivePlatoon* a);// public RVA = 0x5571D0 vtable offset = 0x0
    void _NV_setFaction(Faction* p, ActivePlatoon* a);// public RVA = 0x5571D0 vtable offset = 0x0
    Ogre::Vector3 calculateLeftPost() const;// public RVA = 0x426F70
    void setupLevelData(Faction* f, GameData* squad, const std::string& interior, const std::string& exterior);// public RVA = 0x5519C0
    virtual float getLinkLength() const;// public RVA = 0xF8230 vtable offset = 0x440
    float _NV_getLinkLength() const;// public RVA = 0xF8230 vtable offset = 0x440
    BuildingInterior* myInterior; // 0x1F0 Member
    Ogre::SceneNode* getRootNode() const;// public RVA = 0xDEDE0
    virtual ZoneMap* getZoneMapLocation();// public RVA = 0x547240 vtable offset = 0x0
    ZoneMap* _NV_getZoneMapLocation();// public RVA = 0x547240 vtable offset = 0x0
    virtual void clearTownBuildingsManagerPtr();// public RVA = 0x54A810 vtable offset = 0x448
    void _NV_clearTownBuildingsManagerPtr();// public RVA = 0x54A810 vtable offset = 0x448
    TownBuildingsManager* buildingsManager; // 0x1F8 Member
    Ogre::SceneNode* rootNode; // 0x200 Member
    virtual void setup();// protected RVA = 0x5513A0 vtable offset = 0x450
    void _NV_setup();// protected RVA = 0x5513A0 vtable offset = 0x450
    virtual void setupFromData();// protected RVA = 0x29DC10 vtable offset = 0x458
    void _NV_setupFromData();// protected RVA = 0x29DC10 vtable offset = 0x458
    void setupAudio();// protected RVA = 0x55BAC0
    unsigned __int64 audioObject; // 0x208 Member
    SoundEmitter* soundEmitter; // 0x210 Member
    bool hasAudio; // 0x218 Member
    GroundType interiorGround; // 0x21C Member
    GroundType exteriorGround; // 0x220 Member
    PhysicsCollection* physical; // 0x228 Member
    int entitiesToLoad; // 0x230 Member
    bool entitiesLoaded; // 0x234 Member
    Layout* isFurnitureOf; // 0x238 Member
    bool isOutsideFurniture; // 0x240 Member
    bool isNestItem; // 0x241 Member
    GameData* baseMaterial; // 0x248 Member
    lektor<std::pair<PhysicalEntity*, Effect*> > effects; // 0x250 Member
    bool effectsVisible; // 0x268 Member
    bool effectsActive; // 0x269 Member
    bool lightsVisible; // 0x26A Member
    virtual void switchLights(bool on);// public RVA = 0x29A560 vtable offset = 0x460
    void _NV_switchLights(bool on);// public RVA = 0x29A560 vtable offset = 0x460
    virtual void switchEffects(bool on);// public RVA = 0x296F30 vtable offset = 0x468
    void _NV_switchEffects(bool on);// public RVA = 0x296F30 vtable offset = 0x468
    bool hasAnyGoodPositionMarkersLeft();// public RVA = 0x54BE40
    void notifyBadPositionMarker(const Ogre::Vector3& what);// public RVA = 0x54CC90
    virtual Ogre::Vector3 getPositionMarker(const Ogre::Vector3& currentPosition);// public RVA = 0x54B0D0 vtable offset = 0x470
    Ogre::Vector3 _NV_getPositionMarker(const Ogre::Vector3& currentPosition);// public RVA = 0x54B0D0 vtable offset = 0x470
    virtual Ogre::Vector3 getDirectionMarker(const Ogre::Vector3& currentPosition);// public RVA = 0x548E90 vtable offset = 0x478
    Ogre::Vector3 _NV_getDirectionMarker(const Ogre::Vector3& currentPosition);// public RVA = 0x548E90 vtable offset = 0x478
    virtual Ogre::Quaternion getDirectionMarkerQuat(const Ogre::Vector3& currentPosition);// public RVA = 0x548FA0 vtable offset = 0x480
    Ogre::Quaternion _NV_getDirectionMarkerQuat(const Ogre::Vector3& currentPosition);// public RVA = 0x548FA0 vtable offset = 0x480
    virtual bool isCreated() const;// public RVA = 0x5490B0 vtable offset = 0x488
    bool _NV_isCreated() const;// public RVA = 0x5490B0 vtable offset = 0x488
    void updateUsageNodes();// public RVA = 0x54F040
    void forceValidUsageNodesValidation();// public RVA = 0x54F350
    void addUsageNode(const std::string& nodeId);// public RVA = 0x54F650
    void removeUsageNode(const std::string& nodeId);// public RVA = 0x54D250
    void clearUsageNodes();// public RVA = 0x54BD50
    // no_addr const class lektor<UsageNode *> & getUsageNodes();// public
    virtual void notifyEffect(EffectType::Enum type, WeatherAffecting what, float strength);// public RVA = 0x546760 vtable offset = 0x0
    void _NV_notifyEffect(EffectType::Enum type, WeatherAffecting what, float strength);// public RVA = 0x546760 vtable offset = 0x0
    static DatapanelGUI* infoWindow; // RVA = 0x212CB70 Static Member
    static Ogre::SharedPtr<Ogre::Material> getBuildingPartMaterial(GameData* data, bool coloured, bool instanced, bool inside, const Ogre::Vector3& pos);// protected RVA = 0x57A1A0
    static void setBuildingPartMaterial(Ogre::Entity* entity, GameData* data, bool instanced, bool inside, const Ogre::Vector3& pos);// protected RVA = 0x57A300
    void restoreMaterialToPhysical(PhysicsCollection* physical, bool inside);// protected RVA = 0x558160
    Ogre::Vector3 positionMarker; // 0x26C Member
    void updatePhysicalWithProgress();// protected RVA = 0x558990
    float heightAboveGround; // 0x278 Member
    void updateWorldAABB(Ogre::MovableObject* entity);// protected RVA = 0x546C90
    void recalculateWorldAABB();// protected RVA = 0x548D00
    Ogre::Aabb AABB; // 0x27C Member
    bool isRedDebugTextureMode; // 0x294 Member
    std::string materialName; // 0x298 Member
    GameData* selectPartMaterial(GameData* partData);// protected RVA = 0x54C5B0
    Ogre::SharedPtr<Ogre::Material> getPartMaterial(GameData* matData, Ogre::Entity* ent, bool instanced, bool inside);// protected RVA = 0x557460
    static void selectParts(const Ogre::vector<GameDataReference>::type* partList, lektor<GameData*>& parts);// protected RVA = 0x559400
    void loadParts(GameData* from, PhysicalEntity* parent, PhysicsCollection* _physical, unsigned char renderQueueGroup, int flags);// protected RVA = 0x560070
    PhysicalEntity* loadPartEntity(PhysicsCollection* to, GameData* part, Ogre::SceneNode* parentNode, unsigned char renderQueueGroup, int flags, GameData* fromParent);// protected RVA = 0x55EF60
    Ogre::MovableObject* loadEntity(GameData* partData, Ogre::SceneNode* parentNode, unsigned char renderQueueGroup);// protected RVA = 0x55D9D0
    void loadEntityCallback(Ogre::SharedPtr<Ogre::Resource> _a1, void* entityData);// protected RVA = 0x5583C0
    void loadInstances(GameData* part, PhysicalEntity* parent, Ogre::SceneNode* node);// protected RVA = 0x553640
    unsigned int getSeed() const;// protected RVA = 0x56C8B0
    PhysicalEntity* findPhysicalEntity(Ogre::MovableObject* obj) const;// protected RVA = 0x5499F0
    static PhysicalEntity* findPhysicalEntityInCollection(Ogre::MovableObject* obj, PhysicsCollection* list);// protected RVA = 0x547EB0
    static bool buildingContainsEntity(Ogre::MovableObject* obj, PhysicsCollection* list);// protected RVA = 0x547F60
    static std::string getEntityMaterialName(Ogre::MovableObject* obj);// protected RVA = 0x54AC50
    virtual void onBuildingLoaded();// protected RVA = 0x558BA0 vtable offset = 0x490
    void _NV_onBuildingLoaded();// protected RVA = 0x558BA0 vtable offset = 0x490
    virtual void setPartVisible(PhysicalEntity* part, bool on);// protected RVA = 0x55DFC0 vtable offset = 0x498
    void _NV_setPartVisible(PhysicalEntity* part, bool on);// protected RVA = 0x55DFC0 vtable offset = 0x498
    std::set<std::string, std::less<std::string >, Ogre::STLAllocator<std::string, Ogre::GeneralAllocPolicy > > usageNodesIds; // 0x2C0 Member
    lektor<UsageNode*> usageNodes; // 0x2E8 Member
    ogre_unordered_map<int, float>::type badNodes; // 0x300 Member
    void updateBadNodes();// protected RVA = 0x54B010
    SimplePhysXEntity* triggerVolume; // 0x340 Member
    lektor<std::pair<char, float> > activeEffects; // 0x348 Member
    // no_addr class Building & operator=(const class Building & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};