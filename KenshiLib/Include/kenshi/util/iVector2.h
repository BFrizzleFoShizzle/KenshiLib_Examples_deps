#pragma once

#include <string>

class iVector2
{
public:
	iVector2(int, int);// RVA = 0x2BB630
	iVector2();// RVA = 0xFEB00
	int x; // 0x0 Member
	int y; // 0x4 Member
	bool operator==(const iVector2&);// RVA = 0x2D53B0
	bool operator!=(const iVector2&);// RVA = 0x2D53D0
	int getLinearValue();// RVA = 0x2E6520
	bool operator<(const iVector2&);// RVA = 0x2E6530
	std::string getAsString();// RVA = 0x93300
	iVector2 operator+(const iVector2&);// RVA = 0x300150
};