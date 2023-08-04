#include "PersonNode.h"

PersonNode::PersonNode(void) : m_name(""), m_age(0), m_next(nullptr)
{
}

PersonNode::PersonNode(const string& name, int age) : m_name(name), m_age(age), m_next(nullptr)
{
}

PersonNode::~PersonNode(void)
{
}

void PersonNode::SetAge(int age) {
	m_age = age;
}

void PersonNode::SetName(string name) {
	m_name = name;
}

int PersonNode::GetAge() {
	return m_age;
}

string PersonNode::GetName() {
	return m_name;
}

