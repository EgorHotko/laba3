#pragma once

#include <string>

class Student {
private:
	int _group;
	std::string _surname;
public:

	int GetGroup() const;
	std::string GetSurname() const;
	void SetGroup(int);
	void SetSurname(const std::string&);

	void Fill_Element();
	void Show_Element() const;

	static void InputInformation(int &group, std::string &surname);
};