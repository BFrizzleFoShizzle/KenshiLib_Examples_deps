#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <mygui/MyGUI_Widget.h>
#include <kenshi/util/hand.h>

#include <string>
#include <vector>

class NewGameWindow;

namespace wraps
{
    class BaseLayout
    {
    public:
        // VTable         : (none)
        // no_addr void BaseLayout(const class wraps::BaseLayout & _a1);// public missing arg names
        BaseLayout(const std::string& _layout, MyGUI::Widget* _parent);// protected RVA = 0x11F2A0
        BaseLayout* _CONSTRUCTOR(const std::string& _layout, MyGUI::Widget* _parent);// protected RVA = 0x11F2A0
        // no_addr void BaseLayout();// protected
        void initialise(const std::string& _layout, MyGUI::Widget* _parent, bool _throw, bool _createFakeWidgets);// protected RVA = 0x119010
        void shutdown();// protected RVA = 0x115E00
        std::string FindParentPrefix(MyGUI::Widget* _parent);// private RVA = 0x116EB0
        void snapToParent(MyGUI::Widget* _child);// private RVA = 0x115F20
        MyGUI::Widget* _createFakeWidgetT(const std::string& _typeName, MyGUI::Widget* _parent);// private RVA = 0x116130
        virtual ~BaseLayout();// public RVA = 0x116390 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0x116390 vtable offset = 0x0
        MyGUI::Widget* mMainWidget; // 0x8 Member
        std::string mPrefix; // 0x10 Member
        std::string mLayoutName; // 0x38 Member
        std::vector<MyGUI::Widget*> mListWindowRoot; // 0x60 Member
        // Typedef        : VectorBasePtr
        std::vector<wraps::BaseLayout*> mListBase; // 0x80 Member
        // no_addr class wraps::BaseLayout & operator=(const class wraps::BaseLayout & _a1);// public missing arg names
        // no_addr void __local_vftable_ctor_closure();// public
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
}

class GUIWindow : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void GUIWindow(const class GUIWindow & _a1);// public missing arg names
    GUIWindow();// protected RVA = 0x6E2510
    GUIWindow* _CONSTRUCTOR();// protected RVA = 0x6E2510
    virtual ~GUIWindow();// protected RVA = 0x6E1940 vtable offset = 0x0
    void _DESTRUCTOR();// protected RVA = 0x6E1940 vtable offset = 0x0
    virtual void clear();// public RVA = 0x402A20 vtable offset = 0x8
    void _NV_clear();// public RVA = 0x402A20 vtable offset = 0x8
    virtual void show(bool _a1) = 0;// public vtable offset = 0x10 missing arg names
    virtual void setPositionReal(float x, float y);// public RVA = 0x6E19A0 vtable offset = 0x18
    void _NV_setPositionReal(float x, float y);// public RVA = 0x6E19A0 vtable offset = 0x18
    virtual void setPosition(int x, int y);// public RVA = 0x6E19C0 vtable offset = 0x20
    void _NV_setPosition(int x, int y);// public RVA = 0x6E19C0 vtable offset = 0x20
    virtual int getWidth() const;// public RVA = 0x6E19E0 vtable offset = 0x28
    int _NV_getWidth() const;// public RVA = 0x6E19E0 vtable offset = 0x28
    virtual int getHeight() const;// public RVA = 0x6E19F0 vtable offset = 0x30
    int _NV_getHeight() const;// public RVA = 0x6E19F0 vtable offset = 0x30
    virtual float getWidthReal() const;// public RVA = 0x6E1A00 vtable offset = 0x38
    float _NV_getWidthReal() const;// public RVA = 0x6E1A00 vtable offset = 0x38
    virtual float getHeightReal() const;// public RVA = 0x6E1A20 vtable offset = 0x40
    float _NV_getHeightReal() const;// public RVA = 0x6E1A20 vtable offset = 0x40
    virtual bool isVisible() const;// public RVA = 0x6E1A40 vtable offset = 0x48
    bool _NV_isVisible() const;// public RVA = 0x6E1A40 vtable offset = 0x48
    virtual void update();// public RVA = 0x6E1A90 vtable offset = 0x50
    void _NV_update();// public RVA = 0x6E1A90 vtable offset = 0x50
    virtual void autoChangeSelectedObject(const hand& obj);// public RVA = 0x6E1AA0 vtable offset = 0x58
    void _NV_autoChangeSelectedObject(const hand& obj);// public RVA = 0x6E1AA0 vtable offset = 0x58
    MyGUI::Widget* getWidget();// public RVA = 0x6E1AD0
    virtual void resize(int w, int h);// public RVA = 0x6E1AE0 vtable offset = 0x60
    void _NV_resize(int w, int h);// public RVA = 0x6E1AE0 vtable offset = 0x60
    MyGUI::Widget* win; // 0x8 Member
    hand selectedObject; // 0x10 Member
    // no_addr class GUIWindow & operator=(const class GUIWindow & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// protected vtable offset = 0x0 missing arg names
};

class TitleScreen : public GUIWindow, public wraps::BaseLayout
{
public:
    // GUIWindow offset = 0x0, length = 0x30
    // wraps::BaseLayout offset = 0x30, length = 0xA0
    static TitleScreen* getSingleton();// public RVA = 0x911620
    // no_addr void TitleScreen(const class TitleScreen & _a1);// public missing arg names
    TitleScreen();// public RVA = 0x917740
    TitleScreen* _CONSTRUCTOR();// public RVA = 0x917740
    virtual ~TitleScreen();// public RVA = 0x9125C0 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x9125C0 vtable offset = 0x0
    virtual void clear();// public RVA = 0x911680 vtable offset = 0x0
    void _NV_clear();// public RVA = 0x911680 vtable offset = 0x0
    virtual void show(bool on);// public RVA = 0x9116D0 vtable offset = 0x0
    void _NV_show(bool on);// public RVA = 0x9116D0 vtable offset = 0x0
    virtual void update();// public RVA = 0x9120D0 vtable offset = 0x0
    void _NV_update();// public RVA = 0x9120D0 vtable offset = 0x0
    bool closeTheOtherBits();// public RVA = 0x9132E0
    void loadGame(MyGUI::Widget* _sender);// private RVA = 0x913650
    void importGame(MyGUI::Widget* _sender);// private RVA = 0x913760
    void showOptions(MyGUI::Widget* _sender);// private RVA = 0x913870
    void credits(MyGUI::Widget* _sender);// private RVA = 0x913980
    void exitGame(MyGUI::Widget* _sender);// private RVA = 0x9139D0
    // no_addr void newGame(class MyGUI::Widget * _a1);// private missing arg names
    void continueGame(MyGUI::Widget* _sender);// private RVA = 0x913490
    void hover(MyGUI::Widget* _sender, MyGUI::Widget* _a2);// private RVA = 0x911690
    void setCreditsVisible(bool value);// private RVA = 0x912A80
    NewGameWindow* newGameWindow; // 0xD0 Member
    MyGUI::Widget* creditsPanel; // 0xD8 Member
    MyGUI::TextBox* creditsText; // 0xE0 Member
    bool creditsLoaded; // 0xE8 Member
    float creditsPosition; // 0xEC Member
    // no_addr class TitleScreen & operator=(const class TitleScreen & _a1);// public missing arg names
    // no_addr void __local_vftable_ctor_closure();// public
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};