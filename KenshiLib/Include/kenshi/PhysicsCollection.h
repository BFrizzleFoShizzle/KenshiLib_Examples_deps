#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <kenshi/Enums.h>
#include <kenshi/util/lektor.h>

class GameData;
class hand;
class SimplePhysXEntity;

enum BuildingRotation
{
    ROTATION_NONE = 0x80020008,
    ROTATION_CONSTANT = 0x1,
    ROTATION_OUTPUT_BASED = 0x2,
    ROTATION_WIND_SPEED = 0x3,
    ROTATION_FACE_WIND_DIRECTION = 0x4,
    ROTATION_TARGET = 0x5,
    ROTATION_MATCH_PARENT = 0x6
};

class PhysicalEntity : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void PhysicalEntity(const class PhysicalEntity & _a1);// public missing arg names
    PhysicalEntity(Ogre::MovableObject* entity, char floor, GameData* _mat, GameData* part, bool instanced);// public RVA = 0x4CD570
    void _CONSTRUCTOR(Ogre::MovableObject* entity, char floor, GameData* _mat, GameData* part, bool instanced);// public RVA = 0x4CD570
    virtual ~PhysicalEntity();// public RVA = 0x4CB300 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x4CB300 vtable offset = 0x0
    Ogre::MovableObject* ent; // 0x8 Member
    PhysicalEntity* parent; // 0x10 Member
    char floorNumber; // 0x18 Member
    GameData* mat; // 0x20 Member
    GameData* partData; // 0x28 Member
    bool instanced; // 0x30 Member
    bool isShell; // 0x31 Member
    bool isEmissive; // 0x32 Member
    // no_addr class PhysicalEntity & operator=(const class PhysicalEntity & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class WeatherInstance;
class AreaBiomeGroup;
class Season;
class EffectGroup;
// TODO move
class WeatherRegion : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    class Listener
    {
    public:
        // VTable         : (none)
        virtual void weatherUpdated(WeatherInstance* _a1, bool _a2) = 0;// public vtable offset = 0x0 missing arg names
        // no_addr void Listener(const class WeatherRegion::Listener & _a1);// public missing arg names
        Listener();// public RVA = 0xFCCB0
        void _CONSTRUCTOR();// public RVA = 0xFCCB0
        // no_addr class WeatherRegion::Listener & operator=(const class WeatherRegion::Listener & _a1);// public missing arg names
    };
    // Typedef        : WeatherListenerList
    // no_addr void WeatherRegion(const class WeatherRegion & _a1);// public missing arg names
    WeatherRegion(AreaBiomeGroup* biomeGroup);// public RVA = 0x9DE120
    void _CONSTRUCTOR(AreaBiomeGroup* biomeGroup);// public RVA = 0x9DE120
    ~WeatherRegion();// public RVA = 0x9DB070
    void _DESTRUCTOR();// public RVA = 0x9DB070
    void reset();// public RVA = 0x9DCED0
    WeatherInstance* getWeatherInstance() const;// public RVA = 0x9DA920
    void setCurrentSeason(int seasonIndex, int seasonEnd);// public RVA = 0x9DAC10
    // no_addr class Season * getCurrentSeason();// public
    float getNewWeatherStrength() const;// public RVA = 0x9DAC30
    void update();// public RVA = 0x9DAD30
    void updateBT();// public RVA = 0x9DC6A0
    void addListener(WeatherRegion::Listener* listener);// public RVA = 0x9DB310
    void removeListener(WeatherRegion::Listener* listener);// public RVA = 0x9DAEB0
    void addGlobalEffect(EffectType::Enum type);// public RVA = 0x9DB6F0
    void getNewSeason();// private RVA = 0x9DC640
    void weatherChanged(bool newWeather);// private RVA = 0x9DACB0
    void updateWeatherEffects();// private RVA = 0x9DB340
    void save(GameData* data, const std::string& key);// private RVA = 0x9DC830
    void load(GameData* data, const std::string& key);// private RVA = 0x9DCA50
    AreaBiomeGroup* biomeGroup; // 0x0 Member
    Ogre::vector<Season*>::type seasons; // 0x8 Member
    float weatherStrengthMultiplierMin; // 0x28 Member
    float weatherStrengthMultiplierMax; // 0x2C Member
    WeatherInstance* weatherInstance; // 0x30 Member
    Season* currentSeason; // 0x38 Member
    int currentSeasonIndex; // 0x40 Member
    int currentSeasonEndDay; // 0x44 Member
    Ogre::vector<WeatherRegion::Listener*>::type listeners; // 0x48 Member
    bool biomeGroupLoaded; // 0x68 Member
    bool requestUpdateEffects; // 0x69 Member
    Ogre::vector<EffectGroup*>::type effects; // 0x70 Member
    std::vector<std::pair<EffectType::Enum, float>, Ogre::STLAllocator<std::pair<EffectType::Enum, float>, Ogre::GeneralAllocPolicy > > activeGlobalEffects; // 0x90 Member
    bool activeCameraBiome; // 0xB0 Member
    bool weatherUpdated; // 0xB1 Member
    bool instanceUpdated; // 0xB2 Member
    // no_addr class WeatherRegion & operator=(const class WeatherRegion & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

class PhysicsCollection : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    ~PhysicsCollection();// public RVA = 0x4CBB00
    void _DESTRUCTOR();// public RVA = 0x4CBB00
    class StaticEnt : public PhysicalEntity
    {
    public:
        // PhysicalEntity offset = 0x0, length = 0x38
        // no_addr void StaticEnt(const class PhysicsCollection::StaticEnt & _a1);// public missing arg names
        StaticEnt(Ogre::MovableObject* entity, int floor, GameData* _mat, GameData* part);// public RVA = 0x546690
        void _CONSTRUCTOR(Ogre::MovableObject* entity, int floor, GameData* _mat, GameData* part);// public RVA = 0x546690
        virtual void update(float spd);// public RVA = 0x569D50 vtable offset = 0x8
        void _NV_update(float spd);// public RVA = 0x569D50 vtable offset = 0x8
        virtual float updateAim(float rotSpeed, const Ogre::Vector3& target);// public RVA = 0x569D60 vtable offset = 0x10
        float _NV_updateAim(float rotSpeed, const Ogre::Vector3& target);// public RVA = 0x569D60 vtable offset = 0x10
        virtual bool isRotatingEnt() const;// public RVA = 0x569D70 vtable offset = 0x18
        bool _NV_isRotatingEnt() const;// public RVA = 0x569D70 vtable offset = 0x18
        virtual ~StaticEnt();// public RVA = 0x569D80 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0x569D80 vtable offset = 0x0
        // no_addr class PhysicsCollection::StaticEnt & operator=(const class PhysicsCollection::StaticEnt & _a1);// public missing arg names
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
    class RotatingEnt : public PhysicsCollection::StaticEnt, public WeatherRegion::Listener
    {
    public:
        // PhysicsCollection::StaticEnt offset = 0x0, length = 0x38
        // WeatherRegion::Listener offset = 0x38, length = 0x8
        // no_addr void RotatingEnt(const class PhysicsCollection::RotatingEnt & _a1);// public missing arg names
        RotatingEnt(Ogre::MovableObject* entity, int floor, GameData* _mat, GameData* part);// public RVA = 0x555AD0
        void _CONSTRUCTOR(Ogre::MovableObject* entity, int floor, GameData* _mat, GameData* part);// public RVA = 0x555AD0
        virtual ~RotatingEnt();// public RVA = 0x547470 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0x547470 vtable offset = 0x0
        virtual void update(float productionSpeed);// public RVA = 0x547520 vtable offset = 0x0
        void _NV_update(float productionSpeed);// public RVA = 0x547520 vtable offset = 0x0
        virtual float updateAim(float speed, const Ogre::Vector3& target);// public RVA = 0x549310 vtable offset = 0x0
        float _NV_updateAim(float speed, const Ogre::Vector3& target);// public RVA = 0x549310 vtable offset = 0x0
        virtual bool isRotatingEnt() const;// public RVA = 0x569DD0 vtable offset = 0x0
        bool _NV_isRotatingEnt() const;// public RVA = 0x569DD0 vtable offset = 0x0
        float getRotationPower() const;// public RVA = 0x4CB0C0
        virtual void weatherUpdated(WeatherInstance* weather, bool newWeather);// public RVA = 0x5494E0 vtable offset = 0x0
        void _NV_weatherUpdated(WeatherInstance* weather, bool newWeather);// public RVA = 0x5494E0 vtable offset = 0x0
        Ogre::Vector3 rotAxis; // 0x40 Member
        Ogre::Radian rotAngle; // 0x4C Member
        float rotationSpeed; // 0x50 Member
        float rotationPower; // 0x54 Member
        float speedMin; // 0x58 Member
        float speedMax; // 0x5C Member
        BuildingRotation rotationFunction; // 0x60 Member
        Ogre::Quaternion rotationBase; // 0x64 Member
        bool isRotating; // 0x74 Member
        Ogre::Quaternion rotationSrc; // 0x78 Member
        Ogre::Quaternion rotationDst; // 0x88 Member
        float rotatingTime; // 0x98 Member
        float rotationDuration; // 0x9C Member
        float windSpeedRotationMin; // 0xA0 Member
        float windSpeedRotationMax; // 0xA4 Member
        float windSpeedRotationDanger; // 0xA8 Member
        // no_addr class PhysicsCollection::RotatingEnt & operator=(const class PhysicsCollection::RotatingEnt & _a1);// public missing arg names
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
    class LightEnt
    {
    public:
        LightEnt(GameData* data, bool indoors, Ogre::SceneNode* parentNode);// public RVA = 0x553460
        void _CONSTRUCTOR(GameData* data, bool indoors, Ogre::SceneNode* parentNode);// public RVA = 0x553460
        ~LightEnt();// public RVA = 0x4CB2D0
        void _DESTRUCTOR();// public RVA = 0x4CB2D0
        Ogre::Light* light; // 0x0 Member
        float brightness; // 0x8 Member
        float range; // 0xC Member
        void setEnergyLevel(float level);// public RVA = 0x5464C0
        void setFloor(int floor);// public RVA = 0x5464E0
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    PhysicsCollection::RotatingEnt* findRotatingEnt(GameData* part) const;// public RVA = 0x4CB590
    float getWindRotationPower() const;// public RVA = 0x4CB610
    PhysicsCollection::RotatingEnt* getWindMillPart() const;// public RVA = 0x4CB690
    bool isLoaded();// public RVA = 0x4CB700
    void setVisible(bool on);// public RVA = 0x4CB770
    void handleChanged(const hand& h);// public RVA = 0x4CB870
    void update(float speed);// public RVA = 0x4CB8E0
    float updateAimingType(float speed, const Ogre::Vector3& rotTarget);// public RVA = 0x4CB950
    lektor<PhysicsCollection::StaticEnt*> staticEnts; // 0x0 Member
    lektor<SimplePhysXEntity*> parts; // 0x18 Member
    lektor<PhysicsCollection::LightEnt*> lights; // 0x30 Member
    // no_addr void PhysicsCollection(const class PhysicsCollection & _a1);// public missing arg names
    PhysicsCollection();// public RVA = 0x56EC00
    void _CONSTRUCTOR();// public RVA = 0x56EC00
    // no_addr class PhysicsCollection & operator=(const class PhysicsCollection & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};