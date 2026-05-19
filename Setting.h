#ifndef _SETTING_
#define _SETTING_

#include "Common.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"

std::string chooseModeToChangeCarInfo(char mode, int order, std::vector <std::shared_ptr <Car_infor>>& carInfor);

bool checkDataCar(std::vector <std::shared_ptr <Car_infor>> carInfor);

void outputInforCar(const std::vector <std::shared_ptr <Car_infor>>& carInfor);

void menu();	// Giao dien tong quat

void settingMenu();	// Giao dien Cai dat du lieu xe

void printSettingMenu();	// Giao dien xuat du lieu xe da duoc cai dat

void chooseSettingMenu(std::vector <std::shared_ptr<Car_infor>>& dis_infor, std::vector <std::shared_ptr<Car_infor>>& sound_info, std::vector <std::shared_ptr<Car_infor>>& general_info);

void choosePrintSettingMenu(std::vector <std::shared_ptr<Car_infor>>& dis_infor, std::vector <std::shared_ptr<Car_infor>>& sound_info, std::vector <std::shared_ptr<Car_infor>>& general_info);

void chooseMenu(std::vector <std::shared_ptr<Car_infor>>& dis_infor, std::vector <std::shared_ptr<Car_infor>>& sound_info, std::vector <std::shared_ptr<Car_infor>>& general_info);

#endif