#ifndef _SETTING_
#define _SETTING_

#include "Common.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"
#include "listFeature.h"

std::string chooseModeToChangeCarInfo(char mode, int order, std::vector <std::shared_ptr <Car_infor>>& carInfor);

bool checkDataCar(std::vector <std::shared_ptr <Car_infor>> carInfor);

void outputInforCar(const std::vector <std::shared_ptr <Car_infor>>& carInfor);

void menu();	// Giao dien tong quat

void settingMenu();	// Giao dien Cai dat du lieu xe

void printSettingMenu();	// Giao dien xuat du lieu xe da duoc cai dat

void chooseSettingMenu(listFeature <Car_infor>& display, listFeature <Car_infor>& sound, listFeature <Car_infor>& general);

void choosePrintSettingMenu(listFeature <Car_infor>& display, listFeature <Car_infor>& sound, listFeature <Car_infor>& general);

void chooseSortModeMenu(listFeature <Car_infor>& display, listFeature <Car_infor>& sound, listFeature <Car_infor>& general);

void chooseMenu(listFeature <Car_infor>& display, listFeature <Car_infor>& sound, listFeature <Car_infor>& general);

#endif