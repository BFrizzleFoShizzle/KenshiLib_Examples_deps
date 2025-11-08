#pragma once

#include "Enums.h"
#include "util/lektor.h"
#include "util/Array2d.h"
#include "Item.h"

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

class Item;
class hand;
class Faction;
class Inventory;
class RootObject;
class GameData;


class InventorySection
{
public:
    // VTable         : (none)
    class SectionItem
    {
    public:
        Item* item; // 0x0 Member
        unsigned short x; // 0x8 Member
        unsigned short y; // 0xA Member
        unsigned short w; // 0xC Member
        unsigned short h; // 0xE Member
    };
    // no_addr void InventorySection(const class InventorySection & _a1);// public missing arg names
    InventorySection(const std::string& _name, int _w, int _h, AttachSlot slot, Inventory* inv, bool _containerSlot, bool _equipSlot, bool enabled);// public RVA = 0x748390
    InventorySection* _CONSTRUCTOR(const std::string& _name, int _w, int _h, AttachSlot slot, Inventory* inv, bool _containerSlot, bool _equipSlot, bool enabled);// public RVA = 0x748390
    virtual ~InventorySection();// public RVA = 0x746420 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x746420 vtable offset = 0x0
    virtual bool hasRoomForItem(GameData* _itemData, int quantity);// public RVA = 0x74A620 vtable offset = 0x8
    bool _NV_hasRoomForItem(GameData* _itemData, int quantity);// public RVA = 0x74A620 vtable offset = 0x8
    void notifyModified();// public RVA = 0x7465B0
    virtual bool addItem(Item* itemToAdd, int quantity);// public RVA = 0x74B6A0 vtable offset = 0x10
    bool _NV_addItem(Item* itemToAdd, int quantity);// public RVA = 0x74B6A0 vtable offset = 0x10
    virtual void _addItem(Item* item, int x, int y);// public RVA = 0x748510 vtable offset = 0x18
    void _NV__addItem(Item* item, int x, int y);// public RVA = 0x748510 vtable offset = 0x18
    Item* getItemAt(int x, int y);// public RVA = 0x745AF0
    // no_addr float getTotalWeight();// public
    bool hasItem(GameData* itemData) const;// public RVA = 0x745BA0
    bool hasItem(Item* item) const;// public RVA = 0x745B40
    bool hasItemType(itemType type);// public RVA = 0x7455A0
    virtual void autoArrange();// public RVA = 0x748B20 vtable offset = 0x20
    void _NV_autoArrange();// public RVA = 0x748B20 vtable offset = 0x20
    void getAllItemsOfType(lektor<Item*>& list, Item* item);// public RVA = 0x745D10
    void getAllItemsOfType(lektor<Item*>& list, itemType type);// public RVA = 0x745C50
    void getAllItemsOfName(lektor<Item*>& list, const std::string& itemName);// public RVA = 0x746010
    unsigned int getNumItems() const;// public RVA = 0x745630
    bool isEmpty() const;// public RVA = 0x745670
    bool removeItem(Item* item);// public RVA = 0x748810
    void clearAllItems(bool destroy, bool skipUnique);// public RVA = 0x748A10
    bool canItemGoHere(Item* item, int x, int y);// public RVA = 0x74AC30
    bool getValidInventoryPosition(Item* item, int& x, int& y);// public RVA = 0x74ACB0
    bool findNearestPlaceForItem(Item* item, int& x, int& y);// public RVA = 0x74ADE0
    int getItemsInFootprint(lektor<Item*>& itemList, int itemWidth, int itemHeight, int x, int y);// protected RVA = 0x745A00
    int getItemsInFootprint(lektor<Item*>& out, Item* item, int x, int y);// public RVA = 0x745ED0
    bool existsItemInFootprint(Item* item, int x, int y);// public RVA = 0x7454E0
    AttachSlot getLimitedSlot() const;// public RVA = 0x5C7150
    void setupContainerData(GameData* data);// public RVA = 0x74A510
    int applyStackingBonuses(int normalStackableAmount) const;// public RVA = 0x7454A0
    void recalculateTotalWeight();// public RVA = 0x747F50
    void setWeightMultiplier(float mult);// public RVA = 0x744C80
    void setStackingBonus(int minn, float mult);// public RVA = 0x2966A0
    int getMaxStack() const;// public RVA = 0x2C27A0
    // no_addr class RootObject * getCallbackObject();// public
    void addVeryLimitedSlot(GameData* item);// public RVA = 0x74A900
    void clearVeryLimitedSlot();// public RVA = 0x746970
    const lektor<GameData*>& getVeryLimitedSlot() const;// public RVA = 0x14D900
    bool isLimitedSlotCompatible(GameData* itemData);// public RVA = 0x749C30
    bool isLimitedSlotCompatible(Item* item);// public RVA = 0x74AA20
    // no_addr bool getIsAnEquippedItemSection();// public
    bool getEnabled() const;// public RVA = 0x14D910
    void setEnabled(bool value);// public RVA = 0x744C90
    void setItemsLimitCount(int value);// public RVA = 0x7449A0
    // no_addr int getItemsLimitCount();// public
    bool getItemsLimitReached() const;// public RVA = 0x7194E0
    Inventory* getInventory() const;// public RVA = 0x7449B0
    float getFillPercentage() const;// public RVA = 0x745DD0
    const Ogre::vector<InventorySection::SectionItem>::type& getItems() const;// public RVA = 0x2966C0
    Item* getItem() const;// public RVA = 0x2AC170
    std::string name; // 0x8 Member
    int width; // 0x30 Member
    int height; // 0x34 Member
    bool armourOnly; // 0x38 Member
    void setupEquipCallbacks(RootObject* owner);// protected RVA = 0x7449C0
    int numItemsInFootprint(Item* item, int x, int y);// protected RVA = 0x745F40
    void resize(int w, int h, bool clearContent);// protected RVA = 0x74A8C0
    Ogre::vector<InventorySection::SectionItem>::type items; // 0x40 Member
    Array2d<Item> content; // 0x60 Member
    int stackingBonusMin; // 0x88 Member
    float stackingBonusMult; // 0x8C Member
    lektor<GameData*> veryLimitedSlot; // 0x90 Member
    int itemsLimit; // 0xA8 Member
    float weightMultiplier; // 0xAC Member
    float totalWeight; // 0xB0 Member
    bool isAnEquippedItemSection; // 0xB4 Member
    AttachSlot limitedSlot; // 0xB8 Member
    bool containerSlot; // 0xBC Member
    RootObject* callbackObject; // 0xC0 Member
    Inventory* parentInventory; // 0xC8 Member
    bool enabled; // 0xD0 Member
    // no_addr class InventorySection & operator=(const class InventorySection & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class GameDataContainer;
class GameSaveState;
class Character;
class Weapon;
class InventoryGUI;

class Inventory : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void Inventory(const class Inventory & _a1);// public missing arg names
    Inventory(RootObject* _owner);// public RVA = 0x749D30
    Inventory* _CONSTRUCTOR(RootObject* _owner);// public RVA = 0x749D30
    virtual ~Inventory();// public RVA = 0x749E80 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x749E80 vtable offset = 0x0
    const hand& getHandle();// public RVA = 0x7449E0
    void clearAll(bool destroy, bool skipUnique);// public RVA = 0x749460
    GameData* serialise(GameDataContainer* container, GameData* refList);// public RVA = 0x7465E0
    void loadFrom(GameDataContainer* container, GameData* inventoryState);// public RVA = 0x74AED0
    void loadFrom(GameSaveState* state);// public RVA = 0x74BB90
    void notifyModified();// public RVA = 0x746380
    void fillFromVendorList(GameData* vendorData, Faction* f);// public RVA = 0x7491C0
    void fillFromVendorList(lektor<GameData*>& vendorlistList, Faction* f);// public RVA = 0x74A160
    virtual InventorySection* initialiseNewSection(const std::string& name, int w, int h, AttachSlot limitSlot, bool equipCallbacks, bool isContainerSlot, bool enabled, int limit);// public RVA = 0x74A1C0 vtable offset = 0x8
    InventorySection* _NV_initialiseNewSection(const std::string& name, int w, int h, AttachSlot limitSlot, bool equipCallbacks, bool isContainerSlot, bool enabled, int limit);// public RVA = 0x74A1C0 vtable offset = 0x8
    void resizeSection(InventorySection* sect, int w, int h, bool clearContent);// public RVA = 0x74A9D0
    void removeAllSections();// public RVA = 0x7493A0
    InventorySection* getSection(const std::string& name) const;// public RVA = 0x7469A0
    InventorySection* getSectionOfType(AttachSlot type);// public RVA = 0x744CE0
    void getAllSectionsOfType(lektor<InventorySection*>& out, AttachSlot type);// public RVA = 0x745710
    lektor<InventorySection*>& getAllSections();// public RVA = 0xD52F0
    bool getExcessLoot(const hand& me, lektor<Item*>& out, bool justAsking);// public RVA = 0x747B30
    void getResourceItems(ogre_unordered_set<GameData*>::type& out, bool buildingMatsToo) const;// public RVA = 0x748280
    int getNumItems(GameData* itemType) const;// public RVA = 0x745030
    int getNumItems() const;// public RVA = 0x746290
    Character* getCallbackCharacter() const;// public RVA = 0x70BC80
    virtual bool addItem(Item* item, int quantity, bool dropOnFail, bool destroyOnFail);// public RVA = 0x744A70 vtable offset = 0x10
    bool _NV_addItem(Item* item, int quantity, bool dropOnFail, bool destroyOnFail);// public RVA = 0x744A70 vtable offset = 0x10
    virtual bool tryAddItem(Item* item, int quantity);// public RVA = 0x74AB10 vtable offset = 0x18
    bool _NV_tryAddItem(Item* item, int quantity);// public RVA = 0x74AB10 vtable offset = 0x18
    class HasRoomCache
    {
    public:
        std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData* const, bool> > > itemStates; // 0x0 Member
        void modified();// public RVA = 0x7589A0
        bool knowsAbout(GameData* item) const;// public RVA = 0x756920
        bool hasRoomFor(GameData* item) const;// public RVA = 0x756990
        void remember(GameData* d, bool state);// public RVA = 0x75AED0
        // no_addr void HasRoomCache(const class Inventory::HasRoomCache & _a1);// public missing arg names
        HasRoomCache();// public RVA = 0x75AF50
        HasRoomCache* _CONSTRUCTOR();// public RVA = 0x75AF50
        ~HasRoomCache();// public RVA = 0x75A1A0
        void _DESTRUCTOR();// public RVA = 0x75A1A0
        // no_addr class Inventory::HasRoomCache & operator=(const class Inventory::HasRoomCache & _a1);// public missing arg names
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    Inventory::HasRoomCache* hasRoomCache; // 0x8 Member
    virtual bool hasRoomForItem(GameData* item);// public RVA = 0x74A350 vtable offset = 0x20
    bool _NV_hasRoomForItem(GameData* item);// public RVA = 0x74A350 vtable offset = 0x20
    virtual Item* removeItemDontDestroy_returnsItem(Item* it, int howmany, bool returnCopyIfSomeLeft);// public RVA = 0x749800 vtable offset = 0x28
    Item* _NV_removeItemDontDestroy_returnsItem(Item* it, int howmany, bool returnCopyIfSomeLeft);// public RVA = 0x749800 vtable offset = 0x28
    virtual bool removeItemAutoDestroy(Item* it, int howmany);// public RVA = 0x744BD0 vtable offset = 0x30
    bool _NV_removeItemAutoDestroy(Item* it, int howmany);// public RVA = 0x744BD0 vtable offset = 0x30
    virtual void dropItem(Item* it);// public RVA = 0x744B80 vtable offset = 0x38
    void _NV_dropItem(Item* it);// public RVA = 0x744B80 vtable offset = 0x38
    bool transferMouseItem(Item* item);// public RVA = 0x744B60
    bool hasItem(GameData* item, int quantity) const;// public RVA = 0x744D60
    bool hasItem(Item* item) const;// public RVA = 0x744D20
    int countItems(GameData* item) const;// public RVA = 0x744E00
    Item* getItem(GameData* item);// public RVA = 0x744E90
    bool hasItemType(itemType item, bool skipEquipped) const;// public RVA = 0x744F20
    void getAllStolenItems(lektor<Item*>& all, bool includeUnknown);// public RVA = 0x7479B0
    bool hasStolenItems() const;// public RVA = 0x744F70
    void getAllItemsOfType(lektor<Item*>& all, itemType ty, bool skipEquipped);// public RVA = 0x7457B0
    void getEquippedWeapons(lektor<Item*>& all);// public RVA = 0x746DE0
    Weapon* getSecondaryWeapon();// public RVA = 0x746A20
    Weapon* getPrimaryWeapon();// public RVA = 0x746BF0
    void getEquippedArmour(lektor<Item*>& all);// public RVA = 0x747170
    Item* takeOneItemOnly(GameData* item);// public RVA = 0x7499E0
    bool deathCheck(Item* item);// public RVA = 0x75D5D0
    bool takeItem_EntireStack(Item* what);// public RVA = 0x749BD0
    Item* takeItem_EntireStack(GameData* item);// public RVA = 0x749B00
    bool hasItemFunction(ItemFunction type) const;// public RVA = 0x744FF0
    void getAllItemsWithFunction(lektor<Item*>& out, ItemFunction type);// public RVA = 0x745870
    Item* getBestItemWithFunction(ItemFunction type) const;// public RVA = 0x745140
    Item* getBestItemWithLowestCharges(GameData* what) const;// public RVA = 0x74A450
    Item* getBestItemWithLowestCharges(ItemFunction type) const;// public RVA = 0x745270
    Item* getBestFoodItem(Character* race) const;// public RVA = 0x5C7160
    int getNumFoodItems(Character* race) const;// public RVA = 0x334010
    Item* _getBestFoodItem(ItemFunction type, Character* race) const;// public RVA = 0x747B60
    int _getNumFoodItems(ItemFunction type, Character* race) const;// public RVA = 0x7453C0
    bool hasWeaponEquipped() const;// public RVA = 0x746160
    bool equipItem(Item* item);// public RVA = 0x74B440
    bool isAContainer() const;// public RVA = 0x744A00
    // no_addr class RootObject * getOwner();// public
    RootObject* getOwner();// public RVA = 0x14D920
    bool isEmpty() const;// public RVA = 0x7457A0
    void recalculateTotalWeight();// public RVA = 0x746230
    float getTotalWeight();// public RVA = 0x7461C0
    int getMoney() const;// public RVA = 0x744C50
    void takeMoney(int val);// public RVA = 0x744C20
    Item* buyItem(Item* itemToBuy, RootObject* sendingTo);// public RVA = 0x7494E0
    InventoryGUI* getInventoryGUI();// public RVA = 0x14D960
    bool isVisible();// public RVA = 0x14D990
    virtual void _sectionAddItemCallback(Item* item);// public RVA = 0x7463A0 vtable offset = 0x40
    void _NV__sectionAddItemCallback(Item* item);// public RVA = 0x7463A0 vtable offset = 0x40
    virtual void _sectionUpdateItemCallback(Item* _a1, int _a2);// public RVA = 0x7463D0 vtable offset = 0x48 missing arg names
    void _NV__sectionUpdateItemCallback(Item* _a1, int _a2);// public RVA = 0x7463D0 vtable offset = 0x48 missing arg names
    virtual void _sectionRemoveItemCallback(Item* item);// public RVA = 0x7463F0 vtable offset = 0x50
    void _NV__sectionRemoveItemCallback(Item* item);// public RVA = 0x7463F0 vtable offset = 0x50
    virtual void refreshGui();// public RVA = 0x744A40 vtable offset = 0x58
    void _NV_refreshGui();// public RVA = 0x744A40 vtable offset = 0x58
    void autoArrange();// public RVA = 0x746310
    RootObject* getCallbackObject();// public RVA = 0x14D930
    const lektor<Item*>& getAllItems() const;// public RVA = 0x2966D0
    virtual void _addToList(Item* item);// protected RVA = 0x7459B0 vtable offset = 0x60
    void _NV__addToList(Item* item);// protected RVA = 0x7459B0 vtable offset = 0x60
    virtual void _removeFromList(Item* item, bool checkEverything);// protected RVA = 0x7450B0 vtable offset = 0x68
    void _NV__removeFromList(Item* item, bool checkEverything);// protected RVA = 0x7450B0 vtable offset = 0x68
    lektor<Item*> _allItems; // 0x10 Member
    boost::unordered::unordered_map<std::string, InventorySection*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySection*>, Ogre::GeneralAllocPolicy > > sections; // 0x28 Member
    lektor<InventorySection*> sectionsInSearchOrder; // 0x68 Member
    RootObject* callbackObject; // 0x80 Member
    RootObject* owner; // 0x88 Member
    float totalWeight; // 0x90 Member
    // no_addr class Inventory & operator=(const class Inventory & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};