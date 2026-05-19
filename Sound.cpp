#include "Sound.h"

Sound::Sound() : Car_infor()
{
    media_volume_level = 0;
    call_volume_level = 0;
    navigation_volume_level = 0;
    notification_volume_level = 0;
}

Sound::Sound(std::string name, std::vector <int> personal_id, std::string mail, std::string odo_number, int km, int media_volume, int call_volume, int navigation_volume, int notification_volume) : Car_infor(name, personal_id, mail, odo_number, km)
{
    setMediaVolumeLevel(media_volume);
    setCallVolumeLevel(call_volume);
    setNavigationVolumeLevel(navigation_volume);
    setNotificationVolumeLevel(notification_volume);
}

Sound::Sound(const Sound& sound) : Car_infor(sound)
{
    setMediaVolumeLevel(sound.media_volume_level);
    setCallVolumeLevel(sound.call_volume_level);
    setNavigationVolumeLevel(sound.navigation_volume_level);
    setNotificationVolumeLevel(sound.notification_volume_level);
}

void Sound::setMediaVolumeLevel(const int& media_volume)
{
    if (media_volume < 0)
        media_volume_level = 0;
    else media_volume_level = media_volume;
}

void Sound::setCallVolumeLevel(const int& call_volume)
{
    if (call_volume < 0)
        call_volume_level = 0;
    else call_volume_level = call_volume;
}

void Sound::setNavigationVolumeLevel(const int& navigation_volume)
{
    if (navigation_volume < 0)
        navigation_volume_level = 0;
    else navigation_volume_level = navigation_volume;
}

void Sound::setNotificationVolumeLevel(const int& notification_volume)
{
    if (notification_volume < 0)
        notification_volume_level = 0;
    else notification_volume_level = notification_volume;
}

int Sound::getNUmberOfAttributes() const
{
    return 9;
}

int Sound::getMediaVolumeLevel() const
{
    return media_volume_level;
}

int Sound::getCallVolumeLevel() const
{
    return call_volume_level;
}

int Sound::getNavigationVolumeLevel() const
{
    return navigation_volume_level;
}

int Sound::getNotificationVolumeLevel() const
{
    return notification_volume_level;
}

// Ban phim nhap la ban phim so
void Sound::input()
{
    Car_infor::input();     // Nhap cac thong so chung

    // Nhap Media volume level
    int media_volume;
    std::cout << "INPUT MEDIA VOLUME LEVEL: ";
    std::cin >> media_volume;

    // Nhap Call volume level
    int call_volume;
    std::cout << "INPUT CALL VOLUME LEVEL: ";
    std::cin >> call_volume;

    // Nhap Navigation volume level
    int navigation_volume;
    std::cout << "INPUT NAVIGATION VOLUME LEVEL: ";
    std::cin >> navigation_volume;

    // Nhap Notification volume Level
    int notification_volume;
    std::cout << "INPUT NOTIFICATION VOLUME LEVEL: ";
    std::cin >> notification_volume;

    // Luu du lieu
    setMediaVolumeLevel(media_volume);
    setCallVolumeLevel(call_volume);
    setNavigationVolumeLevel(navigation_volume);
    setNotificationVolumeLevel(notification_volume);
}

void Sound::output()
{
    std::cout << std::left << std::setw(20) << getOwnerName();  // Name

    std::string id;
    for (const int& val : getId())
        id += std::to_string(val);
    std::cout << std::left << std::setw(15) << id;              // Id

    std::cout << std::left << std::setw(30) << getEmail();      // Email
    std::cout << std::left << std::setw(15) << getOdo();        // Odo
    std::cout << std::left << std::setw(20) << std::to_string(getServiceRemind());      // Service remind

    std::cout << std::left << std::setw(20) << std::to_string(getMediaVolumeLevel());      // Media volume level
    std::cout << std::left << std::setw(20) << std::to_string(getCallVolumeLevel());      // Call volume level
    std::cout << std::left << std::setw(20) << std::to_string(getNavigationVolumeLevel());      // Navigation volume level
    std::cout << std::left << std::setw(20) << std::to_string(getNotificationVolumeLevel());      // Notification volume level
}

void Sound::printCarInfoChange()
{
    Car_infor::printCarInfoChange();
    
    std::cout << "6/ Media Volumn Level" << std::endl;
    std::cout << "7/ Call Volumn Level" << std::endl;
    std::cout << "8/ Navigation Volumn Level" << std::endl;
    std::cout << "9/ Notification Volumn Level" << std::endl;
    std::cout << "10/ Go back" << std::endl;
    std::cout << "11/ Exit" << std::endl;
}

void Sound::changeDistinctProperties(int mode)
{
    switch (mode)
    {
        case 6:
        {
            std::cout << "NHAP MEDIA VOLUMN MOI: ";
            int media;
            std::cin >> media;
            setMediaVolumeLevel(media);
            break;
        }
        case 7:
        {
            std::cout << "NHAP CALL VOLUMN MOI: ";
            int call;
            std::cin >> call;
            setCallVolumeLevel(call);
            break;
        }
        case 8:
        {
            std::cout << "NHAP NAVIGATION VOLUMN MOI: ";
            int navigation;
            std::cin >> navigation;
            setNavigationVolumeLevel(navigation);
            break;
        }
        case 9:
        {
            std::cout << "NHAP NOTIFICATION VOLUMN MOI: ";
            int notification;
            std::cin >> notification;
            setNotificationVolumeLevel(notification);
            break;
        }
    }

    std::cin.ignore(1);
}

void Sound::outputFormat()
{
    Car_infor::outputFormat();

    std::cout << std::left << std::setw(20) << "MEDIA";			// Media volumn level
    std::cout << std::left << std::setw(20) << "CALL";      // Call volumn level
    std::cout << std::left << std::setw(20) << "NAVIGATION";      // Navigation volumn level
    std::cout << std::left << std::setw(20) << "NOTIFICATION";      // Notification volumn level

    std::cout << std::endl;
}

void Sound::outputDistinctAttribute()
{
    std::cout << std::left << std::setw(20) << std::to_string(getMediaVolumeLevel());      // Media volume level
    std::cout << std::left << std::setw(20) << std::to_string(getCallVolumeLevel());      // Call volume level
    std::cout << std::left << std::setw(20) << std::to_string(getNavigationVolumeLevel());      // Navigation volume level
    std::cout << std::left << std::setw(20) << std::to_string(getNotificationVolumeLevel());      // Notification volume level
}

Sound::~Sound()
{
}
