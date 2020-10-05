// TODO: add file header comments here
/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185	                                                        *
*	Workshop 4 Lab: TRAVELERS VALIDATION LOGIC											*
*****************************************************************************************/

// TODO: add header file guard here
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

// TODO: declare your namespace here
namespace sict {

	// TODO: define the constants here
	const int max_desination_size = 32;
	const int name_size = 16;


	// TODO: define the Traveler class here
	class Traveler
	{
		char m_tFirstName[name_size];//The traveler’s first name
		char m_tLastName[name_size];//The traveler’s last name
		char m_destination[max_desination_size];//The destination

	public:
		Traveler(); //default constructor
		Traveler(const char*, const char*, const char*);
		bool isEmpty() const;
		void display() const;	   	 
	};
}


#endif