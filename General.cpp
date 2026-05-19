#include "General.h"

General::General() : Car_infor()
{
    time_zone = "";
    language = "";
}

General::General(std::string name, std::vector <int> personal_id, std::string mail, std::string odo_number, int km, std::string timeZone, std::string lang) : Car_infor(name, personal_id, mail, odo_number, km)
{
    setTimezone(timeZone);
    setLanguage(lang);
}

General::General(const General& general) : Car_infor(general)
{
    setTimezone(general.time_zone);
    setLanguage(general.language);
}

void General::setTimezone(const std::string& timeZone)
{
    time_zone = timeZone;
}

void General::setLanguage(const std::string& lang)
{
    language = lang;
}

std::string General::getTimezone() const
{
    return time_zone;
}

std::string General::getLanguage() const
{
    return language;
}

int General::getNUmberOfAttributes() const
{
    return 7;
}

int inputLanguage(std::vector <std::string>& language)
{
    int chooseLanguage;
    do
    {
        outputLanguage(language);
        std::cout << "CHOOSE YOUR LANGUAGE: ";
        std::cin >> chooseLanguage;

        // KT du lieu dau vao
        if (chooseLanguage <= 0 || chooseLanguage > language.size())
        {
            std::cout << "WRONG CHOICE. PLEASE INPUT AGAIN" << std::endl;
            system("pause");
            std::cin.ignore(1);
            system("cls");
        }
    } while (chooseLanguage <= 0 || chooseLanguage > language.size());

    system("cls");
    return chooseLanguage;
}

int inputTimezone(std::vector <std::string>& timezone)
{
    int chooseTimeZone;
    do
    {
        outputTimeZone(timezone);
        std::cout << "CHOOSE YOUR TIME ZONE: ";
        std::cin >> chooseTimeZone;

        // KT du lieu dau vao
        if (chooseTimeZone <= 0 || chooseTimeZone > timezone.size())
        {
            std::cout << "WRONG CHOICE. PLEASE INPUT AGAIN" << std::endl;
            system("pause");
            std::cin.ignore(1);
            system("cls");
        }
    } while (chooseTimeZone <= 0 || chooseTimeZone > timezone.size());

    system("cls");
    return chooseTimeZone;
}

void General::input()
{
    Car_infor::input();     // Nhap cac thong so chung
    system("cls");

    // Nhap time zone
    std::vector <std::string> timezone = downloadTimeZone();
    int chooseTimezone = inputTimezone(timezone);

    // Nhap language
    std::vector <std::string> languages = downloadLanguage();
    int chooseLanguage = inputLanguage(languages);

    // Luu du lieu
    setTimezone(timezone[chooseTimezone - 1]);
    setLanguage(languages[chooseLanguage - 1]);
}

void General::output()
{
    std::cout << std::left << std::setw(20) << getOwnerName();  // Name

    std::string id;
    for (const int& val : getId())
        id += std::to_string(val);
    std::cout << std::left << std::setw(15) << id;              // Id

    std::cout << std::left << std::setw(30) << getEmail();      // Email
    std::cout << std::left << std::setw(15) << getOdo();        // Odo
    std::cout << std::left << std::setw(20) << std::to_string(getServiceRemind());      // Service remind

    std::cout << std::left << std::setw(50) << getTimezone();       // Time zone
    std::cout << std::left << std::setw(20) << getLanguage();       // Language
}

void General::printCarInfoChange()
{
    Car_infor::printCarInfoChange();

    std::cout << "6/ Language" << std::endl;
    std::cout << "7/ Time Zone" << std::endl;
    std::cout << "8/ Go back" << std::endl;
    std::cout << "9/ Exit" << std::endl;
}

void General::changeDistinctProperties(int mode)
{
    switch (mode)
    {
        case 6:
        {
            // Chon ngon ngu
            std::vector <std::string> languages = downloadLanguage();
            int chooseLanguage = inputLanguage(languages);
            setLanguage(languages[chooseLanguage - 1]);

            break;
        }
        case 7:
        {
            // Chon vung
            std::vector <std::string> timezone = downloadTimeZone();
            int chooseTimezone = inputLanguage(timezone);
            setTimezone(timezone[chooseTimezone - 1]);

            break;
        }
    }

    std::cin.ignore(1);
}

void General::outputFormat()
{
    Car_infor::outputFormat();

    std::cout << std::left << std::setw(50) << "TIME ZONE";			// Time zone
    std::cout << std::left << std::setw(20) << "LANGUAGE";          // Language

    std::cout << std::endl;
}

void General::outputDistinctAttribute()
{
    std::cout << std::left << std::setw(50) << getTimezone();       // Time zone
    std::cout << std::left << std::setw(20) << getLanguage();       // Language
}

General::~General()
{
}
