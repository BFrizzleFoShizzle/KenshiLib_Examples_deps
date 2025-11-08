#pragma once

#include "Enums.h"
#include "util/lektor.h"
#include "util/TimeOfDay.h"
#include "util/StringPair.h"

#include <ogre/OgreVector3.h>
#include <kenshi/util/OgreUnordered.h>

// 1.0.59 GOG MedicalSystem TakeDamage possibly @ kenshi_GOG_x64.exe+5056D0 
// MedicalSystem::TakeDamage(HealthPartStatus* part, struct damage, uint64_t unk)
enum LimbState
{
    LIMB_ORIGINAL = 0x0,
    LIMB_STUMP = 0x1,
    LIMB_REPLACED = 0x2,
    LIMB_CRUSHED = 0x3
};

class Character;
class GameData;
class Item;
class RootObject;

// TODO move?
class RobotLimbs
{
public:
    enum Limb
    {
        LEFT_ARM,
        RIGHT_ARM,
        LEFT_LEG,
        RIGHT_LEG,
        NULL_LIMB
    };

    RobotLimbs(Character* c);// public RVA = 0xCD3B0
    RobotLimbs* _CONSTRUCTOR(Character* c);// public RVA = 0xCD3B0
    ~RobotLimbs();// public RVA = 0xCD3E0
    void _DESTRUCTOR();// public RVA = 0xCD3E0
    void load(GameData* state);// public RVA = 0xD0150
    void save(GameData* state) const;// public RVA = 0xCFB10
    LimbState getState(RobotLimbs::Limb limb) const;// public RVA = 0xCD410
    Item* getLimb(RobotLimbs::Limb limb) const;// public RVA = 0xCD420
    int getMask() const;// public RVA = 0xCD430
    void setLimb(RobotLimbs::Limb limb, LimbState state, Item* item);// public RVA = 0xCFD90
    RootObject* getInventoryInterface(bool create);// public RVA = 0xD0490
    void destroyInventoryInterface();// public RVA = 0xCD480
    Item* getLimbItem(RobotLimbs::Limb l);// public RVA = 0x6431B0
    Character* character; // 0x0 Member
    RootObject* inventory; // 0x8 Member
    LimbState states[0x4]; // 0x10 Member
    Item* items[0x4]; // 0x20 Member
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};

namespace AttackDirection 
{
    enum Enum
    {
        FRONT = 0x1,
        BACK = 0x2,
        LEFT = 0x4,
        RIGHT = 0x8,
        TOP = 0x10,
        BOTTOM = 0x20
    };
}

class Wound;
class CharStats;
class RobotLimbItem;
class AnimationClass;
class Armour;
class Harpoon;
class Faction;
class Damages;
class CombatTechniqueData;
class DatapanelGUI;


class MedicalSystem
{
public:
    // VTable         : (none)
    void precalculateFirstAidNeedScore();// private RVA = 0x6446E0
    // no_addr void MedicalSystem(const class MedicalSystem & _a1);// public missing arg names
    MedicalSystem();// public RVA = 0x640270
    MedicalSystem* _CONSTRUCTOR();// public RVA = 0x640270
    virtual ~MedicalSystem();// public RVA = 0x646230 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x646230 vtable offset = 0x0
    void init(AnimationClass* animsys, Character* c, GameData* race, CharStats* _stats);// public RVA = 0x64DC90
    virtual void updateStats();// public RVA = 0x644B50 vtable offset = 0x8
    void _NV_updateStats();// public RVA = 0x644B50 vtable offset = 0x8
    void notifyRaceChange(GameData* race);// public RVA = 0x64D590
    void medicalUpdate(float frameTime);// public RVA = 0x651880
    virtual void periodicUpdate();// public RVA = 0x64D2F0 vtable offset = 0x10
    void _NV_periodicUpdate();// public RVA = 0x64D2F0 vtable offset = 0x10
    float scoreFirstAidNeed(bool robotAid) const;// public RVA = 0x643520
    float scoreJuryRigNeed(float skills) const;// public RVA = 0x645C80
    bool isFullyRested() const;// public RVA = 0x643550
    void _setHealth(const std::string& bodypart, float amount);// public RVA = 0x645770
    void validateHealthValues();// public RVA = 0x644E20
    LimbState getLimbState(RobotLimbs::Limb limb) const;// public RVA = 0x6433B0
    void amputate(RobotLimbs::Limb limb, bool createSeveredItem, const Ogre::Vector3& force);// public RVA = 0x64E640
    void crushLimb(RobotLimbs::Limb limb);// public RVA = 0x6433D0
    bool isUselessNoLimbGuy();// public RVA = 0x6439F0
    float recalculateStealthHinderance();// public RVA = 0x644620
    class HealthPartStatus
    {
    public:
        GameData* data; // 0x0 Member
        void serialise(GameData* out, int num);// public RVA = 0x64CC10
        void load(GameData* out, int num);// public RVA = 0x64CE80
        enum PartType
        {
            PART_TORSO,
            PART_LEG,
            PART_ARM,
            PART_HEAD
        };

        MedicalSystem::HealthPartStatus::PartType whatAmI; // 0x8 Member
        MedicalSystem* medical; // 0x10 Member
        Character* me; // 0x18 Member
        LeftRight side; // 0x20 Member
        RobotLimbItem* robotLimb; // 0x28 Member
        bool isRobotic();// public RVA = 0x6432F0
        GameData* getData();// public RVA = 0x6431C0
        RobotLimbs::Limb getRobotLimbEnum() const;// public RVA = 0x643420
        void setup(GameData* dat, float _hitchance, float _max, float _age, MedicalSystem* med, bool selfHeal, Character* _me);// public RVA = 0x64C960
        bool update(float frameTIME, float healMultFlesh, float healMultRobot, float degenerationRate, float _age, float robotWear);// public RVA = 0x64EE40
        void updateDerivedHealths();// public RVA = 0x6434A0
        void applyDamage(const Damages& damage);// public RVA = 0x6442F0
        void applyWearDamage(const Damages& damage);// public RVA = 0x643470
        float getWorstDamage(float brokenBoneValue) const;// public RVA = 0x643910
        LimbState getRobotLimbState();// public RVA = 0x53E5B0
        void setRobotLimbItem(RobotLimbItem* _robotLimb, bool isLoadingASave);// public RVA = 0x643E30
        float getExtraBleedingAmount();// public RVA = 0x644380
        bool isDead() const;// public RVA = 0x656DC0
        float getBloodynessMult() const;// public RVA = 0x53FDA0
        bool selfHealing; // 0x30 Member
        bool collapses; // 0x31 Member
        bool fatal; // 0x32 Member
        float KOMult; // 0x34 Member
        float hitChance; // 0x38 Member
        float hitChanceMult; // 0x3C Member
        float flesh; // 0x40 Member
        float fleshStun; // 0x44 Member
        float bandaging; // 0x48 Member
        float juryRigging; // 0x4C Member
        float wearDamage; // 0x50 Member
        float maxHealth() const;// public RVA = 0x2967C0
        float _maxHealth; // 0x54 Member
        float age; // 0x58 Member
        float HPMult; // 0x5C Member
        float healthAsPercent(float healt);// public RVA = 0x6431D0
        float derivedFleshHealthPercent; // 0x60 Member
    };
    ogre_unordered_map<GameData*, MedicalSystem::HealthPartStatus>::type status; // 0x8 Member
    MedicalSystem::HealthPartStatus* getPart(RobotLimbs::Limb what);// public RVA = 0x656E10
    MedicalSystem::HealthPartStatus* getPart(unsigned __int64 index);// public RVA = 0x2AA150
    MedicalSystem::HealthPartStatus* getPart(MedicalSystem::HealthPartStatus::PartType partType, LeftRight leftSide);// public RVA = 0x65A460
    // no_addr class MedicalSystem::HealthPartStatus * getPart(class GameData * _a1);// public missing arg names
    int getPartCount() const;// public RVA = 0x2AA140
    void setRobotLimbItem(RobotLimbs::Limb what, Item* item, bool isLoadingASave);// public RVA = 0x644F10
    bool hasRobotics() const;// public RVA = 0x881EE0
    lektor<Armour*> armourList; // 0x48 Member
    void addArmour(Armour* item);// public RVA = 0x6455B0
    void removeArmour(Item* item);// public RVA = 0x6456A0
    bool wearingUniformOf(Faction* f);// public RVA = 0x644B00
    void serialise(GameData* out);// public RVA = 0x64E2D0
    void load(GameData* out);// public RVA = 0x64F3C0
    GameData* addWound(bool lowBlow, CutDirection area, Damages& damage, int& material, RootObject* attacker, AttackDirection::Enum& attackDirection, Harpoon* harpoon);// public RVA = 0x650150
    float punchSomething(HitMaterialType material, Character* target, CombatTechniqueData* technique, int comboID);// public RVA = 0x666000
    static const std::string& getBoneNameForBodypart(GameData* bodypart);// public RVA = 0x649850
    float hunger; // 0x60 Member
    float fed; // 0x64 Member
    bool isFed() const;// public RVA = 0x595CC0
    TimeOfDay lastPeriodicUpdate; // 0x68 Member
    float blood; // 0x70 Member
    float getMaxBlood() const;// public RVA = 0x643920
    float extraBloodLossFromBodyparts; // 0x74 Member
    float currentBleedRate; // 0x78 Member
    MedicalSystem::HealthPartStatus* leftLeg; // 0x80 Member
    MedicalSystem::HealthPartStatus* rightLeg; // 0x88 Member
    MedicalSystem::HealthPartStatus* leftArm; // 0x90 Member
    MedicalSystem::HealthPartStatus* rightArm; // 0x98 Member
    float knockoutTimer; // 0xA0 Member
    void startKnockoutTimer();// public RVA = 0x644050
    void knockout(float skill01);// public RVA = 0x644200
    void knockoutForceTimer(float seconds);// public RVA = 0x5C6E50
    float pointOfCollapseBloodloss() const;// public RVA = 0x643200
    float pointOfNoReturn() const;// public RVA = 0x643360
    float pointOfNoReturn_Hunger01(float mult) const;// public RVA = 0x656EA0
    bool isHungerKO();// public RVA = 0x643BA0
    float getToughnessXpBonus();// public RVA = 0x8C4790
    float getHungerSpeedModifier() const;// public RVA = 0x6445B0
    float getHealthStatModifier(StatsEnumerated stat, bool _hunger, bool _wounds, bool _darkness, bool robotParts, bool weather, bool gear) const;// public RVA = 0x645060
    float _getRoboticsStatMult(StatsEnumerated stat) const;// public RVA = 0x644410
    float getMissingArmPenaltyMult() const;// public RVA = 0x656F20
    float getDerivedHeadHealth();// public RVA = 0x644600
    float worstDamage; // 0xA4 Member
    float needsFirstAidScoreTotal_robot; // 0xA8 Member
    float needsFirstAidScoreTotal_fleshy; // 0xAC Member
    float restedState; // 0xB0 Member
    float stealthHinderance; // 0xB4 Member
    float partBestArm; // 0xB8 Member
    float partHead; // 0xBC Member
    float partWorstTorso; // 0xC0 Member
    bool isCollapse(MedicalSystem::HealthPartStatus* health, float _a2);// public RVA = 0x643330
    enum CollapseStage
    {
        COLLAPSE_NONE,
        COLLAPSE_BUT_NO_RAGDOLL,
        COLLAPSE_KO
    };

    MedicalSystem::CollapseStage getCollapseStage(MedicalSystem::HealthPartStatus* health, float bias);// public RVA = 0x643CD0
    void calculateDesiredPainAnimations();// public RVA = 0x649980
    float getMovementSpeedInjuryMultiplier();// public RVA = 0x8831C0
    float getStatRoboticsMultiplier(StatsEnumerated stat);// public RVA = 0x8826D0
    float getMovementSwimSpeedInjuryMultiplier();// public RVA = 0x883280
    bool gettingEaten(float amount, bool vampire);// public RVA = 0x64FBF0
    bool gettingAcidRain(float amount);// public RVA = 0x646B40
    bool gettingAcidWater(float amount);// public RVA = 0x646500
    bool gettingAcidFeet(float amount);// public RVA = 0x646890
    bool gettingGassed(float amount);// public RVA = 0x6476B0
    bool gettingWindyface(float amount);// public RVA = 0x648770
    bool gettingBurnt(float amount);// public RVA = 0x647CE0
    bool applyFirstAid(float skill, Item* equipment, float frameTIME, Character* who);// public RVA = 0x64D080
    bool applyDoctoring(float skill, Item* equipment, float frameTIME, Character* who);// public RVA = 0x649280
    bool applyRigging(float skill, Item* equipment, float frameTIME);// public RVA = 0x6495D0
    void reassessCollapseMode(bool medic, bool agony);// public RVA = 0x648BA0
    bool isUnconcious() const;// public RVA = 0x28D8F0
    bool isCrippled() const;// public RVA = 0x51C010
    bool isDead() const;// public RVA = 0x32DA90
    bool hasAnArmToFightWith() const;// public RVA = 0x6439D0
    bool hasFreshlySeveredALimb();// public RVA = 0x644BD0
    bool isReallyHungry() const;// public RVA = 0x411960
    float scoreTechnique(CombatTechniqueData* attack);// public RVA = 0x884880
    void getMedicalGUIData(DatapanelGUI* panel);// public RVA = 0x889140
    bool isProbablyDying();// public RVA = 0x8832C0
    float dazedOrAlert; // 0xC4 Member
    float getOverallHealthRating() const;// public RVA = 0x885430
    bool canGetUpWakeUp();// public RVA = 0x595CE0
    void _reassessRagdollPartsAssumingWeJustClearedTheEntireRagdoll();// public RVA = 0x6497D0
    bool isRightArmOk() const;// public RVA = 0x333D00
    bool isLeftArmOk() const;// public RVA = 0x333D10
    bool canIkick() const;// public RVA = 0x8827F0
    bool isInBloodlossTrauma() const;// public RVA = 0x881F30
    void splatBlood(const Damages& dam, CutDirection cutDirection, AttackDirection::Enum from);// public RVA = 0x7928C0
    void clearWeatherEffects();// public RVA = 0x5E5120
    float getWeatherStatPenaltyMult() const;// public RVA = 0x643270
    int getWeatherStatPenalty(float mult) const;// public RVA = 0x6432B0
    RobotLimbs* robotLimbs; // 0xC8 Member
    bool bloodynessChanged; // 0xD0 Member
    bool bloodynessCleanedUp; // 0xD1 Member
    float calculateBleedRateForFX();// public RVA = 0x6434E0
    AnimationClass* animation; // 0xD8 Member
    Character* me; // 0xE0 Member
    StringPair weatherGUIfeedback; // 0xE8 Member
    WeatherAffecting currentWeatherAffect; // 0x148 Member
    float currentWeatherAffectStrength; // 0x14C Member
    TimeOfDay lastHungerKO; // 0x150 Member
    float nextKOTime; // 0x158 Member
    int _eatenDeathDelay; // 0x15C Member
    bool crippled; // 0x160 Member
    bool unconcious; // 0x161 Member
    bool sub50KO; // 0x162 Member
    bool bloodlossTrauma; // 0x163 Member
    bool dead; // 0x164 Member
    bool rightArmOk; // 0x165 Member
    bool leftArmOk; // 0x166 Member
    Ogre::Vector3 lastBloodPosition; // 0x168 Member
    Ogre::FastArray<Wound*> wounds; // 0x178 Member
    lektor<MedicalSystem::HealthPartStatus*> anatomy; // 0x190 Member
    void bloodlossUpdate(float frameTime);// protected RVA = 0x6459C0
    void drainMedkit(float skill, Item* equipment, float frameTIME) const;// protected RVA = 0x643AD0
    void applyDamage(MedicalSystem::HealthPartStatus* part, const Damages& damage, bool loadingSavestate, bool canSever, const Ogre::Vector3& force);// protected RVA = 0x64EB80
    void ragdollPartCollapse(MedicalSystem::HealthPartStatus* part);// protected RVA = 0x6490F0
    void updateDamageState();// protected RVA = 0x6460E0
    CharStats* stats; // 0x1A8 Member
    // no_addr class MedicalSystem & operator=(const class MedicalSystem & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

