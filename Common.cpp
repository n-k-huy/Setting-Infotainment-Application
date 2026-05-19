#include "Common.h"

std::vector<std::string> downloadTimeZone()
{
    std::vector <std::string> result;

    // Mo file
    std::fstream timeZone;
    timeZone.open("TimeZone.txt", std::ios::in);

    // Lay du lieu tu file
    if (timeZone.is_open() == true)
    {
        std::string line;
        while (getline(timeZone, line))
            result.push_back(line);
        timeZone.close();
    }
    return result;
}

std::vector<std::string> downloadLanguage()
{
    std::vector <std::string> result;

    // Mo file
    std::fstream language;
    language.open("Language.txt", std::ios::in);

    // Lay du lieu tu file
    if (language.is_open() == true)
    {
        std::string line;
        while (getline(language, line))
            result.push_back(line);
        language.close();
    }
    return result;
}

void outputTimeZone(const std::vector<std::string>& timezone)
{
    // 1/ (GMT-12:00) International Date Line West
    for (int index = 0; index < timezone.size(); index++)
        std::cout << index + 1 << "/ " << timezone[index] << std::endl;
}

void outputLanguage(const std::vector<std::string>& language)
{
    // 1/ Mandarin
    for (int index = 0; index < language.size(); index++)
        std::cout << index + 1 << "/ " << language[index] << std::endl;
}
