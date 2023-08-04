#pragma once

#include <string>
using namespace std;

class PersonNode
{
	friend class AddressBookSLL;
public:
	PersonNode(void);
	PersonNode(const string& name, int age);
	~PersonNode(void);

	void SetName(string name);
	void SetAge(int age);
	int GetAge();
	string GetName();

private:
	string m_name;
	int m_age;
	PersonNode* m_next;
};
