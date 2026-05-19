#include "Car_infor.h"

Car_infor::Car_infor()
{
    owner_name = "Unknown";
    id = std::vector <int>(8, 0);
    email = "Unknown";
    odo = "Unknown";
    service_remind = 0;
}

Car_infor::Car_infor(std::string name, std::vector<int> personal_id, std::string mail, std::string odo_number, int km)
{
    setOwnerName(name);
    setId(personal_id);
    setEmail(mail);
    setOdo(odo_number);
    setServiceRemind(km);
}

Car_infor::Car_infor(const Car_infor& car_infor)
{
    setOwnerName(car_infor.owner_name);
    setId(car_infor.id);
    setEmail(car_infor.email);
    setOdo(car_infor.odo);
    setServiceRemind(car_infor.service_remind);
}

void Car_infor::setOwnerName(const std::string& name)
{
    owner_name = name;
}

void Car_infor::setId(const std::vector<int>& id_number)
{
    id = id_number;
}

void Car_infor::setEmail(const std::string& mail)
{
    email = mail;
}

void Car_infor::setOdo(const std::string& odo_number)
{
    odo = odo_number;
}

void Car_infor::setServiceRemind(const int& km)
{
    service_remind = km;
}

std::string Car_infor::getOwnerName() const
{
    return owner_name;
}

std::vector<int> Car_infor::getId() const
{
    return id;
}

std::string Car_infor::getEmail() const
{
    return email;
}

std::string Car_infor::getOdo() const
{
    return odo;
}

int Car_infor::getServiceRemind() const
{
    return service_remind;
}

void Car_infor::input()
{
    // Nhap ten
    std::string name;
    std::cout << "INPUT NAME: ";
    getline(std::cin, name);

    // Nhap id
    std::vector <int> personal_id(8, 0);
    std::cout << "INPUT ID: ";
    for (int& val : personal_id)
        std::cin >> val;
    std::cin.ignore(1);

    // Nhap email
    std::string mail;
    std::cout << "INPUT EMAIL: ";
    getline(std::cin, mail);

    // Nhap odo
    std::string odo_number;
    std::cout << "INPUT ODO: ";
    getline(std::cin, odo_number);

    // Nhap service remind
    int km;
    std::cout << "INPUT SERVICE REMIND: ";
    std::cin >> km;

    // Luu gia tri
    setOwnerName(name);
    setId(personal_id);
    setEmail(mail);
    setOdo(odo_number);
    setServiceRemind(km);
}

void Car_infor::printCarInfoChange()
{
    std::cout << "1/ Owner Name" << std::endl;
    std::cout << "2/ ID" << std::endl;
    std::cout << "3/ Email" << std::endl;
    std::cout << "4/ ODO" << std::endl;
    std::cout << "5/ Service Remind" << std::endl;
}

void Car_infor::outputFormat()
{
    std::cout << std::left << std::setw(6) << "STT";			// STT
    std::cout << std::left << std::setw(20) << "OWNER NAME";  // Name
    std::cout << std::left << std::setw(15) << "ID";              // Id
    std::cout << std::left << std::setw(30) << "EMAIL";      // Email
    std::cout << std::left << std::setw(15) << "ODO";        // Odo
    std::cout << std::left << std::setw(20) << "SERVICE REMIND";      // Service remind
}

Car_infor::~Car_infor()
{
}
