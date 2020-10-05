/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca		        *
*	Student Number: 104497185					        *
*	Workshop MILESTONE 1								*
********************************************************/

#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>

namespace ama 
{
	const int min_year = 2019;
	const int max_year = 2028;
	const int no_error = 0;
	const int error_year = 1;
	const int error_mon = 2;
	const int error_day = 3;
	const int error_invalid_operation = 4;
	const int error_input = 5;

	class Date
	{
		//class attributes
		int m_year; // from min_year to max_year only
		int m_month; // from 1 - 12
		int m_dayOfMonth; // from 1-31
		int m_status; // error code 

		//private functions
		void status(int newStatus); // sets status of date object
		int mdays(int year, int month) const; // returns number of days in a given month for a given year. 
		

	public: 
		
		// public functions
		Date();
		Date(int year, int month, int day);
		
		int status() const;// A query
		void clearError(); //clearError(...): A modifier that resets the status of an object to no_error. 
		bool isGood() const; // query
		
		Date& operator+=(int days);
		Date& operator++();
		Date operator++(int);
		Date operator+(int days) const;
		
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& ostr) const;


	};

	std::ostream& operator<<(std::ostream&, const Date&);
	std::istream& operator>>(std::istream&, Date&);
}

#endif
