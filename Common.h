#ifndef _COMMON_
#define _COMMON_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <memory>
#include <algorithm>

#define NUMBER_MENU_MODE 4
#define NUMBER_SETTING_MENU_MODE 4
#define NUMBER_PRINT_SETTING_MENU_MODE 5
#define NUMBER_SORT_MENU_MODE 3

std::vector <std::string> downloadTimeZone();

std::vector <std::string> downloadLanguage();

void outputTimeZone(const std::vector <std::string>& timezone);

void outputLanguage(const std::vector <std::string>& language);

#endif

