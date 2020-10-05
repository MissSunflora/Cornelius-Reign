/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185															*
*****************************************************************************************/

#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

namespace sict
{

	void Book::set(const char* gName, const char* fName, const char* tit, long long number)
	{
		if (min_isbn_value <= number && number <= max_isbn_value)
		{
			long long tempNumber = number;		//9780441172719
			int tempStorage = 0;
			int sumOdd = 0;
			int sumEven = 0;
			int sumTotal = 0;
			int last;
			int difference;
			int multiple;
			

			last = tempNumber % 10;		//stores the last number of isbn
			tempNumber = tempNumber / 10;

			for (int i = 12; i >= 0; i--)
			{

				tempStorage = tempNumber % 10;	//9 7 8 0 4 4 1 1 7 2 7 1 9
				tempNumber = tempNumber / 10;
				
				if (i % 2 == 0)
				{
					sumOdd = sumOdd + tempStorage; //add all odd-positioned numbers
				}
				else
				{
					sumEven = sumEven + tempStorage; //add all even-positioned numbers
				}
			}
			
			sumTotal = sumEven + (sumOdd * 3);		// summation of sumOdd and of sumEven which is multiplied by 3
			multiple = ((sumTotal / 10) * 10) + 10;	//formula to take the highest integer multiple of 10 of the sumTotal
			difference = multiple - sumTotal;		//difference between multiple and sumTotal	  	
			
			
			if (last == difference) //if last digit is equals to the difference, accept the input.
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
		else {
			isbn = 0;
		}
	}

	void Book::set(int year, double price)
	{
		if (isbn != 0)
		{
			m_year = year;
			m_price = price; 
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

	void Book::display(bool empty) const
	{
		if (empty == false) 
		{
			if (Book::isEmpty() == true)
			{
				cout << "The book object is empty!" << endl;
			}
			else
			{	cout << "Author: " << family_name << ", " << given_name << endl
					<< "Title: " << title << endl
					<< "ISBN-13: " << isbn << endl
					<< "Publication Year: " << m_year << endl
					<< "Price: " << m_price << endl;
			}	
		}
		else {
			if (Book::isEmpty() == true)
			{
				cout.setf(ios::left);
				cout << "|";
				cout.width(92);
				cout << "The book object is empty! " << "|" << endl;
			}
			else {
				cout.setf(ios::right);
				cout << "|";
				cout.width(max_name_size);
				cout << family_name;
				cout << "|";


				cout.width(max_name_size);
				cout << given_name;
				cout << "|";
				cout.unsetf(ios::right);
				
				cout.setf(ios::left);
				cout.width(max_title_size);
				cout << title;


				cout << "|";
				cout.width(13);
				cout << isbn;

				cout << "|";
				cout.width(4);
				cout << m_year;

				cout.setf(ios::fixed);
				cout.precision(2);
				cout.setf(ios::right);
				cout << "|";
				cout.width(6);
				cout << m_price;
				cout << "|" << endl;
				cout.unsetf(ios::fixed);
				cout.unsetf(ios::right);
			}

		}	
	}
}


