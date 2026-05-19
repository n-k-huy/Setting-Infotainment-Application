#ifndef _CAR_INFOR_
#define _CAR_INFOR_

#include "Common.h"

class Car_infor
{
private:
	std::string owner_name;
	std::vector <int> id;		// 8 so
	std::string email;			// abcd@gmail.def
	std::string odo;			// Chu so
	int service_remind;
public:
	Car_infor();
	Car_infor(std::string name, std::vector <int> personal_id, std::string mail, std::string odo_number, int km);
	Car_infor(const Car_infor& car_infor);
	
	void setOwnerName(const std::string& name);
	void setId(const std::vector <int>& id_number);
	void setEmail(const std::string& mail);
	void setOdo(const std::string& odo_number);
	void setServiceRemind(const int& km);

	std::string getOwnerName() const;
	std::vector <int> getId() const;
	std::string getEmail() const;
	std::string getOdo() const;
	int getServiceRemind() const;
	virtual int getNUmberOfAttributes() const = 0;

	virtual void input();
	virtual void output() = 0;
	virtual void printCarInfoChange();
	virtual void changeDistinctProperties(int mode) = 0;
	virtual void outputFormat();
	virtual void outputDistinctAttribute() = 0;

	virtual ~Car_infor();
};

#endif