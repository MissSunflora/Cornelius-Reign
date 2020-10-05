// TODO: add file header comments here
/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185	                                                        *
*	Workshop 4 Home: TRAVELERS VALIDATION LOGIC											*
*****************************************************************************************/
// TODO: add your headers here

#include <iostream>
#include <cstring>
#include "Traveler.h"

using namespace std;

// TODO: continue your namespace here
namespace sict
{
	// TODO: implement the default constructor here
	Traveler::Traveler() //my custom made constructor
	{
		*this->m_tFirstName = '\0';
		*this->m_tLastName = '\0';
		*this->m_destination = '\0';

	}


	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char* firstName, const char* lastName, const char* destination)
	{
		if ((firstName == '\0' || nullptr) ||
			(lastName == '\0' || nullptr) ||
			(destination == '\0' || nullptr))
		{
			*this = Traveler();
			//instead of:
			//*this->m_tFirstName = '\0';
			//*this->m_tLastName = '\0';
			//*this->m_destination = '\0';
			
		}
		else
		{
			strncpy(this->m_tFirstName, firstName, name_size);
			strncpy(this->m_tLastName, lastName, name_size);
			strncpy(this->m_destination, destination, max_desination_size);
			
			m_dYear = 2019;
			m_dMonth = 7;
			m_dDay = 1;

		}
	}

	// TODO: implement isEmpty query here
	bool Traveler::isEmpty() const
	{
		if ((*this->m_tFirstName == '\0' || m_tFirstName == nullptr) ||
			(*this->m_tLastName == '\0' || m_tLastName == nullptr) ||
			(*this->m_destination == '\0' || m_destination == nullptr))
			return true;
		else
			return false;
	}

	// TODO: implement display query here
	void Traveler::display() const
	{
		if (Traveler::isEmpty() == false)
		{
			cout << m_tLastName  << ", " << m_tFirstName
				<< " goes to " << m_destination << " on "
				<< this->m_dYear << "/";
				
			cout.fill('0');
			cout.width(2);

			cout << m_dMonth << "/";

			cout.fill('0');
			cout.width(2);

			cout << m_dDay << endl;
		}
		else {
			cout << "--> Not a valid traveler! <--" << endl;
		}
	}


	Traveler::Traveler(const char* fName, const char* lName, const char* dest, const int year, const int month, const int day)
	{
		if (
			(fName == '\0' || nullptr) ||
			(lName == '\0' || nullptr) ||
			(dest == '\0' || nullptr) ||
			(year < 2019) || (year > 2022) || (year == 0) ||
			(month < 1) || (month > 12) || (month == 0) ||
			(day < 1) || (day > 31) || (day == 0)
			)
		{
			*this = Traveler();			

			m_dYear = 0; 
			m_dMonth = 0;
			m_dDay = 0;
		}
		else
		{
			strncpy(this->m_tFirstName, fName, name_size);
			strncpy(this->m_tLastName, lName, name_size);
			strncpy(this->m_destination, dest, max_desination_size);
			this->m_dYear = year;
			this->m_dMonth = month;
			this->m_dDay = day;
		}
	}
	const char* Traveler::name() const
	{	
		return m_tFirstName;
	}

	//bool canTravelWith(const Traveler&) const;

	bool Traveler::canTravelWith(const Traveler& friends) const
	{
			if ((strcmp(friends.m_destination, m_destination) == 0) &&
				(friends.m_dYear == m_dYear) &&
				(friends.m_dMonth == m_dMonth) &&
				(friends.m_dDay == m_dDay))
				return 1;
			return 0;
	}
		

}
