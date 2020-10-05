/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185	                                                        *
*	Workshop 6: Class with a Resource													*
*****************************************************************************************/


#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

#include <iostream>

namespace sict 
{
	const int max_name_size = 16;


	class Contact
	{
		char m_nameOfContact[max_name_size];
		long long* m_phoneNumbers;
		int m_numberOfPhoneNumbers;

		bool check(long long) const;
	public:
		Contact();
		Contact(const char* name, const long long* phone, const int number);
		~Contact();
		bool isEmpty() const;
		void display() const;

	};
}


#endif // !CONTACT_H

