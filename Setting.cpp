#include "Setting.h"

bool validInput(std::string input, int numberOfMode, char mode)
{
	// '1' <= input <= '9'
	// mode = 1, input = 10 => exit
	// mode = 2, input = 10 => Go back
	//			 input = 11 => Exit
	// mode = 3, input = 9 => Exit

	if (input.length() > 1)
	{
		if ((mode == '1' && input == "10") || (mode == '2' && (input == "10" || input == "11")))
			return true;
		else return false;
	}
	else if (input[0] < '0' || input[0] > ('0' + numberOfMode + 1))
	{
		if (mode == '3')
		{
			if (input == "9")
				return true;
		}
		return false;
	}

	return true;
}

std::string chooseModeToChangeCarInfo(char mode, int order, std::vector<std::shared_ptr<Car_infor>>& carInfor)
{
	std::string changeMode;
	int numberOfMode = carInfor[order - 1]->getNUmberOfAttributes();	// Lay so luong thuoc tinh xe
	bool isValidInput;
	do
	{
		// In thong tin thuoc tinh can thay doi
		carInfor[order - 1]->printCarInfoChange();
		

		// Nguoi dung chon mode thay doi thong tin xe
		std::cout << "MOI LUA CHON THONG TIN CAN THAY DOI: ";
		std::getline(std::cin, changeMode);

		isValidInput = validInput(changeMode, numberOfMode, mode);
		if (isValidInput == false)
		{
			std::cout << "NHAP SAI VUI LONG NHAP LAI." << std::endl;
			system("pause");
			system("cls");
		}
	} while (isValidInput == false);

	return changeMode;
}

bool checkDataCar(std::vector<std::shared_ptr<Car_infor>> carInfor)
{
	return carInfor.empty();
}

void outputInforCar(const std::vector<std::shared_ptr<Car_infor>>& carInfor)
{
	for (int index = 0; index < carInfor.size(); index++)
	{
		std::cout << index + 1 << std::left << std::setw(5) << ".";
		carInfor[index]->output();
		std::cout << std::endl;
	}
}

void menu()
{
	std::cout << "-------SELECT MENU-----------" << std::endl;
	std::cout << " 1/ Input Setting Information" << std::endl;
	std::cout << " 2/ Print Setting Information" << std::endl;
	std::cout << " 3/ Sort Setting Information" << std::endl;
	std::cout << " 4/ Exits" << std::endl;
	std::cout << "MOI NHAP LUA CHON: ";
}

void settingMenu()
{
	std::cout << "-------SELECT MENU-----------" << std::endl;
	std::cout << " 1/ Display Setting" << std::endl;
	std::cout << " 2/ Sound Setting" << std::endl;
	std::cout << " 3/ General Setting" << std::endl;
	std::cout << " 4/ Go back" << std::endl;
	std::cout << "MOI NHAP LUA CHON: ";
}

void printSettingMenu()
{
	std::cout << "-------SELECT MENU-----------" << std::endl;
	std::cout << " 1/ Print Display Setting Information" << std::endl;
	std::cout << " 2/ Print Sound Setting Information" << std::endl;
	std::cout << " 3/ Print General Setting Information" << std::endl;
	std::cout << " 4/ Print All Setting Information" << std::endl;
	std::cout << " 5/ Go back" << std::endl;
	std::cout << "MOI NHAP LUA CHON: ";
}

void printSortModeMenu()
{
	std::cout << "-------SELECT MENU-----------" << std::endl;
	std::cout << " 1/ Sort follow ID" << std::endl;
	std::cout << " 2/ Sort follow name" << std::endl;
	std::cout << " 3/ Go back" << std::endl;
	std::cout << "MOI NHAP LUA CHON: ";
}

int inputOrderCar(const std::vector <std::shared_ptr <Car_infor>>& carInfo)
{
	system("cls");
	outputInforCar(carInfo);
	std::cout << "MOI BAN CHON XE MUON THAY DOI THONG TIN: ";

	// Bat buoc ban phim nhap la ban phim so
	int orderCar;
	std::cin >> orderCar;
	std::cin.ignore(1);		// Bo Enter
	system("cls");

	return orderCar;
}

void chooseSettingMenu(listFeature <Car_infor>& display, listFeature <Car_infor>& sound, listFeature <Car_infor>& general)
{
	// Take setting info
	auto dis_infor = display.getSettingList();
	auto sound_info = sound.getSettingList();
	auto general_info = general.getSettingList();

	std::string chooseMode;
	char wantToChooseMore = 'Y';

	// Chon menu
	while (wantToChooseMore == 'Y' || wantToChooseMore == 'y')
	{
		// Nhap du lieu cho nguoi dung
		do
		{
			// Hien thi menu cho nguoi dung
			settingMenu();

			// Nguoi dung nhap du lieu
			std::getline(std::cin, chooseMode);

			// Dua ra thong bao nguoi dung nhap sai
			if (chooseMode.length() > 1 || chooseMode[0] < '0' || chooseMode[0] > ('0' + NUMBER_SETTING_MENU_MODE))
			{
				std::cout << "NHAP SAI. VUI LONG NHAP LAI." << std::endl;
				system("pause");
				system("cls");
			}


		} while (chooseMode.length() > 1 || chooseMode[0] < '0' || chooseMode[0] > ('0' + NUMBER_SETTING_MENU_MODE));

		// Kiem tra du lieu ton tai trong mang
		bool check_display_data = checkDataCar(dis_infor);
		bool check_sound_data = checkDataCar(sound_info);
		bool check_general_data = checkDataCar(general_info);

		// Lua chon Mode
		switch (chooseMode[0])
		{
			case '1':
			{
				// Kiem tra du lieu Display
				if (check_display_data == false)
				{
					// In thong tin xe
					outputInforCar(dis_infor);

					// Hoi nguoi dung co muon thay doi thong tin xe 
					char changingCarInfo;
					std::cout << "BAN CO MUON THAY DOI THONG TIN XE? (Y/N): ";
					std::cin >> changingCarInfo;
					std::cin.ignore(1);		// Bo Enter

					// Thay doi thong tin xe
					while (changingCarInfo == 'Y' || changingCarInfo == 'y')
					{
						int orderCar = inputOrderCar(dis_infor);

						// Lua chon thuoc tinh de thay doi
						std::string changeMode = chooseModeToChangeCarInfo(chooseMode[0], orderCar, dis_infor);
						int numberOfMode = dis_infor[0]->getNUmberOfAttributes();		// La tong so luong thuoc tinh xe

						// Thay doi thuoc tinh theo tuong ung changeMode
						int mode = stoi(changeMode);
						switch (mode)
						{
							case 1:
							{
								std::cout << "NHAP TEN MOI: ";
								std::string owner_name;
								std::getline(std::cin, owner_name);
								dis_infor[orderCar - 1]->setOwnerName(owner_name);
								break;
							}
							case 2:
							{
								std::cout << "NHAP ID MOI: ";
								std::vector <int> id(8, 0);
								for (int& val : id)
									std::cin >> val;
								std::cin.ignore(1);		// Bo Enter
								dis_infor[orderCar - 1]->setId(id);
								break;
							}
							case 3:
							{
								std::cout << "NHAP EMAIL MOI: ";
								std::string email;
								std::getline(std::cin, email);
								dis_infor[orderCar - 1]->setEmail(email);
								break;
							}
							case 4:
							{
								std::cout << "NHAP ODO MOI: ";
								std::string odo;
								std::getline(std::cin, odo);
								dis_infor[orderCar - 1]->setOdo(odo);
								break;
							}
							case 5:
							{
								std::cout << "NHAP SERVICE REMIND MOI: ";
								int service_remind;
								std::cin >> service_remind;
								std::cin.ignore(1);		// Bo Enter
								dis_infor[orderCar - 1]->setServiceRemind(service_remind);
								break;
							}
							case 6:
							case 7:
							case 8:
							{
								dis_infor[orderCar - 1]->changeDistinctProperties(mode);
								break;
							}
							case 9:
							{
								system("cls");
								return chooseSettingMenu(display, sound, general);
							}
							default:
							{
								return;
							}
						}

						// Hoi nguoi dung co muon thay doi tiep khong
						std::cout << "BAN CO MUON THAY DOI THEM THUOC TINH XE? (Y/N): ";
						std::cin >> changingCarInfo;
						std::cin.ignore(1);		// Bo Enter
						system("cls");
					}
				}
				else
				{
					std::cout << "CHUA CO DU LIEU CHO DISPLAY." << std::endl;
					system("pause");
					system("cls");
				}
				
				// Cai dat thong tin cho display
				char addMore = 'y';
				while (addMore == 'Y' || addMore == 'y')
				{
					std::cout << "NHAP DU LIEU DISPLAY CHO XE MOI" << std::endl;
					std::shared_ptr <Car_infor> display(std::make_shared <Display>());
					display->input();
					dis_infor.push_back(display);
					system("cls");

					// Hoi nguoi dung co muon them Display moi nua hay khong
					std::cout << "BAN CO MUON THEM DU LIEU DISPLAY MOI KHONG? (Y/N): ";
					std::cin >> addMore;
					std::cin.ignore(1);			// Bo qua Enter
				}

				break;
			}
			case '2':
			{
				// Kiem tra du lieu Display
				if (check_sound_data == false)
				{
					// In thong tin xe
					outputInforCar(sound_info);

					// Hoi nguoi dung co muon thay doi thong tin xe 
					char changingCarInfo;
					std::cout << "BAN CO MUON THAY DOI THONG TIN XE? (Y/N): ";
					std::cin >> changingCarInfo;
					std::cin.ignore(1);		// Bo Enter

					// Thay doi thong tin xe
					while (changingCarInfo == 'Y' || changingCarInfo == 'y')
					{
						int orderCar = inputOrderCar(sound_info);

						// Lua chon thuoc tinh de thay doi
						std::string changeMode = chooseModeToChangeCarInfo(chooseMode[0], orderCar, sound_info);
						int numberOfMode = sound_info[0]->getNUmberOfAttributes();		// La tong so luong thuoc tinh xe

						// Thay doi thuoc tinh theo tuong ung changeMode
						int mode = stoi(changeMode);
						switch (mode)
						{
							case 1:
							{
								std::cout << "NHAP TEN MOI: ";
								std::string owner_name;
								std::getline(std::cin, owner_name);
								sound_info[orderCar - 1]->setOwnerName(owner_name);
								break;
							}
							case 2:
							{
								std::cout << "NHAP ID MOI: ";
								std::vector <int> id(8, 0);
								for (int& val : id)
									std::cin >> val;
								std::cin.ignore(1);		// Bo Enter
								sound_info[orderCar - 1]->setId(id);
								break;
							}
							case 3:
							{
								std::cout << "NHAP EMAIL MOI: ";
								std::string email;
								std::getline(std::cin, email);
								sound_info[orderCar - 1]->setEmail(email);
								break;
							}
							case 4:
							{
								std::cout << "NHAP ODO MOI: ";
								std::string odo;
								std::getline(std::cin, odo);
								sound_info[orderCar - 1]->setOdo(odo);
								break;
							}
							case 5:
							{
								std::cout << "NHAP SERVICE REMIND MOI: ";
								int service_remind;
								std::cin >> service_remind;
								std::cin.ignore(1);		// Bo Enter
								sound_info[orderCar - 1]->setServiceRemind(service_remind);
								break;
							}
							case 6:
							case 7:
							case 8:
							case 9:
							{
								sound_info[orderCar - 1]->changeDistinctProperties(mode);
								break;
							}
							case 10:
							{
								system("cls");
								return chooseSettingMenu(display, sound, general);
							}
							default:
							{
								return;
							}
						}

						// Hoi nguoi dung co muon thay doi tiep khong
						std::cout << "BAN CO MUON THAY DOI THEM THUOC TINH XE? (Y/N): ";
						std::cin >> changingCarInfo;
						std::cin.ignore(1);		// Bo Enter
						system("cls");
					}
				}
				else
				{
					std::cout << "CHUA CO DU LIEU CHO SOUND." << std::endl;
					system("pause");
					system("cls");
				}

				// Cai dat thong tin cho display
				char addMore = 'y';
				while (addMore == 'Y' || addMore == 'y')
				{
					std::cout << "NHAP DU LIEU SOUND CHO XE MOI" << std::endl;
					std::shared_ptr <Car_infor> sound(std::make_shared <Sound>());
					sound->input();
					sound_info.push_back(sound);
					system("cls");

					// Hoi nguoi dung co muon them Sound moi nua hay khong
					std::cout << "BAN CO MUON THEM DU LIEU SOUND MOI KHONG? (Y/N): ";
					std::cin >> addMore;
					std::cin.ignore(1);			// Bo qua Enter
				}

				break;
			}
			case '3':
			{
				// Kiem tra du lieu Display
				if (check_general_data == false)
				{
					// In thong tin xe
					outputInforCar(general_info);

					// Hoi nguoi dung co muon thay doi thong tin xe 
					char changingCarInfo;
					std::cout << "BAN CO MUON THAY DOI THONG TIN XE? (Y/N): ";
					std::cin >> changingCarInfo;
					std::cin.ignore(1);		// Bo Enter

					// Thay doi thong tin xe
					while (changingCarInfo == 'Y' || changingCarInfo == 'y')
					{
						int orderCar = inputOrderCar(general_info);

						// Lua chon thuoc tinh de thay doi
						std::string changeMode = chooseModeToChangeCarInfo(chooseMode[0], orderCar, general_info);
						int numberOfMode = general_info[0]->getNUmberOfAttributes();		// La tong so luong thuoc tinh xe

						// Thay doi thuoc tinh theo tuong ung changeMode
						int mode = stoi(changeMode);
						switch (mode)
						{
							case 1:
							{
								std::cout << "NHAP TEN MOI: ";
								std::string owner_name;
								std::getline(std::cin, owner_name);
								general_info[orderCar - 1]->setOwnerName(owner_name);
								break;
							}
							case 2:
							{
								std::cout << "NHAP ID MOI: ";
								std::vector <int> id(8, 0);
								for (int& val : id)
									std::cin >> val;
								std::cin.ignore(1);		// Bo Enter
								general_info[orderCar - 1]->setId(id);
								break;
							}
							case 3:
							{
								std::cout << "NHAP EMAIL MOI: ";
								std::string email;
								std::getline(std::cin, email);
								general_info[orderCar - 1]->setEmail(email);
								break;
							}
							case 4:
							{
								std::cout << "NHAP ODO MOI: ";
								std::string odo;
								std::getline(std::cin, odo);
								general_info[orderCar - 1]->setOdo(odo);
								break;
							}
							case 5:
							{
								std::cout << "NHAP SERVICE REMIND MOI: ";
								int service_remind;
								std::cin >> service_remind;
								std::cin.ignore(1);		// Bo Enter
								general_info[orderCar - 1]->setServiceRemind(service_remind);
								break;
							}
							case 6:
							case 7:
							{
								general_info[orderCar - 1]->changeDistinctProperties(mode);
								break;
							}
							case 8:
							{
								system("cls");
								return chooseSettingMenu(display, sound, general);
							}
							default:
							{
								return;
							}
						}

						// Hoi nguoi dung co muon thay doi tiep khong
						std::cout << "BAN CO MUON THAY DOI THEM THUOC TINH XE? (Y/N): ";
						std::cin >> changingCarInfo;
						std::cin.ignore(1);		// Bo Enter
						system("cls");
					}
				}
				else
				{
					std::cout << "CHUA CO DU LIEU CHO GENERAL." << std::endl;
					system("pause");
					system("cls");
				}

				// Cai dat thong tin cho display
				char addMore = 'y';
				while (addMore == 'Y' || addMore == 'y')
				{
					std::cout << "NHAP DU LIEU GENERAL CHO XE MOI" << std::endl;
					std::shared_ptr <Car_infor> general(std::make_shared <General>());
					general->input();
					general_info.push_back(general);
					system("cls");

					// Hoi nguoi dung co muon them Sound moi nua hay khong
					std::cout << "BAN CO MUON THEM DU LIEU GENERAL MOI KHONG? (Y/N): ";
					std::cin >> addMore;
					std::cin.ignore(1);			// Bo qua Enter
				}

				break;
			}
			case ('0' + NUMBER_SETTING_MENU_MODE):
			{
				system("cls");
				chooseMenu(display, sound, general);
			}
		}
	}

	display.setSettingList(dis_infor);
	sound.setSettingList(sound_info);
	general.setSettingList(general_info);
}

void choosePrintSettingMenu(listFeature <Car_infor>& display, listFeature <Car_infor>& sound, listFeature <Car_infor>& general)
{
	// Take setting info
	auto dis_infor = display.getSettingList();
	auto sound_info = sound.getSettingList();
	auto general_info = general.getSettingList();

	std::string chooseMode;
	char wantToChooseMore = 'Y';

	// Chon menu
	while (wantToChooseMore == 'Y' || wantToChooseMore == 'y')
	{
		// Nhap du lieu cho nguoi dung
		do
		{
			// Hien thi menu cho nguoi dung
			printSettingMenu();

			// Nguoi dung nhap du lieu
			std::getline(std::cin, chooseMode);

			// Dua ra thong bao nguoi dung nhap sai
			if (chooseMode.length() > 1 || chooseMode[0] < '0' || chooseMode[0] > ('0' + NUMBER_PRINT_SETTING_MENU_MODE))
			{
				std::cout << "NHAP SAI. VUI LONG NHAP LAI." << std::endl;
				system("pause");
				system("cls");
				std::cin.ignore(1);
			}


		} while (chooseMode.length() > 1 || chooseMode[0] < '0' || chooseMode[0] > ('0' + NUMBER_PRINT_SETTING_MENU_MODE));

		// Lua chon Mode
		system("cls");
		switch (chooseMode[0])
		{
			case '1':
			{
				// STT	OWNER NAME	ID	ODO	SERVICE REMIND	LIGHT	SCREEN LIGHT	TAPLO LIGHT
				try
				{
					dis_infor.at(0)->outputFormat();
				}
				catch (const std::out_of_range& e)
				{
					std::cout << "Exception: " << e.what() << std::endl;
				}
				outputInforCar(dis_infor);

				system("pause");
				system("cls");

				break;
			}
			case '2':
			{
				// STT	OWNER NAME	ID	ODO	SERVICE REMIND	MEDIA	CALL	NAVIGATION	NOTIFICATION
				try
				{
					sound_info.at(0)->outputFormat();
				}
				catch (const std::out_of_range& e)
				{
					std::cout << e.what() << std::endl;
				}
				outputInforCar(sound_info);

				system("pause");
				system("cls");

				break;
			}
			case '3':
			{
				// STT	OWNER NAME	ID	ODO	SERVICE REMIND	TIME ZONE	LANGUAGE
				try
				{
					general_info.at(0)->outputFormat();
				}
				catch (const std::out_of_range& e)
				{
					std::cout << e.what() << std::endl;
				}
				outputInforCar(general_info);

				system("pause");
				system("cls");

				break;
			}
			case '4':
			{
				try
				{
					std::cout << std::left << std::setw(6) << "STT";			// STT
					std::cout << std::left << std::setw(20) << "OWNER NAME";  // Name
					std::cout << std::left << std::setw(15) << "ID";              // Id
					std::cout << std::left << std::setw(30) << "EMAIL";      // Email
					std::cout << std::left << std::setw(15) << "ODO";        // Odo
					std::cout << std::left << std::setw(20) << "SERVICE REMIND";      // Service remind

					std::cout << std::left << std::setw(20) << "LIGHT";			// Light level
					std::cout << std::left << std::setw(20) << "SCREEN LIGHT";      // Screen light level
					std::cout << std::left << std::setw(20) << "TAPLO LIGHT";      // Taplo 

					std::cout << std::left << std::setw(20) << "MEDIA";			// Media volumn level
					std::cout << std::left << std::setw(20) << "CALL";      // Call volumn level
					std::cout << std::left << std::setw(20) << "NAVIGATION";      // Navigation volumn level
					std::cout << std::left << std::setw(20) << "NOTIFICATION";      // Notification volumn level

					std::cout << std::left << std::setw(50) << "TIME ZONE";			// Time zone
					std::cout << std::left << std::setw(20) << "LANGUAGE";          // Language

					std::cout << std::endl;

					for (int index = 0; index < dis_infor.size(); index++)
					{
						std::cout << index + 1 << std::left << std::setw(5) << ".";

						std::cout << std::left << std::setw(20) << dis_infor.at(index)->getOwnerName();  // Name

						std::string id;
						for (const int& val : dis_infor.at(index)->getId())
							id += std::to_string(val);
						std::cout << std::left << std::setw(15) << id;              // Id

						std::cout << std::left << std::setw(30) << dis_infor.at(index)->getEmail();      // Email
						std::cout << std::left << std::setw(15) << dis_infor.at(index)->getOdo();        // Odo
						std::cout << std::left << std::setw(20) << std::to_string(dis_infor.at(index)->getServiceRemind());      // Service remind

						dis_infor.at(index)->outputDistinctAttribute();
						sound_info.at(index)->outputDistinctAttribute();
						general_info.at(index)->outputDistinctAttribute();

						std::cout << std::endl;
					}
				}
				catch (const std::out_of_range& e)
				{
					std::cout << e.what() << std::endl;
				}

				system("pause");
				system("cls");

				break;
			}
			case ('0' + NUMBER_PRINT_SETTING_MENU_MODE):
			{
				return chooseMenu(display, sound, general);
			}
		}
	}
}

void chooseSortModeMenu(listFeature <Car_infor>& display, listFeature <Car_infor>& sound, listFeature <Car_infor>& general)
{
	std::string chooseMode;
	char wantToChooseMore = 'Y';

	// Chon menu
	while (wantToChooseMore == 'Y' || wantToChooseMore == 'y')
	{
		// Nhap du lieu cho nguoi dung
		do
		{
			// Hien thi menu cho nguoi dung
			printSortModeMenu();

			// Nguoi dung nhap du lieu
			std::getline(std::cin, chooseMode);

			// Dua ra thong bao nguoi dung nhap sai
			if (chooseMode.length() > 1 || chooseMode[0] < '0' || chooseMode[0] > ('0' + NUMBER_SORT_MENU_MODE))
			{
				std::cout << "NHAP SAI. VUI LONG NHAP LAI." << std::endl;
				system("pause");
				system("cls");
				std::cin.ignore(1);
			}


		} while (chooseMode.length() > 1 || chooseMode[0] < '0' || chooseMode[0] > ('0' + NUMBER_SORT_MENU_MODE));

		// Lua chon Mode
		system("cls");
		switch (chooseMode[0])
		{
			case '1':
			{
				auto dis_info = display.sortFollowID();
				auto sound_info = sound.sortFollowID();
				auto general_info = general.sortFollowID();

				outputInforCar(dis_info);
				std::cout << std::endl;
				outputInforCar(sound_info);
				std::cout << std::endl;
				outputInforCar(general_info);
				std::cout << std::endl;

				break;
			}
			case '2':
			{
				auto dis_info = display.sortFollowName();
				auto sound_info = sound.sortFollowName();
				auto general_info = general.sortFollowName();

				outputInforCar(dis_info);
				std::cout << std::endl;
				outputInforCar(sound_info);
				std::cout << std::endl;
				outputInforCar(general_info);
				std::cout << std::endl;

				break;
			}
			case ('0' + NUMBER_SORT_MENU_MODE):
			{
				return chooseMenu(display, sound, general);
			}
		}
	}
}

void chooseMenu(listFeature <Car_infor>& display, listFeature <Car_infor>& sound, listFeature <Car_infor>& general)
{
	std::string chooseMode;
	char wantToChooseMore = 'Y';

	// Chon menu
	while (wantToChooseMore == 'Y' || wantToChooseMore == 'y')
	{
		// Nhap du lieu cho nguoi dung
		do
		{
			// Hien thi menu cho nguoi dung
			menu();

			// Nguoi dung nhap du lieu
			std::getline(std::cin, chooseMode);

			// Dua ra thong bao nguoi dung nhap sai
			if (chooseMode.length() > 1 || chooseMode[0] < '0' || chooseMode[0] > ('0' + NUMBER_MENU_MODE))
			{
				std::cout << "NHAP SAI. VUI LONG NHAP LAI." << std::endl;
				system("pause");
				system("cls");
			}


		} while (chooseMode.length() > 1 || chooseMode[0] < '0' || chooseMode[0] > ('0' + NUMBER_MENU_MODE));

		// Lua chon Mode
		system("cls");
		switch (chooseMode[0])
		{
			case '1':
			{
				chooseSettingMenu(display, sound, general);
				break;
			}
			case '2':
			{
				choosePrintSettingMenu(display, sound, general);
				break;
			}
			case '3':
			{
				chooseSortModeMenu(display, sound, general);
				break;
			}
			case ('0' + NUMBER_MENU_MODE):
			{
				// Hoi nguoi dung co muon lua chon tiep khong
				std::cout << "BAN CO MUON LUA CHON TIEP? (Y/N): ";
				std::cin >> wantToChooseMore;
				std::cin.ignore(1);		// Bo Enter
				break;
			}
		}
	}

	// Ket thuc chuong trinh
	system("cls");
	std::cout << "CAM ON DA SU DUNG!" << std::endl;
	std::exit(0);
}