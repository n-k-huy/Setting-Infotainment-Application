#ifndef _LIST_FEATURES_
#define _LIST_FEATURES_

#include "Common.h"

bool compareID(const std::vector <int>& id1, const std::vector <int>& id2)
{
	return (id1 < id2);
}

bool compareName(const std::string& name1, const std::string& name2)
{
	// Find the first character in name of user
	char firstAphabetName1 = name1.length() - 1;
	char firstAlphabetName2 = name2.length() - 1;

	while (name1.at(firstAphabetName1) != ' ')
		firstAphabetName1--;
	while (name2.at(firstAlphabetName2) != ' ')
		firstAlphabetName2--;

	return (name1.at(firstAphabetName1 + 1) < name2.at(firstAlphabetName2 + 1));
}

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
	
	std::sort(result.begin(), result.end(), compareID);

	return result;
}

template<class T>
inline std::vector<std::shared_ptr<T>> listFeature<T>::sortFollowName()
{
	std::vector <std::shared_ptr <T>> result = settingList;

	std::sort(result.begin(), result.end(), compareName);

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

	std::vector <int>::iterator pos = std::find(settingList.begin(), settingList.end(), findingId);

	return pos;
}

template<class T>
inline listFeature<T>::~listFeature()
{
}

#endif