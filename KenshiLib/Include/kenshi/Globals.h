#pragma once

class Item;
class GameWorld;
class GlobalConstants;
class InputHandler;
class OptionsHolder;

void  showErrorMessage();// RVA = 0x5CC110
float modMedicalSkill(float skill, Item* equipment, float frameTIME);// RVA = 0x4FC9E0

__declspec(dllimport) GameWorld* ou;
__declspec(dllimport) GlobalConstants* con;
__declspec(dllimport) InputHandler* key;
__declspec(dllimport) OptionsHolder* options;