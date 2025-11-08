#pragma once

#include <string>

class iVector2
{
public:
    iVector2(int _x, int _y);// public RVA = 0x37E3C0
    iVector2* _CONSTRUCTOR(int _x, int _y);// public RVA = 0x37E3C0
    iVector2();// public RVA = 0x15A860
    iVector2* _CONSTRUCTOR();// public RVA = 0x15A860
    int x; // 0x0 Member
    int y; // 0x4 Member
    bool operator==(const iVector2& a) const;// public RVA = 0x39DD00
    bool operator!=(const iVector2& a) const;// public RVA = 0x39DD20
    int getLinearValue() const;// public RVA = 0x3B3020
    bool operator<(const iVector2& rhs) const;// public RVA = 0x3B3030
    std::string getAsString() const;// public RVA = 0xD4600
    iVector2 operator+(const iVector2& other) const;// public RVA = 0x3D2C40
};