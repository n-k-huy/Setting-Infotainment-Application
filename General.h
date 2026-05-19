#ifndef _GENERAL_
#define _GENERAL_

#include "Car_infor.h"

class General : public Car_infor
{
private:
	std::string time_zone;
	std::string language;
public:
	General();
	General(std::string name, std::vector <int> personal_id, std::string mail, std::string odo_number, int km, std::string timeZone, std::string lang);
	General(const General& general);

	void setTimezone(const std::string& timeZone);
	void setLanguage(const std::string& lang);

	std::string getTimezone() const;
	std::string getLanguage() const;
	int getNUmberOfAttributes() const override;

	void input();
	void output() override;
	void printCarInfoChange() override;
	void changeDistinctProperties(int mode) override;
	void outputFormat() override;
	void outputDistinctAttribute() override;

	virtual ~General();
};

#endif

