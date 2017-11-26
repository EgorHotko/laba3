#include "Student.h"
#include <iostream>
using namespace std;
int Student::GetGroup() const
{
	return _group;
}

std::string Student::GetSurname() const 
{
	return _surname;
}

void Student::SetGroup(int group)
{
	_group = group;
}

void Student::SetSurname(const string& surname)
{
	_surname = surname;

}

void Student::Fill_Element()
{
	int group;
	string surname;
	InputInformation(group, surname);
	SetSurname(surname);
	SetGroup(group);
}

void Student::Show_Element() const
{ 
		cout << "Information :\n  Surname " << GetSurname() << " Group " << GetGroup() << endl;
}
void Student::InputInformation(int &group, std::string &surname)
{
	cout << "Input surname: ";
	getline(cin, surname);
	cout << "Input group: ";
	cin >> group;
}