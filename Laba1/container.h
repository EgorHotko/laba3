#pragma once
#include "Student.h"


class ListItem {
public:
	Student student;
	ListItem* next;
};
class List
{
private:
	int length;
	ListItem* Head;
public:
	// TODO: getLength
	List();
	List(const List&);
	~List();
	void DeleteElement(int);
	void AddElement(const Student&);
	void show_list() const;
};