#include "AddressBookSLL.h"
#include <iostream>

AddressBookSLL::AddressBookSLL(void) : m_head(nullptr)
{
}

AddressBookSLL::~AddressBookSLL(void)
{
	while (m_head->m_next != nullptr) {
		PersonNode* previous = m_head;
		PersonNode* current = m_head;
		while (current->m_next != nullptr)
		{
			previous = current;
			current = current->m_next;
		}
		delete current;
		previous->m_next = nullptr;
	}
	delete m_head;
	m_head = nullptr;
}

void AddressBookSLL::addPerson(const string& name, int age) {
	if (m_head == nullptr) {
		m_head = new PersonNode(name, age);
	}
	else if (m_head != nullptr && m_head->m_next == nullptr) {
		m_head->m_next = new PersonNode(name, age);
	}
	else {
		PersonNode* currentNode = m_head;
		while (currentNode->m_next != nullptr) {
			currentNode = currentNode->m_next;
		}
		currentNode->m_next = new PersonNode(name, age);
	}
}

const PersonNode* AddressBookSLL::findPerson(const string& name) const {
	PersonNode* currentNode = m_head;
	if (currentNode == nullptr) {
		return nullptr;
	}
	else {
		while (true) {
			if (currentNode->GetName() == name) {
				return currentNode;
			}
			else if (currentNode->m_next == nullptr) {
				return nullptr;
			}
			else {
				currentNode = currentNode->m_next;
			}
		}
	}
}

bool AddressBookSLL::deletePerson(const string& name) {
	const PersonNode* person = findPerson(name);
	if (person == nullptr) {
		return false;
	}
	else {
		delete person;
		return true;
	}
}

void AddressBookSLL::writeBook() {
	PersonNode* currentNode = m_head;
	while (currentNode != nullptr) {
		cout << "Name: " << currentNode->GetName() << " // Age: " << currentNode->GetAge() << endl;
		currentNode = currentNode->m_next;
	}
}