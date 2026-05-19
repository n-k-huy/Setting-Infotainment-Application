#ifndef _SOUND_
#define _SOUND_

#include "Car_infor.h"

class Sound : public Car_infor
{
private:
	int media_volume_level;
	int call_volume_level;
	int navigation_volume_level;
	int notification_volume_level;
public:
	Sound();
	Sound(std::string name, std::vector <int> personal_id, std::string mail, std::string odo_number, int km, int media_volume, int call_volume, int navigation_volume, int notification_volume);
	Sound(const Sound& sound);

	void setMediaVolumeLevel(const int& media_volume);
	void setCallVolumeLevel(const int& call_volume);
	void setNavigationVolumeLevel(const int& navigation_volume);
	void setNotificationVolumeLevel(const int& notification_volume);
	int getNUmberOfAttributes() const override;

	int getMediaVolumeLevel() const;  
	int getCallVolumeLevel() const;
	int getNavigationVolumeLevel() const;
	int getNotificationVolumeLevel() const;

	void input();
	void output() override;
	void printCarInfoChange() override;
	void changeDistinctProperties(int mode) override;
	void outputFormat() override;
	void outputDistinctAttribute() override;

	virtual ~Sound();
};

#endif

