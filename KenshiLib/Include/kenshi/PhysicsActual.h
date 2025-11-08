#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <string>
#include <ogre/OgreQuaternion.h>

#include <boost/thread/shared_mutex.hpp>
#include <kenshi/util/PerfTimer.h>
#include <kenshi/util/lektor.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/util/hand.h>
#include "ThreadClass.h"

class NxVec3;
class NxMaterial;
class NxShape;
class NxScene;
class NxActor;
class NxControllerManager;
class NxPhysicsSDK;
class NxJoint;

enum NxShapeFlag
{
    NX_TRIGGER_ON_ENTER = 0x1,
    NX_TRIGGER_ON_LEAVE = 0x2,
    NX_TRIGGER_ON_STAY = 0x4,
    NX_TRIGGER_ENABLE = 0x7,
    NX_SF_VISUALIZATION = 0x8,
    NX_SF_DISABLE_COLLISION = 0x10,
    NX_SF_FEATURE_INDICES = 0x20,
    NX_SF_DISABLE_RAYCASTING = 0x40,
    NX_SF_POINT_CONTACT_FORCE = 0x80,
    NX_SF_FLUID_DRAIN = 0x100,
    NX_SF_FLUID_DISABLE_COLLISION = 0x400,
    NX_SF_FLUID_TWOWAY = 0x800,
    NX_SF_DISABLE_RESPONSE = 0x1000,
    NX_SF_DYNAMIC_DYNAMIC_CCD = 0x2000,
    NX_SF_DISABLE_SCENE_QUERIES = 0x4000,
    NX_SF_CLOTH_DRAIN = 0xFFFF8000,
    NX_SF_CLOTH_DISABLE_COLLISION = 0x10000,
    NX_SF_CLOTH_TWOWAY = 0x20000,
    NX_SF_SOFTBODY_DRAIN = 0x40000,
    NX_SF_SOFTBODY_DISABLE_COLLISION = 0x80000,
    NX_SF_SOFTBODY_TWOWAY = 0x100000
};

class NxUserTriggerReport
{
public:
    // VTable         : (none)
    virtual void onTrigger(NxShape& _a1, NxShape& _a2, NxShapeFlag _a3) = 0;// public vtable offset = 0x0 missing arg names
    virtual ~NxUserTriggerReport();// protected RVA = 0x7DCF20 vtable offset = 0x8
    void _DESTRUCTOR();// protected RVA = 0x7DCF20 vtable offset = 0x8
    // no_addr void NxUserTriggerReport(const class NxUserTriggerReport & _a1);// public missing arg names
    NxUserTriggerReport();// public RVA = 0x7DC880
    NxUserTriggerReport* _CONSTRUCTOR();// public RVA = 0x7DC880
    // no_addr class NxUserTriggerReport & operator=(const class NxUserTriggerReport & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x8 missing arg names
};

namespace NXU
{
    class NxuPhysicsCollection;
    class NxTriangleMeshDesc;
}

class PhysFileParams;
class _ScytheRootObjectInterfaceT;

// TODO move?
namespace Scythe
{
    class ScythePhysicsEntityData;
    class Vector3;
    class Matrix;
    class Quat;
    class ScytheActor;
    class PhysicsActorData;
    class SkeletonData;
    class PhysicsJointData;
    class PhysicsModelData;
    class PhysicsClass
    {
    public:
        bool insert(PhysFileParams* p, _ScytheRootObjectInterfaceT* physical, NxScene* const world, const Scythe::ScythePhysicsEntityData* physEnt, const Scythe::Vector3& position, const Scythe::Matrix& rotation);// public RVA = 0x1B1A70
        bool insert(PhysFileParams* owner, _ScytheRootObjectInterfaceT* obj, NxScene* const world, const Scythe::ScythePhysicsEntityData* physEnt, const Scythe::Vector3& position, const Scythe::Quat& rotation);// public RVA = 0x1B2010
        bool insert(PhysFileParams* owner, _ScytheRootObjectInterfaceT* obj, NxScene* const world, const Scythe::ScythePhysicsEntityData* physEnt, const Scythe::Vector3& position);// public RVA = 0x1B1F70
        Scythe::ScytheActor* createNewActor1(const Scythe::PhysicsActorData* act, PhysFileParams* p, _ScytheRootObjectInterfaceT* physicalObj, const Scythe::Vector3& position, NxScene* const nxScene, const Scythe::Matrix& rotation, Scythe::SkeletonData* skeleton);// protected RVA = 0x1B1160
        Scythe::ScytheActor* createNewActor(PhysFileParams* params, const Scythe::PhysicsActorData* act, const Scythe::Vector3& position, NxScene* const nxScene, const Scythe::Matrix& rotation, Scythe::SkeletonData* skeleton);// protected RVA = 0x1A8730
        NxJoint* createJoint1(const Scythe::PhysicsJointData* joint, NxActor* const act0, NxActor* const act1, NxScene* const nxScene, const Scythe::Vector3& positionOffset, const Scythe::Matrix& rotationOffset, const Scythe::Vector3& scale, int jointParam);// protected RVA = 0x1B0FC0
        NxJoint* createJoint(const Scythe::PhysicsJointData* joint, NxActor* const act0, NxActor* const act1, NxScene* const nxScene, const Scythe::Vector3& positionOffset, const Scythe::Matrix& _rotationOffset, const Scythe::Vector3& scale, int jointParam);// protected RVA = 0x1A7D00
        Scythe::SkeletonData* createSkeletalModel(PhysFileParams* p, _ScytheRootObjectInterfaceT* obj, const Scythe::PhysicsModelData* model, const Scythe::Vector3& position, const Scythe::Matrix& rotation);// protected RVA = 0x7E3D20
    };
}

// TODO move
class ThreadWannabe : public ThreadClass
{
public:
    // ThreadClass offset = 0x0, length = 0x88
    // no_addr void ThreadWannabe(const class ThreadWannabe & _a1);// public missing arg names
    ThreadWannabe(const std::string& threadname);// protected RVA = 0x25F650
    ThreadWannabe* _CONSTRUCTOR(const std::string& threadname);// protected RVA = 0x25F650
    virtual void backThreadUpdate(float _a1, bool _a2) = 0;// protected vtable offset = 0x10 missing arg names
    CPerfTimer timer; // 0x88 Member
    // no_addr double getTimeStamp();// public
    bool isPaused();// public RVA = 0x7E0520
    void setPaused(bool on, float _speedMult);// public RVA = 0x7899F0
    // no_addr float getFrameSpeedMult();// public
    // no_addr void lockEverythingSoICanSave();// public
    // no_addr void unlockEverythingAgain();// public
    boost::shared_mutex mute; // 0x98 Member
    bool paused; // 0xB8 Member
    double speedMult; // 0xC0 Member
    boost::shared_mutex haltEverythingMutex; // 0xC8 Member
    virtual unsigned long threadProc();// public RVA = 0x25F830 vtable offset = 0x0
    unsigned long _NV_threadProc();// public RVA = 0x25F830 vtable offset = 0x0
    virtual void forceLoopMT();// public RVA = 0x25F770 vtable offset = 0x18
    void _NV_forceLoopMT();// public RVA = 0x25F770 vtable offset = 0x18
    virtual ~ThreadWannabe();// public RVA = 0x25FA20 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x25FA20 vtable offset = 0x0
    // no_addr class ThreadWannabe & operator=(const class ThreadWannabe & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class PhysicsActual;
class PhysicsHullT;
class SimplePhysXEntity;
class RootObject;
class PhysicsThreadedBaseInterface;
class DoorStuff;
class TerrainSector;
class GameData;
class PreviewBuilding;
class AttachmentData;
class ScythePhysicsT;
class ScytheRagdollPhysicsT;
class PhysFileParams;
class ConstantTracerT;

template<typename T>
class MessageChain
{
public:
    // VTable         : (none)
    // no_addr void MessageChain<ConstantTracerT *>(const class MessageChain<ConstantTracerT *> & _a1);// public missing arg names
    // no_addr void MessageChain<ConstantTracerT *>();// public
    virtual ~MessageChain<T>();// public vtable offset = 0x0
    virtual bool flush();// public vtable offset = 0x8
    // no_addr void addMessage(class ConstantTracerT * _a1);// public missing arg names
    // no_addr int getMessageCountMT();// public
    // no_addr class lektor<ConstantTracerT *> & getMessages();// public
    lektor<T> mainThreadData; // 0x8 Member
    lektor<T> backThreadData; // 0x20 Member
    // no_addr class MessageChain<ConstantTracerT *> & operator=(const class MessageChain<ConstantTracerT *> & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class PhysicsInterface : public ThreadWannabe
{
public:
    // ThreadWannabe offset = 0x0, length = 0xE8
    // no_addr void PhysicsInterface(const class PhysicsInterface & _a1);// public missing arg names
    PhysicsInterface();// public RVA = 0x7E0610
    PhysicsInterface* _CONSTRUCTOR();// public RVA = 0x7E0610
    virtual ~PhysicsInterface();// public RVA = 0x7E08E0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x7E08E0 vtable offset = 0x0
    PhysicsActual* getBackthread();// public RVA = 0x7DAA10
    virtual void updateUT() = 0;// public vtable offset = 0x20
    virtual void backThreadUpdate(float _a1, bool _a2) = 0;// public vtable offset = 0x0 missing arg names
    PhysicsHullT* createTriggerHull(const Ogre::Vector3& pos, const Ogre::Vector3& size, RootObject* user);// public RVA = 0x4CC3D0
    SimplePhysXEntity* createStaticCapsule(const Ogre::Vector3& pos, float h, float w);// public RVA = 0x4CD7D0
    void destroy(PhysicsThreadedBaseInterface* hull);// public RVA = 0xF15E0
    void destroyActor(NxActor* hull);// public RVA = 0x7EA8D0
    void changeGroup(SimplePhysXEntity* hull, unsigned short group);// public RVA = 0x575170
    void addImpulse(SimplePhysXEntity* hull, const Ogre::Vector3& force, const Ogre::Vector3& pos);// public RVA = 0xD4340
    void addNewObject(PhysicsThreadedBaseInterface* t);// public RVA = 0xF1630
    void doorWantsSetup(DoorStuff* t);// public RVA = 0x56EBB0
    void loadTerrain(TerrainSector* t);// public RVA = 0x7EA920
    bool scytheInsertPreview(GameData* buildingData, PreviewBuilding* pre);// public RVA = 0x7E59D0
    void scytheCreateAttachmentData(const std::string& filename, lektor<AttachmentData*>& out);// public RVA = 0x7E2920
    ScythePhysicsT* loadScytheFileMT(RootObject* userdata, const std::string& file, const Ogre::Vector3& pos, const Ogre::Quaternion& q, const std::string& boneAttachment, GameData* itemdata);// public RVA = 0x7E6200
    ScytheRagdollPhysicsT* loadScytheRagdollFileMT(PhysFileParams* p);// public RVA = 0x7E3C70
    SimplePhysXEntity* createSimplePhysicsEntityMT(Ogre::Entity* ent, PhysFileParams* p, bool _static);// public RVA = 0x7E1E70
    SimplePhysXEntity* createSimplePhysicsEntityMT(const std::string& entname, PhysFileParams* p, bool _static);// public RVA = 0x7E1F80
    void addConstantTracerMT(ConstantTracerT* t);// public RVA = 0x4CFB80
    void removeConstantTracerMT(ConstantTracerT* t);// public RVA = 0x4CFBD0
    NxScene* nWorld; // 0xE8 Member
    MessageChain<ConstantTracerT*> newConstantTracers; // 0xF0 Member
    MessageChain<ConstantTracerT*> removeConstantTracers; // 0x128 Member
    ogre_unordered_set<ConstantTracerT*>::type constantTracers; // 0x160 Member
    MessageChain<PhysicsThreadedBaseInterface*> hullsToMake; // 0x1A0 Member
    lektor<PhysicsThreadedBaseInterface*> hulls; // 0x1D8 Member
    MessageChain<PhysicsThreadedBaseInterface*> hullsToDestroy; // 0x1F0 Member
    MessageChain<std::pair<SimplePhysXEntity*, int> > hullsToChangeGroup; // 0x228 Member
    MessageChain<boost::tuples::tuple<SimplePhysXEntity*, Ogre::Vector3, Ogre::Vector3, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type> > impulse; // 0x260 Member
    MessageChain<NxActor*> actorsToDestroy; // 0x298 Member
    lektor<DoorStuff*> doorsToSetup; // 0x2D0 Member
    MessageChain<TerrainSector*> terrainToLoad; // 0x2E8 Member
    bool _queuesClear; // 0x320 Member
    boost::shared_mutex queuesClearMuto; // 0x328 Member
    bool queuesAreClearMT();// public RVA = 0x174060
    void setQueuesAreClear(bool on);// public RVA = 0x579770
    // no_addr class PhysicsInterface & operator=(const class PhysicsInterface & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class PhysicsActual : public PhysicsInterface, public Ogre::GeneralAllocatedObject
{
public:
    // PhysicsInterface offset = 0x0, length = 0x348
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x348, length = 0x1
    // no_addr void PhysicsActual(const class PhysicsActual & _a1);// public missing arg names
    PhysicsActual();// public RVA = 0x7DBF70
    PhysicsActual* _CONSTRUCTOR();// public RVA = 0x7DBF70
    virtual ~PhysicsActual();// public RVA = 0x7DC020 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x7DC020 vtable offset = 0x0
    virtual void updateUT();// public RVA = 0x4CD350 vtable offset = 0x0
    void _NV_updateUT();// public RVA = 0x4CD350 vtable offset = 0x0
    virtual void backThreadUpdate(float time, bool _useOwnTimers);// public RVA = 0x7DBE00 vtable offset = 0x0
    void _NV_backThreadUpdate(float time, bool _useOwnTimers);// public RVA = 0x7DBE00 vtable offset = 0x0
    void threadJunkPreBT();// public RVA = 0x4CBEA0
    void threadJunkPostBT();// public RVA = 0x4CD1C0
    bool setup();// public RVA = 0x7DAC80
    std::string scytheGetFirstModelName(const std::string& filename);// public RVA = 0x7E2C30
    bool scytheInsert(_ScytheRootObjectInterfaceT* out);// public RVA = 0x7E2E40
    void convertXMLToBin(std::string& filename, const Ogre::Vector3& scale);// public RVA = 0x7E4940
    NxActor* loadPhysXFile(PhysFileParams& p, lektor<NxActor*>* out);// public RVA = 0x7E4320
    NxActor* loadPhysXFileAsATrigger(PhysFileParams& p, lektor<NxActor*>* out);// public RVA = 0x7E4590
    NxActor* _createTriggerHull(const Ogre::Vector3& pos, const Ogre::Vector3& size);// public RVA = 0x7E2070
    NxActor* _createStaticCapsule(const Ogre::Vector3& pos, float length, float radius);// public RVA = 0x7E2410
    NxActor* _createStaticBox(const Ogre::Vector3& pos, const Ogre::Vector3& dimensions, const Ogre::Quaternion& rot, int group);// public RVA = 0x7E2660
    void _destroy(NxActor* actor);// public RVA = 0x7DAA20
    static void setActorCollisionGroup(NxActor* actor, unsigned short group);// public RVA = 0x7DAA70
    static unsigned short getActorCollisionGroup(NxActor* actor);// public RVA = 0x7DAB10
    static void setActorMaterial(NxActor* actor, int material);// public RVA = 0x7DAB60
    void scaleCollection(NXU::NxuPhysicsCollection*& collection, const NxVec3& scale);// public RVA = 0x7E31B0
    bool uncookMesh(NXU::NxTriangleMeshDesc* mesh, const char* cId) const;// public RVA = 0x7E1C10
    NxMaterial* materialConcrete; // 0x348 Member
    NxMaterial* materialMetal; // 0x350 Member
    NxMaterial* materialSand; // 0x358 Member
    NxMaterial* materialHuman; // 0x360 Member
    class TriggerCallback : public NxUserTriggerReport
    {
    public:
        // NxUserTriggerReport offset = 0x0, length = 0x8
        virtual void onTrigger(NxShape& triggerShape, NxShape& otherShape, NxShapeFlag status);// public RVA = 0x4CCF40 vtable offset = 0x0
        void _NV_onTrigger(NxShape& triggerShape, NxShape& otherShape, NxShapeFlag status);// public RVA = 0x4CCF40 vtable offset = 0x0
        void updateFrameEndMT();// public RVA = 0x4CD0D0
        ogre_unordered_map<hand, hand>::type triggerUpdateMap; // 0x8 Member
        // no_addr void TriggerCallback(const class PhysicsActual::TriggerCallback & _a1);// public missing arg names
        TriggerCallback();// public RVA = 0x7DF690
        TriggerCallback* _CONSTRUCTOR();// public RVA = 0x7DF690
        virtual ~TriggerCallback();// public RVA = 0x7DF6F0 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0x7DF6F0 vtable offset = 0x0
        // no_addr class PhysicsActual::TriggerCallback & operator=(const class PhysicsActual::TriggerCallback & _a1);// public missing arg names
        // no_addr void __local_vftable_ctor_closure();// public
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x8 missing arg names
    };
    PhysicsActual::TriggerCallback myTriggerCallback; // 0x368 Member
    bool HW; // 0x3B0 Member
    bool debugRenderOn; // 0x3B1 Member
    Scythe::PhysicsClass scytheClass; // 0x3B2 Member
    NxControllerManager* controllerMgr; // 0x3B8 Member
    NxPhysicsSDK* physicsSDK; // 0x3C0 Member
    // no_addr class PhysicsActual & operator=(const class PhysicsActual & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class NxVec3
{
public:
    NxVec3(const NxVec3& v);// public RVA = 0x1B5930
    NxVec3* _CONSTRUCTOR(const NxVec3& v);// public RVA = 0x1B5930
    NxVec3(const float* v);// public RVA = 0x1BE630
    NxVec3* _CONSTRUCTOR(const float* v);// public RVA = 0x1BE630
    // no_addr void NxVec3(const struct _Nx3F32 & _a1);// public missing arg names
    NxVec3(float _x, float _y, float _z);// public RVA = 0x1A6D00
    NxVec3* _CONSTRUCTOR(float _x, float _y, float _z);// public RVA = 0x1A6D00
    NxVec3(float a);// public RVA = 0x7E7BA0
    NxVec3* _CONSTRUCTOR(float a);// public RVA = 0x7E7BA0
    NxVec3() {};// public RVA = 0x1AA820
    NxVec3* _CONSTRUCTOR();// public RVA = 0x1AA820
    // no_addr const class NxVec3 & operator=(const struct _Nx3F32 & _a1);// public missing arg names
    const NxVec3& operator=(const NxVec3& v);// public RVA = 0x1AA830
    // no_addr void get(double * _a1);// public missing arg names
    // no_addr void get(float * _a1);// public missing arg names
    // no_addr float * get();// public
    // no_addr const float * get();// public
    // no_addr float operator[](int _a1);// public missing arg names
    float& operator[](int index);// public RVA = 0x204170
    // no_addr bool operator<(const class NxVec3 & _a1);// public missing arg names
    bool operator==(const NxVec3& v) const;// public RVA = 0x1DE480
    bool operator!=(const NxVec3& v) const;// public RVA = 0x23DDB0
    // no_addr void set(float _a1);// public missing arg names
    void set(float _x, float _y, float _z);// public RVA = 0x1AA850
    // no_addr void set(const double * _a1);// public missing arg names
    void set(const float* v);// public RVA = 0x2455D0
    // no_addr void set(const class NxVec3 & _a1);// public missing arg names
    // no_addr void setx(const float & _a1);// public missing arg names
    // no_addr void sety(const float & _a1);// public missing arg names
    // no_addr void setz(const float & _a1);// public missing arg names
    // no_addr void setNegative();// public
    // no_addr void setNegative(const class NxVec3 & _a1);// public missing arg names
    void zero();// public RVA = 0x1AA870
    int isZero() const;// public RVA = 0x1AA7E0
    // no_addr void setPlusInfinity();// public
    // no_addr void setMinusInfinity();// public
    // no_addr void min(const class NxVec3 & _a1);// public missing arg names
    // no_addr void max(const class NxVec3 & _a1);// public missing arg names
    void add(const NxVec3& a, const NxVec3& b);// public RVA = 0x4EBDA0
    void subtract(const NxVec3& a, const NxVec3& b);// public RVA = 0x4EBDE0
    // no_addr void multiply(float _a1, const class NxVec3 & _a2);// public missing arg names
    // no_addr void arrayMultiply(const class NxVec3 & _a1, const class NxVec3 & _a2);// public missing arg names
    void multiplyAdd(float s, const NxVec3& a, const NxVec3& b);// public RVA = 0x4EBE20
    float normalize();// public RVA = 0x4CF520
    void setMagnitude(float length);// public RVA = 0x7D6B80
    unsigned int closestAxis() const;// public RVA = 0x204180
    // no_addr enum NxAxisType snapToClosestAxis();// public
    bool isFinite() const;// public RVA = 0x1AA880
    float dot(const NxVec3& v) const;// public RVA = 0x1AB190
    // no_addr bool sameDirection(const class NxVec3 & _a1);// public missing arg names
    float magnitude() const;// public RVA = 0x4CE950
    float magnitudeSquared() const;// public RVA = 0x1AB1C0
    // no_addr float distance(const class NxVec3 & _a1);// public missing arg names
    // no_addr float distanceSquared(const class NxVec3 & _a1);// public missing arg names
    // no_addr class NxVec3 cross(const class NxVec3 & _a1);// public missing arg names
    void cross(const NxVec3& left, const NxVec3& right);// public RVA = 0x1B5950
    // no_addr void setNotUsed();// public
    // no_addr int isNotUsed();// public
    bool equals(const NxVec3& v, float epsilon) const;// public RVA = 0x7E82E0
    // no_addr class NxVec3 operator-(const class NxVec3 & _a1);// public missing arg names
    NxVec3 operator-() const;// public RVA = 0x3D2660
    NxVec3 operator+(const NxVec3& v) const;// public RVA = 0x1BE650
    // no_addr class NxVec3 operator*(float _a1);// public missing arg names
    // no_addr class NxVec3 operator/(float _a1);// public missing arg names
    NxVec3& operator+=(const NxVec3& v);// public RVA = 0x1BE690
    NxVec3& operator-=(const NxVec3& v);// public RVA = 0x1D6EC0
    NxVec3& operator*=(float f);// public RVA = 0x1D6F00
    // no_addr class NxVec3 & operator/=(float _a1);// public missing arg names
    NxVec3 operator^(const NxVec3& v) const;// public RVA = 0x1B59E0
    // no_addr float operator|(const class NxVec3 & _a1);// public missing arg names
    float x; // 0x0 Member
    float y; // 0x4 Member
    float z; // 0x8 Member
};

namespace NXU
{
    class NxuPhysicsCollection;
    enum NXU_FileType
    {
        FT_BINARY,
        FT_XML,
        FT_COLLADA
    };

    NxuPhysicsCollection* scaleCopyCollection(const NxuPhysicsCollection* source, const char* newId, const NxVec3& scale, NxPhysicsSDK* sdk);// RVA = 0x20B3B0
    NxuPhysicsCollection* loadCollection(const char* fname, NXU::NXU_FileType type, void* mem, int len);// RVA = 0x1DD040
}
NXU::NxuPhysicsCollection* loadPhysXResource(const std::string& filename, int type);// RVA = 0x7E4190