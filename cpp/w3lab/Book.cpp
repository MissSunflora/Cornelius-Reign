/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185															*
*****************************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
#include "Book.h"

using namespace std;

namespace sict
{
	void Book::set(const char* gName, const char* fName, const char* tit, long long number)
	{
		/*delete[] family_name;
		delete[] given_name;
		delete[] isbn;

		family_name = new char;
		given_name = new char;
		isbn = new char;*/

		if (min_isbn_value <= number && number <= max_isbn_value)
		{
			strncpy(this->title, tit, max_title_size);
			strncpy(this->family_name, fName, max_name_size);
			strncpy(this->given_name, gName, max_name_size);
			isbn = number;
		}
		else 
			{
			isbn = 0;
			}
	}

	bool Book::isEmpty() const
	{
		if (isbn == 0)
		{
			return true;
		}else
			return false;
	}

	void Book::display() const
	{
		if (Book::isEmpty() == false)
		{
			cout << "Author: " << family_name << ", " << given_name << endl
				<< "Title: " << title << endl
				<< "ISBN-13: " << isbn << endl;

		}
		else
			cout << "The book object is empty!" << endl;
	}


}


