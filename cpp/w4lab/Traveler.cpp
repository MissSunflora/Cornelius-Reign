// TODO: add file header comments here
/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185	                                                        *
*	Workshop 4 Lab: TRAVELERS VALIDATION LOGIC											*
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
	Traveler::Traveler() //default constructor
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
			*this->m_tFirstName = '\0';
			*this->m_tLastName = '\0';
			*this->m_destination = '\0';
		}
		else
		{
			strncpy(this->m_tFirstName, firstName, name_size);
			strncpy(this->m_tLastName, lastName, name_size);
			strncpy(this->m_destination, destination, max_desination_size);
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
			cout << m_tFirstName << " " << m_tLastName
				<< " goes to " << m_destination << endl;
		}
		else {
			cout << "--> Not a valid traveler! <--" << endl;
		}
	}
}
