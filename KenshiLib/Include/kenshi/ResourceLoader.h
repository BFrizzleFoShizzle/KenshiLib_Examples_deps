#pragma once

#include <string>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <Ogre/OgreResourceBackgroundQueue.h>
#include <ogre/OgreImage.h>
#include "util/OgreUnordered.h"
#include "ThreadClass.h"
#include <boost/function.hpp>

/*
namespace Kenshi
{
	class ResourceLoader // TODO
	{
	public:
		class TextureLoadData
		{
			virtual ~TextureLoadData();
		public:
			// 0x8
			std::string textureName;
			//0x30
			std::string group;
			// 0x58
			Ogre::Image decodedImage;
			// 0x98
			bool bool1;
			bool bool2; // already set to 1 at function start?
			bool bool3; // set to 1 during load(), probably "success"
			bool bool4;
			// 0x9A
		};
	};
}
*/

// TODO move
namespace Kenshi
{
    class ResourceLoader : public Ogre::ResourceBackgroundQueue::Listener, public ThreadClass, public Ogre::ResourceAllocatedObject
    {
    public:
        class MeshLoadData;
        // Ogre::ResourceBackgroundQueue::Listener offset = 0x0, length = 0x8
        // ThreadClass offset = 0x8, length = 0x88
        // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<5> > offset = 0x90, length = 0x1
        class TextureLoadData
        {
        public:
            // VTable         : (none)
            std::string name; // 0x8 Member
            std::string group; // 0x30 Member
            Ogre::Image image; // 0x58 Member
            bool loaded; // 0x98 Member
            bool queued; // 0x99 Member
            bool success; // 0x9A Member
            // no_addr void TextureLoadData(const class ResourceLoader::TextureLoadData & _a1);// public missing arg names
            TextureLoadData(const std::string& name, const std::string& group);// public RVA = 0x4474D0
            void _CONSTRUCTOR(const std::string& name, const std::string& group);// public RVA = 0x4474D0
            virtual ~TextureLoadData();// public RVA = 0x447440 vtable offset = 0x0
            void _DESTRUCTOR();// public RVA = 0x447440 vtable offset = 0x0
            virtual void loadImage();// public RVA = 0x448360 vtable offset = 0x8
            void _NV_loadImage();// public RVA = 0x448360 vtable offset = 0x8
            virtual Ogre::SharedPtr<Ogre::Texture> getTexture();// public RVA = 0x44ACD0 vtable offset = 0x10
            Ogre::SharedPtr<Ogre::Texture> _NV_getTexture();// public RVA = 0x44ACD0 vtable offset = 0x10
            // no_addr class ResourceLoader::TextureLoadData & operator=(const class ResourceLoader::TextureLoadData & _a1);// public missing arg names
            // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
        };
        class MeshLoadData
        {
        public:
            MeshLoadData(const ResourceLoader::MeshLoadData& __that);// public RVA = 0x4586F0
            void _CONSTRUCTOR(const ResourceLoader::MeshLoadData& __that);// public RVA = 0x4586F0
            MeshLoadData();// public RVA = 0x448100
            void _CONSTRUCTOR();// public RVA = 0x448100
            std::string skeletonName; // 0x0 Member
            std::string materialName; // 0x28 Member
            Ogre::SharedPtr<Ogre::Material> material; // 0x50 Member
            unsigned char renderQueue; // 0x60 Member
            static ResourceLoader::MeshLoadData DEFAULT; // RVA = 0x1D91D20 Static Member
            ~MeshLoadData();// public RVA = 0xDC590
            void _DESTRUCTOR();// public RVA = 0xDC590
            // no_addr class ResourceLoader::MeshLoadData & operator=(const class ResourceLoader::MeshLoadData & _a1);// public missing arg names
            // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
        };
        class ResourceLoadRequestMesh
        {
        public:
            unsigned __int64 requestId; // 0x0 Member
            boost::function<void __cdecl(Ogre::SharedPtr<Ogre::Resource>, void*)> callback; // 0x8 Member
            ResourceLoader::MeshLoadData data; // 0x30 Member
            Ogre::Entity* entity; // 0x98 Member
            // no_addr void ResourceLoadRequestMesh(const class ResourceLoader::ResourceLoadRequestMesh & _a1);// public missing arg names
            ResourceLoadRequestMesh(unsigned __int64 requestId, const boost::function<void __cdecl(Ogre::SharedPtr<Ogre::Resource>, void*)>& callback, Ogre::Entity* entity, const ResourceLoader::MeshLoadData& data);// public RVA = 0x4494F0
            void _CONSTRUCTOR(unsigned __int64 requestId, const boost::function<void __cdecl(Ogre::SharedPtr<Ogre::Resource>, void*)>& callback, Ogre::Entity* entity, const ResourceLoader::MeshLoadData& data);// public RVA = 0x4494F0
            ~ResourceLoadRequestMesh();// public RVA = 0x448230
            void _DESTRUCTOR();// public RVA = 0x448230
            void finish();// public RVA = 0x449590
            // no_addr class ResourceLoader::ResourceLoadRequestMesh & operator=(const class ResourceLoader::ResourceLoadRequestMesh & _a1);// public missing arg names
            // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
        };
        class ResourceLoadRequestTexture
        {
        public:
            Ogre::SharedPtr<Ogre::Material> material; // 0x0 Member
            Ogre::TextureUnitState* textureUnitState; // 0x10 Member
            // no_addr void ResourceLoadRequestTexture(const class ResourceLoader::ResourceLoadRequestTexture & _a1);// public missing arg names
            ResourceLoadRequestTexture(const Ogre::SharedPtr<Ogre::Material>& material, Ogre::TextureUnitState* textureUnitState);// public RVA = 0x4482D0
            void _CONSTRUCTOR(const Ogre::SharedPtr<Ogre::Material>& material, Ogre::TextureUnitState* textureUnitState);// public RVA = 0x4482D0
            ~ResourceLoadRequestTexture();// public RVA = 0x448300
            void _DESTRUCTOR();// public RVA = 0x448300
            bool isMaterialValid() const;// public RVA = 0x4473D0
            void setTexture(const Ogre::SharedPtr<Ogre::Texture>& texture);// public RVA = 0x447400
            // no_addr class ResourceLoader::ResourceLoadRequestTexture & operator=(const class ResourceLoader::ResourceLoadRequestTexture & _a1);// public missing arg names
            // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
        };
        // Typedef        : RequestId
        // Typedef        : RequestMeshQueue
        // Typedef        : LoadersMeshMap
        // Typedef        : RequestTextureList
        // Typedef        : LoadersTextureMap
        // Typedef        : TextureLoadDataSet
        // Typedef        : TextureLoadDataList
        // Typedef        : TexturePtrRealMap
        // Typedef        : TextureUnitStateSet
        // Typedef        : LoaderCallback
        static boost::function<void __cdecl(Ogre::SharedPtr<Ogre::Resource>, void*)> EMPTY_CALLBACK; // RVA = 0x212E3F0 Static Member
        static ResourceLoader* getInstance();// public RVA = 0x6DF70
        void destroy(const Ogre::SharedPtr<Ogre::Material>& material, bool destroyManualTextures);// public RVA = 0x447200
        void destroy(Ogre::InstancedEntity* entity, bool destroyParent);// public RVA = 0x447300
        void destroy(Ogre::MovableObject* obj, bool destroyParent);// public RVA = 0x44A900
        void destroy(Ogre::Entity* entity, bool destroyParent);// public RVA = 0x44A4C0
        void destroy();// public RVA = 0x447210
        Ogre::Entity* loadModelEntity(const std::string& meshName, Ogre::SceneNode* sceneNode, bool backgroundLoading, const ResourceLoader::MeshLoadData& data, const boost::function<void __cdecl(Ogre::SharedPtr<Ogre::Resource>, void*)>& callback, Ogre::SceneMemoryMgrTypes memType, const std::string& group);// public RVA = 0x449AC0
        Ogre::Entity* loadModelEntityDetached(const std::string& meshName, bool backgroundLoading, const ResourceLoader::MeshLoadData& data, const boost::function<void __cdecl(Ogre::SharedPtr<Ogre::Resource>, void*)>& callback, Ogre::SceneMemoryMgrTypes memType, const std::string& group);// public RVA = 0x449D30
        void loadTextureUnitArray(const std::string& textureName, const Ogre::vector<std::string>::type& imagesFiles, const Ogre::SharedPtr<Ogre::Material>& material, Ogre::TextureUnitState* textureUnit, const std::string& group);// public RVA = 0x448DA0
        void loadTextureUnit(const std::string& textureName, const Ogre::SharedPtr<Ogre::Material>& material, Ogre::TextureUnitState* textureUnit, const std::string& group);// public RVA = 0x449F30
        bool isTextureLoaded(Ogre::Entity* entity) const;// public RVA = 0x447580
        Ogre::SceneNode* getSceneNode(Ogre::SceneNode* parent, Ogre::SceneMemoryMgrTypes type);// public RVA = 0x447280
        void releaseSceneNode(Ogre::SceneNode* node);// public RVA = 0x4472D0
        void removeRequest(Ogre::Entity* entity);// public RVA = 0x449240
        void updateMT();// public RVA = 0x44BBA0
        bool updateBT();// public RVA = 0x447E90
        bool isLoading() const;// public RVA = 0x447390
        class TextureArrayLoadData : public ResourceLoader::TextureLoadData
        {
        public:
            // ResourceLoader::TextureLoadData offset = 0x0, length = 0xA0
            Ogre::vector<std::string>::type filesNames; // 0xA0 Member
            Ogre::vector<Ogre::Image>::type images; // 0xC0 Member
            // no_addr void TextureArrayLoadData(const class ResourceLoader::TextureArrayLoadData & _a1);// public missing arg names
            TextureArrayLoadData(const std::string& name, const Ogre::vector<std::string>::type& files, const std::string& group);// public RVA = 0x447E10
            void _CONSTRUCTOR(const std::string& name, const Ogre::vector<std::string>::type& files, const std::string& group);// public RVA = 0x447E10
            virtual ~TextureArrayLoadData();// public RVA = 0x447B10 vtable offset = 0x0
            void _DESTRUCTOR();// public RVA = 0x447B10 vtable offset = 0x0
            virtual void loadImage();// public RVA = 0x4485F0 vtable offset = 0x0
            void _NV_loadImage();// public RVA = 0x4485F0 vtable offset = 0x0
            virtual Ogre::SharedPtr<Ogre::Texture> getTexture();// public RVA = 0x448BC0 vtable offset = 0x0
            Ogre::SharedPtr<Ogre::Texture> _NV_getTexture();// public RVA = 0x448BC0 vtable offset = 0x0
            // no_addr class ResourceLoader::TextureArrayLoadData & operator=(const class ResourceLoader::TextureArrayLoadData & _a1);// public missing arg names
            // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
        };
        // no_addr void ResourceLoader(const class ResourceLoader & _a1);// public missing arg names
        ResourceLoader();// protected RVA = 0x44AE50
        void _CONSTRUCTOR();// protected RVA = 0x44AE50
        virtual ~ResourceLoader();// protected RVA = 0x44B290 vtable offset = 0x0
        void _DESTRUCTOR();// protected RVA = 0x44B290 vtable offset = 0x0
        void init();// protected RVA = 0x448020
        unsigned __int64 setupResourceMesh(Ogre::SharedPtr<Ogre::Resource> resource);// protected RVA = 0x448140
        Ogre::Entity* createLoadRequestMesh(const Ogre::SharedPtr<Ogre::Mesh>& mesh, const boost::function<void __cdecl(Ogre::SharedPtr<Ogre::Resource>, void*)>& callback, const ResourceLoader::MeshLoadData& data, Ogre::SceneMemoryMgrTypes memType);// protected RVA = 0x449620
        virtual void operationCompleted(unsigned __int64 ticket, const Ogre::BackgroundProcessResult& result);// protected RVA = 0x44A9D0 vtable offset = 0x0
        void _NV_operationCompleted(unsigned __int64 ticket, const Ogre::BackgroundProcessResult& result);// protected RVA = 0x44A9D0 vtable offset = 0x0
        bool abortLoadRequest(unsigned __int64 requestId);// protected RVA = 0x447D20
        virtual unsigned long threadProc();// protected RVA = 0x447FC0 vtable offset = 0x0
        unsigned long _NV_threadProc();// protected RVA = 0x447FC0 vtable offset = 0x0
        bool running; // 0x90 Member
        Ogre::SceneManager* sceneManager; // 0x98 Member
        ogre_unordered_map<unsigned __int64, ResourceLoader::ResourceLoadRequestMesh*>::type activeMeshLoaders; // 0xA0 Member
        ogre_unordered_map<unsigned __int64, ResourceLoader::ResourceLoadRequestMesh*>::type abortedMeshLoaders; // 0xE0 Member
        std::list<ResourceLoader::ResourceLoadRequestMesh*, Ogre::STLAllocator<ResourceLoader::ResourceLoadRequestMesh*, Ogre::GeneralAllocPolicy > > loadedMeshesList; // 0x120 Member
        std::list<ResourceLoader::ResourceLoadRequestMesh*, Ogre::STLAllocator<ResourceLoader::ResourceLoadRequestMesh*, Ogre::GeneralAllocPolicy > > loadingMeshQueue; // 0x140 Member
        boost::shared_mutex loadingMeshQueueMutex; // 0x160 Member
        boost::unordered::unordered_map<ResourceLoader::TextureLoadData*, Ogre::FastArray<ResourceLoader::ResourceLoadRequestTexture*>, boost::hash<ResourceLoader::TextureLoadData*>, std::equal_to<ResourceLoader::TextureLoadData*>, Ogre::STLAllocator<std::pair<ResourceLoader::TextureLoadData* const, Ogre::FastArray<ResourceLoader::ResourceLoadRequestTexture*> >, Ogre::GeneralAllocPolicy > > activeTextureLoaders; // 0x180 Member
        ogre_unordered_set<ResourceLoader::TextureLoadData*>::type texturesToLoad; // 0x1C0 Member
        boost::shared_mutex texturesLoadingMutex; // 0x200 Member
        boost::shared_mutex texturesLoadedMutex; // 0x220 Member
        Ogre::FastArray<ResourceLoader::TextureLoadData*> texturesLoading; // 0x240 Member
        Ogre::FastArray<ResourceLoader::TextureLoadData*> texturesLoaded; // 0x258 Member
        boost::unordered::unordered_map<Ogre::SharedPtr<Ogre::Texture>, float, boost::hash<Ogre::SharedPtr<Ogre::Texture> >, std::equal_to<Ogre::SharedPtr<Ogre::Texture> >, Ogre::STLAllocator<std::pair<Ogre::SharedPtr<Ogre::Texture> const, float>, Ogre::GeneralAllocPolicy > > manualTexturesLoaded; // 0x270 Member
        ogre_unordered_set<Ogre::TextureUnitState*>::type textureUnitsLoading; // 0x2B0 Member
        static void SetMeshData(Ogre::Entity* entity, const ResourceLoader::MeshLoadData& data);// protected RVA = 0x447850
        static Ogre::LodStrategy* MeshLodStrategy; // RVA = 0x212E3E0 Static Member
        // no_addr class ResourceLoader & operator=(const class ResourceLoader & _a1);// public missing arg names
        // no_addr void __local_vftable_ctor_closure();// public
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x8 missing arg names
    };
}