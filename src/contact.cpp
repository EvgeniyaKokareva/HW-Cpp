/*
 * contact.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Jeka
 */

#include "contact.h"
#include <iostream>

using namespace std;

Contact::Contact(string fn, string ln, string number){
	firstName = fn;
	lastName = ln;
	phoneNumber = number;
}

void Contact::setFirstName(string fn){
	firstName = fn;
}

void Contact::setLastName(string ln){
	lastName = ln;
}

void Contact::setNumber(string number){
	phoneNumber = number;
}

string Contact::getFirstName(){
	return firstName;
}

string Contact::getLastName(){
	return lastName;
}

string Contact::getNumber(){
	return phoneNumber;
}

istream& operator>> (istream& iStream, Contact& contact)
{
	string item;
	iStream >> item;

	contact.setFirstName(item);
	iStream >> item;

	contact.setLastName(item);
	iStream >> item;

	contact.setNumber(item);

	return iStream;
}

