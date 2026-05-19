#include "Setting.h"
#include "listFeature.h"

listFeature <Car_infor> display;
listFeature <Car_infor> sound;
listFeature <Car_infor> general;

std::string takeDataString(std::string& inputString, int begin, int end)
{
	// Move to position to take data inputString
	while (inputString[begin] != ' ')
		begin++;

	std::string result = inputString.substr(begin + 1, end - begin);

	return result;
}

void seperateDataString(std::string& inputString, std::vector <std::string>& result)
{
	int first = 0;
	while (first < inputString.length())
	{
		int second = first;

		// Move Second pointer to pos that has '/'
		while (inputString[second] != '/' && second < inputString.length())
			second++;

		std::string data;

		// Take data from '/' go back
		if (second == inputString.length() - 1)
			data = inputString.substr(first, second + 1 - first);
		else data = inputString.substr(first, second - first);

		result.push_back(data);

		// Update first pointer
		first = second + 1;
	}
}

int main()
{
	// Data Display, Sound, General
	std::vector <std::shared_ptr <Car_infor>> dispalySetting = display.getSettingList();
	std::vector <std::shared_ptr <Car_infor>> soundSetting = sound.getSettingList();
	std::vector <std::shared_ptr <Car_infor>> generalSetting = general.getSettingList();

	// Open file data
	std::fstream settingFile;

	try
	{
		settingFile.open("Setting.txt", std::ios::in);

		if (settingFile.is_open() == false)
			throw "Fail to open file";
	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
	}

	// Take data from file
	std::string line;
	while (getline(settingFile, line))
	{
		// Store info in vector
		std::vector <std::string> basic_info;		// EX: kim huy/nguyenhuy@gmail.com/12345678/4567/5000
													//	   Name/Email/Id/Odo/Service_remind
		std::vector <std::string> lightLevel;		// EX: 1/2/3
													//	   Light/Screen/Taplo
		std::vector <std::string> volumeLevel;		// EX: 1/2/3/4
													//	   Media/Call/Navigation/Notification
		std::vector <std::string> general_info;		// EX: Vietnamese/(GMT+07:00) Bangkok, Hanoi, Jakarta
													//	   Language/Timezone

		// Read the data from file
		
		// Find the position of each info
		// Take respective data string
		// Seperate each data info from each respective data string
		int displayPos = line.find("Display");
		int soundPos = line.find("Sound");
		int generalPos = line.find("General");

		std::string commonData = takeDataString(line, 0, displayPos - 2);		// Take data string
		seperateDataString(commonData, basic_info);								// Separate data string

		std::string displayData = takeDataString(line, displayPos, soundPos - 2);
		seperateDataString(displayData, lightLevel);

		std::string soundData = takeDataString(line, soundPos, generalPos - 2);
		seperateDataString(soundData, volumeLevel);

		std::string generalData = takeDataString(line, generalPos, line.size() - 1);
		seperateDataString(generalData, general_info);

		// Put data into respective object
		
		// Change datatype to suitable with datatype object
		std::vector <int> id(8, 0);										// ID
		std::string id_info = basic_info[2];
		for (int index = 0; index < id_info.length(); index++)
			id[index] = id_info[index] - '0';

		int service_remind = stoi(basic_info[basic_info.size() - 1]);	// Service remind

		std::vector <int> light(3, 0);									// Light Level
		for (int index = 0; index < light.size(); index++)
			light[index] = stoi(lightLevel[index]);
		
		std::vector <int> volume(4, 0);									// Volume level
		for (int index = 0; index < volume.size(); index++)
			volume[index] = stoi(volumeLevel[index]);

		std::string name = basic_info[0];
		std::string email = basic_info[1];
		std::string odo = basic_info[3];

		int light_level = light[0];
		int screen_light_level = light[1];
		int taplo_light_level = light[2];

		int media = volume[0];
		int call = volume[1];
		int navigation = volume[2];
		int notification = volume[3];

		std::string language = general_info[0];
		std::string timezone = general_info[1];

		// Put data into respective object 
		std::shared_ptr <Car_infor> display = std::make_shared <Display>(name, id, email, odo, service_remind, light_level, screen_light_level, taplo_light_level);		// Display
		std::shared_ptr <Car_infor> sound = std::make_shared <Sound>(name, id, email, odo, service_remind, media, call, navigation, notification);	  // Sound
		std::shared_ptr <Car_infor> general = std::make_shared <General>(name, id, email, odo, service_remind, timezone, language);		// General

		// Put into vector result
		dispalySetting.push_back(display);
		soundSetting.push_back(sound);
		generalSetting.push_back(general);
	}

	// chooseMenu(dispalySetting, soundSetting, generalSetting);

	display.setSettingList(dispalySetting);
	sound.setSettingList(soundSetting);
	general.setSettingList(generalSetting);

	auto result = display.sortFollowID();

	for (auto& ele : result)
	{
		ele->output();
	}

	return 1;
}