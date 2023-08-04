#pragma once

#include "PersonNode.h"

class AddressBookSLL
{
public:
	AddressBookSLL(void);
	~AddressBookSLL(void);

	void addPerson(const string& name, int age);
	const PersonNode* findPerson(const string& name) const;
	bool deletePerson(const string& name);
	void writeBook();

private:
	PersonNode* m_head;
};
