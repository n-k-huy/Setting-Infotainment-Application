#ifndef _LIST_FEATURES_
#define _LIST_FEATURES_

#include "Common.h"

template <class T>
class listFeature
{
private:
	std::vector <std::shared_ptr <T>> settingList;
public:
	listFeature();

	void setSettingList(std::vector <std::shared_ptr <T>>& list);

	std::vector <std::shared_ptr <T>> getSettingList();

	std::vector <std::shared_ptr <T>> sortFollowID();

	std::vector <std::shared_ptr <T>> sortFollowName();

	int findFollowID();

	~listFeature();
};

template<class T>
inline listFeature<T>::listFeature()
{
	settingList = {};
}

template<class T>
inline void listFeature<T>::setSettingList(std::vector<std::shared_ptr<T>>& list)
{
	settingList = list;
}

template<class T>
inline std::vector<std::shared_ptr<T>> listFeature<T>::getSettingList()
{
	return settingList;
}

template<class T>
inline std::vector<std::shared_ptr<T>> listFeature<T>::sortFollowID()
{
	std::vector <std::shared_ptr <T>> result = settingList;
	
	std::sort(result.begin(), result.end(),
		[](const std::shared_ptr<T>& a, const std::shared_ptr<T>& b)
		{
			return a->getId() < b->getId();
		});

	return result;
}

template<class T>
inline std::vector<std::shared_ptr<T>> listFeature<T>::sortFollowName()
{
	std::vector <std::shared_ptr <T>> result = settingList;

	std::sort(result.begin(), result.end(),
		[](const std::shared_ptr<T>& a, const std::shared_ptr<T>& b)
		{
			// Find the first character in name of user
			std::string name1 = a->getOwnerName();
			std::string name2 = b->getOwnerName();

			char firstAphabetName1 = name1.length() - 1;
			char firstAlphabetName2 = name2.length() - 1;

			while (name1.at(firstAphabetName1) != ' ')
				firstAphabetName1--;
			while (name2.at(firstAlphabetName2) != ' ')
				firstAlphabetName2--;

			return (name1.at(firstAphabetName1 + 1) < name2.at(firstAlphabetName2 + 1));
		});

	return result;
}

template<class T>
inline int listFeature<T>::findFollowID()
{
	// Nhap id can tim
	std::vector <int> findingId(8, 0);
	std::cout << "Moi nhap id can tim: ";
	for (int& num : findingId)
		std::cin >> num;

	auto pos = std::find_if(settingList.begin(), settingList.end(),
		[&](const std::shared_ptr<T>& car)
		{
			return car->getId() == findingId;
		});

	return static_cast<int>(std::distance(settingList.begin(), pos));
}

template<class T>
inline listFeature<T>::~listFeature()
{
}

#endif