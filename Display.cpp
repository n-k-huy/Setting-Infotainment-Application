#include "Display.h"

Display::Display() : Car_infor()
{
    light_level = 0;
    screen_light_level = 0;
    taplo_light_level = 0;
}

Display::Display(std::string name, std::vector <int> personal_id, std::string mail, std::string odo_number, int km, int light, int screen_light, int taplo_light) : Car_infor(name, personal_id, mail, odo_number, km)
{
    setLightLevel(light);
    setScreenLightLevel(screen_light);
    setTaploLightLevel(taplo_light);
}

Display::Display(const Display& display) : Car_infor(display)
{
    setLightLevel(display.light_level);
    setScreenLightLevel(display.screen_light_level);
    setTaploLightLevel(display.taplo_light_level);
}

void Display::setLightLevel(const int& light)
{
    if (light < 0)
        light_level = 0;
    else light_level = light;
}

void Display::setScreenLightLevel(const int& screen_light)
{
    if (screen_light < 0)
        screen_light_level = 0;
    else screen_light_level = screen_light;
}

void Display::setTaploLightLevel(const int& taplo_light)
{
    if (taplo_light < 0)
        taplo_light_level = 0;
    else taplo_light_level = taplo_light;
}

int Display::getLightLevel() const
{
    return light_level;
}

int Display::getScreenLightLevel() const
{
    return screen_light_level;
}

int Display::getTaploLightLevel() const
{
    return taplo_light_level;
}

int Display::getNUmberOfAttributes() const
{
    return 8;
}

// Ban phim nhap la ban phim so
void Display::input()
{
    Car_infor::input();     // Nhap cac thong so chung

    // Nhap light level
    int light;
    std::cout << "INPUT LIGHT LEVEL: ";
    std::cin >> light;

    // Nhap Screen light level
    int screen_light;
    std::cout << "INPUT SCREEN LIGHT LEVEL: ";
    std::cin >> screen_light;

    // Nhap Taplo light level
    int taplo_light;
    std::cout << "INPUT TAPLO LIGHT LEVEL: ";
    std::cin >> taplo_light;

    // Luu du lieu
    setLightLevel(light);
    setScreenLightLevel(screen_light);
    setTaploLightLevel(taplo_light);
}

void Display::output()
{
    std::cout << std::left << std::setw(20) << getOwnerName();  // Name

    std::string id;
    for (const int& val : getId())
        id += std::to_string(val);
    std::cout << std::left << std::setw(15) << id;              // Id

    std::cout << std::left << std::setw(30) << getEmail();      // Email
    std::cout << std::left << std::setw(15) << getOdo();        // Odo
    std::cout << std::left << std::setw(20) << std::to_string(getServiceRemind());      // Service remind

    std::cout << std::left << std::setw(20) << std::to_string(getLightLevel());      // Light level
    std::cout << std::left << std::setw(20) << std::to_string(getScreenLightLevel());      // Screen light level
    std::cout << std::left << std::setw(20) << std::to_string(getTaploLightLevel());      // Taplo light level
}

void Display::printCarInfoChange()
{
    Car_infor::printCarInfoChange();

    std::cout << "6/ Light Level" << std::endl;
    std::cout << "7/ Screen Light Level" << std::endl;
    std::cout << "8/ Taplo Light Level" << std::endl;
    std::cout << "9/ Go back" << std::endl;
    std::cout << "10/ Exit" << std::endl;
}

void Display::changeDistinctProperties(int mode)
{
    switch (mode)
    {
        case 6:
        {
            std::cout << "NHAP LIGHT MOI: ";
            int light;
            std::cin >> light;
            setLightLevel(light);
            break;
        }
        case 7:
        {
            std::cout << "NHAP SCREEN LIGHT MOI: ";
            int screen;
            std::cin >> screen;
            setScreenLightLevel(screen);
            break;
        }
        case 8:
        {
            std::cout << "NHAP TAPLO LIGHT MOI: ";
            int taplo;
            std::cin >> taplo;
            setTaploLightLevel(taplo);
            break;
        }
    }
    std::cin.ignore(1);		// Bo Enter
}

void Display::outputFormat()
{
    Car_infor::outputFormat();

    std::cout << std::left << std::setw(20) << "LIGHT";			// Light level
    std::cout << std::left << std::setw(20) << "SCREEN LIGHT";      // Screen light level
    std::cout << std::left << std::setw(20) << "TAPLO LIGHT";      // Taplo 

    std::cout << std::endl;
}

void Display::outputDistinctAttribute()
{
    std::cout << std::left << std::setw(20) << std::to_string(getLightLevel());      // Light level
    std::cout << std::left << std::setw(20) << std::to_string(getScreenLightLevel());      // Screen light level
    std::cout << std::left << std::setw(20) << std::to_string(getTaploLightLevel());      // Taplo light level
}

Display::~Display()
{
}
