	/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185	                                                        *
*	Workshop 6: Class with a Resource													*
*****************************************************************************************/


#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict
{
	bool Contact::check(long long phoneNumber) const
	{
		if (phoneNumber > 0)
		{
			return true;
		}
		else {
			return false;
		}

		if (
			(10000000000 <= phoneNumber)
			&& (phoneNumber <= 999999999999)
			&& ((phoneNumber % 10000000000 / 1000000000) >= 1)
			&& ((phoneNumber % 10000000 / 1000000) >= 1)
			)
		{
			return true;
		}
		else {
			return false;
		}
	}

	Contact::Contact()
	{
		m_nameOfContact[0] = '\0';
		m_phoneNumbers = nullptr;
		m_numberOfPhoneNumbers = 0;
	}

	Contact::Contact(const char *name, const long long *phone, const int number)
	{
		if (name == '\0')
		{
			*this->m_nameOfContact = '\0';
		}
		else
		{
			strncpy(this->m_nameOfContact, name, max_name_size - 1);
			m_nameOfContact[max_name_size] = '\0';
			m_numberOfPhoneNumbers = number;
		}

		if (phone) {
			m_phoneNumbers = new long long[m_numberOfPhoneNumbers];


			for (int i = 0; i < m_numberOfPhoneNumbers; i++)
			{
				if (check(phone[i])) {
					m_phoneNumbers[i] = phone[i];
				}
			}

		}
	}

	Contact::~Contact()
	{
		delete[] m_phoneNumbers;
	}

	bool Contact::isEmpty() const
	{
		if (m_nameOfContact[0] == '\0' || m_nameOfContact == nullptr)
		{
			return true;
		}
		else {
			return false;
		}
	}

	void Contact::display() const
	{
		if (isEmpty() == true)
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << m_nameOfContact << endl;

			for (int i = 0; i < m_numberOfPhoneNumbers; i++)
			{
				if (
					(10000000000 <= m_phoneNumbers[i])
					&& (m_phoneNumbers[i] <= 999999999999)
					&& ((m_phoneNumbers[i] % 10000000000 / 1000000000) >= 1)
					&& ((m_phoneNumbers[i] % 10000000 / 1000000) >= 1)
					)
				{
					int countryCode = m_phoneNumbers[i] / 10000000000;
					int areaCode = m_phoneNumbers[i] % 10000000000 / 10000000;
					int first = m_phoneNumbers[i] % 10000000 / 10000;
					int second = m_phoneNumbers[i] % 10000000 % 10000;

					cout << "(+" << countryCode << ") "
						<< areaCode << " ";
					cout << setfill('0') << setw(3);
					cout << first << "-";
					cout << setfill('0') << setw(4);
					cout << second << endl;
				}
			}
		}
	}
}
	



