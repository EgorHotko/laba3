#include "Student.h"
#include "container.h"
#include <iostream>
#include <vector>

using namespace std;
void show_vector(const vector<Student>&, int);
void fill_list(std::vector<Student>, List& );
Student input_student();
int err_cons_input();

int main() {
	/*Student student;
	int group,n;
	string surname;
	student.InputInformation(group, surname);
	student.SetSurname(surname);
	student.SetGroup(group);
	cout << "Information : Surname " << student.GetSurname() << " Group " << student.GetGroup() << endl; 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	Student* studentPtr;
	studentPtr = new Student;
	studentPtr -> InputInformation(group, surname);
	studentPtr -> SetSurname(surname);
	studentPtr -> SetGroup(group);
	cout << "Information : Surname " << studentPtr -> GetSurname() << " Group " << studentPtr -> GetGroup() << endl; 
	delete studentPtr;
	cout << "Input array size: ";
	n = ErrConsInput();
	try {
		if (n <= 0)
			throw "Incorrect size of array!";
		Student* students = new Student[n];
		for (int i = 0; i < n; i++) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			students[i].Fill_Element();
		}
		for (int i = 0; i < n; i++)
			students[i].Show_Element();
		delete[]students;
	}
	catch(char *str){
		cout << str << endl;
	}*/
	vector<Student> student_vct;
	cout << "Input vector size: ";
	const auto vector_length = err_cons_input();
	try {
		if (vector_length <= 0)
			throw "Incorrect size of vector!";
			for (auto i = 0; i < vector_length; i++) {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				student_vct.push_back(input_student());
			}
		//show_vector(studentVct, studentVct.size());
			cout << endl;
	}
	catch (char* str) {
		cout << str << endl;
	}
	List list;
	fill_list(student_vct, list);
	list.show_list();
	list.DeleteElement(3);
	list.show_list();
	cout << endl << endl;
	auto list2 = list;
	list2.show_list();
	system("pause");
	return 0;
}

void show_vector(const vector<Student>& student_vector, int size)
{
	for (auto i = 0; i < size; i++) {
		cout << "Surname: " << student_vector[i].GetSurname() << endl;
		cout << "Group: " << student_vector[i].GetGroup() << endl;
	}
}

Student input_student()
{
	Student vector_element;
	int group;
	string surname;
	cout << "Input information :\n";
	vector_element.InputInformation(group, surname);
	vector_element.SetSurname(surname);
	vector_element.SetGroup(group);
	return vector_element;
}
int err_cons_input() {
	int n1;
	cin >> n1;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Input error! Try again: " << endl;
		cin >> n1;
	}
	return n1;
}

void fill_list(std::vector<Student> stud,List &list)
{

	for (auto i = 0; i < stud.size(); i++) {
		list.AddElement(stud[i]);
	}
}