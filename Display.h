#ifndef _DISPLAY_
#define _DISPLAY_

#include "Car_infor.h"

class Display : public Car_infor
{
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
public:
	Display();
	Display(std::string name, std::vector <int> personal_id, std::string mail, std::string odo_number, int km, int light, int screen_light, int taplo_light);
	Display(const Display& display);

	void setLightLevel(const int& light);
	void setScreenLightLevel(const int& screen_light);
	void setTaploLightLevel(const int& taplo_light);

	int getLightLevel() const;
	int getScreenLightLevel() const;
	int getTaploLightLevel() const;
	int getNUmberOfAttributes() const override;

	void input();
	void output() override;
	void printCarInfoChange() override;
	void changeDistinctProperties(int mode) override;
	void outputFormat() override;
	void outputDistinctAttribute() override;

	virtual ~Display();
};

#endif

