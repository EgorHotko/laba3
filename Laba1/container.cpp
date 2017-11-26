#include "container.h"
#include <iostream>

List::List()
{
	Head = nullptr;
	length = 0;
}
List::List(const List& list) {
	this->~List();
	std::cout << "Copy constructor:\n";
	this->Head = nullptr;
	this->length = 0;
	for (auto i = 0; i < list.length - 1; i++) {
		if (this->Head == nullptr) {
			ListItem* buffer = new ListItem;
			buffer->student = list.Head->student;
			Head = buffer;
			buffer->next = Head;
			this->length++;
		}
		ListItem* temp = this->Head;
		ListItem* pointer = list.Head->next;
		for (auto j = 0; j < i; j++) {
			temp = temp->next;
			pointer = pointer->next;
		}
		ListItem* buffer = new ListItem;
		buffer->student = pointer->student;
		temp->next = buffer;
		buffer->next = Head;
		this->length++;
	}
}

List::~List()
{
	for (auto i = 1; i < this->length; i++) {
		ListItem* temp = Head->next;
		delete Head;
		Head = temp;
	}
	delete Head;
}

void List::DeleteElement(int num_element)
{
	ListItem *temp = Head, *prev = Head;
	if (num_element == 1) {
		temp = Head->next;
		delete Head;
		Head = temp;
		length--;
		return;
	}
	for (auto i = 1; i < num_element; i++) {
		prev = temp;
		temp = temp->next;
	}
		prev->next = temp->next;
		delete temp;
		length--;
}

void List::AddElement(const Student& stud)
{
	if (Head == nullptr) {
		ListItem* element = new ListItem;
		element->student = stud;
		element->next = Head;
		Head = element;
		length++;
		return;
	}
	ListItem* temp = Head;
	for (auto i = 1; i < length; i++)
		temp = temp->next;
	ListItem* element = new ListItem;
	element->student = stud;
	element->next = Head;
	temp->next = element;
	length++;
}

void List::show_list() const
{
	ListItem *temp = Head;
	for (auto i = 0; i < length; i++) {
		temp->student.Show_Element();
		temp = temp->next;
	}
	std::cout << std::endl;
}
