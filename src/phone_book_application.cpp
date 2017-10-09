/*
 * phone_book_application.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Jeka
 */

#include "contact.h"
#include <iostream>
#include <fstream>


using namespace std;

void openFile(string, int&, int&, Contact*&);
void usePhoneBook(Contact*&, int&, int&);
void addNewContactToBook(Contact*&, int&, int&);
void searchForPerson(string, Contact*, int);
void print(Contact&);
void printList(Contact*, int);
void deleteContact(string, Contact*&, int&, int&);


int main(){

	int size = 0;
	int amount = 0;
	Contact* phBook = NULL;
	openFile("phonebook.txt", size, amount, phBook);
	usePhoneBook(phBook, size, amount);

	return 0;
}

void openFile(string nameOfFile, int& size, int& amount, Contact*& phBook){
	ifstream myfile;
	myfile.open (nameOfFile);

	amount = 0;

	if (myfile.is_open()) {   // check if we can open the file

		//count the lines so we will know the size of array
		string line;
		while (getline(myfile, line)){
				amount++;
		}
	}

	myfile.close();

	size = amount + amount/2;
	phBook = new Contact [size];

	myfile.open (nameOfFile);
	if (myfile.is_open()) {
		string contactItem;
		Contact* currentContact = phBook;

		while (!myfile.eof()){
			myfile >> *currentContact;

			currentContact++;
		}
	}
	else{
		cout<<"can not find file phonebook.txt"<<endl;
	}
}

void usePhoneBook(Contact*& phBook, int& size, int& numberOfContacts){

	cout << "***MY	PHONEBOOK	APPLICATION***" << endl;
	char choice;

	while(choice != 'Q') {
		cout << endl;
		cout << "Please	choose	an	operation:" << endl;
		cout << "A (Add) | S (Search)	| D(Delete) | L(List) | Q(Quit):";
		cin >> choice;
		choice = toupper(choice);
		switch (choice){
			case 'A':
				addNewContactToBook(phBook, size, numberOfContacts);
				break;
			case 'S':
			    {
					string nameToSearch;
					cout << "Enter first or last name:";
					cin >> nameToSearch;

					int nameLength = nameToSearch.size();
					for (int i = 0; i < nameLength; i++)
					{
						nameToSearch[i] = toupper(nameToSearch[i]);
					}

					searchForPerson(nameToSearch, phBook, numberOfContacts);
			    }
				break;
			case 'D':
				{
					string numberToDelete;
					cout << "Enter contact number:";
					cin >> numberToDelete;
					deleteContact(numberToDelete, phBook, size, numberOfContacts);
				}
				break;
			case 'L':
				printList(phBook, numberOfContacts);
				break;
			case'Q':
				break;
			default:
				cout << "invalid input. try again" << endl;
				break;
		}

	}
}

void addNewContactToBook(Contact*& phBook, int& size, int& amount){
	Contact newContact;
	string input;
	cout << "Enter first name:";
	cin >> input;
	int nameLength = input.size();
	for (int i = 0; i < nameLength; i++)
	{
		input[i] = toupper(input[i]);
	}
	newContact.setFirstName(input);
	cout << "Enter last name:";
	cin >> input;
	for (int i = 0; i < nameLength; i++)
	{
		input[i] = toupper(input[i]);
	}
	newContact.setLastName(input);
	cout << "Enter phone number:";
	cin >> input;
	newContact.setNumber(input);
	amount ++;

	Contact* newBook;

	int oldSize = size;

	//extend size if needed
	if (amount == size){
		size += size/2;
	}

	//rewrite array
	newBook = new Contact [size];
	for(int i = 0; i < oldSize; i++){
		newBook[i] = phBook[i];
	}

	newBook[amount - 1] = newContact;

	delete[] phBook;
	phBook = newBook;
}

void print(Contact& c) {
	cout << c.firstName << " " << c.lastName << " " << c.phoneNumber << std::endl;
}

void searchForPerson(string nameToSearch, Contact* phBook, int numberOfContacts){
	int count = 0;
	for(int i = 0; i < numberOfContacts; i++){
		if (phBook[i].getFirstName() == nameToSearch ||
		    phBook[i].getLastName() == nameToSearch) {
			print(phBook[i]);
			count++;
		}
	}
	if(count == 0){
		cout << "contact not found" << endl;
	}
}

void printList(Contact* phBook, int numberOfContacts) {
	for(int i = 0; i < numberOfContacts; i++){
		print(phBook[i]);
	}
}

void deleteContact(string numberToDelete, Contact*& phBook, int& size, int& numberOfContacts){

	Contact* itemToDelete = phBook;
	Contact* lastItem = &phBook[numberOfContacts-1];
	bool found = false;
	for(int i = 0; i < numberOfContacts; i++){
			if (itemToDelete -> getNumber() == numberToDelete) {
				itemToDelete -> setFirstName(lastItem->getFirstName());
				itemToDelete -> setLastName(lastItem->getLastName());
				itemToDelete -> setNumber(lastItem->getNumber());
				numberOfContacts--;
				cout << "contact was deleted" << endl;
				found = true;
			}
			itemToDelete++;
	}
	if(!found){
		cout << "contact not found" << endl;
	}
}
