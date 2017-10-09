/*
 * contact.h
 *
 *  Created on: Oct 3, 2017
 *      Author: Jeka
 */

#ifndef CONTACT_H_
#define CONTACT_H_
#include <string>

using namespace std;

class Contact{
	string firstName;
	string lastName;
	string phoneNumber;

	public:
		Contact(){}
		Contact(string, string, string);
		void setFirstName(string);
		void setLastName(string);
		void setNumber(string);

		string getFirstName();
		string getLastName();
		string getNumber();

		friend void print(Contact&);
};

istream& operator>> (istream&, Contact&);


#endif /* CONTACT_H_ */
