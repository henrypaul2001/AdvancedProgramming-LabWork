
#include <iostream>
using namespace std;
#include "AddressBookSLL.h"

/*
	This program will act as a Contacts Address Book using a Single Linked Lists
*/

int main(int argc, char **argv) {

	AddressBookSLL book;

	book.addPerson("Henry", 20);
	book.addPerson("Louis", 19);
	book.addPerson("Billy", 11);
	book.addPerson("Natalia", 5);

	book.writeBook();

	const PersonNode* finderptr = book.findPerson("Billy");
	book.deletePerson("Billy");

	system("PAUSE");
}