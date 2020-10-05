/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca		        *
*	Student Number: 104497185					        *
*	Workshop MILESTONE 1								*
********************************************************/

#include <iostream>
#include "Date.h"

using namespace std;

namespace ama
{
	void Date::status(int newStatus)
	{
		m_status = newStatus;
	}

	int Date::mdays(int year, int mon) const
	{ 
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)); 
	}

	Date::Date()
	{
		m_year = 0;
		m_month = 0;
		m_dayOfMonth = 0;
		clearError();
	}

	Date::Date(int year, int month, int day)
	{
		if (year >= min_year && year <= max_year) 
		{
			if (month >= 1 && month <= 12) 
			{
				if (day > 0 && day <= mdays(year, month))
				{
					m_year = year;
					m_month = month;
					m_dayOfMonth = day;
					status(no_error);			
				}
				else {
					status(error_day);
				}
			}
			else {
				status(error_mon);
			}
		}
		else {
			status(error_year);
		}

		if (!isGood()) {
			m_year = 0;
			m_month = 0;
			m_dayOfMonth = 0;
		}
	}

	int Date::status() const
	{
		return m_status;
	}

	void Date::clearError() 
	{

		this->m_status = no_error;
	}

	bool Date::isGood() const
	{
		bool test = false;
		if (
			(m_status == no_error) &&
			(m_year >= min_year && m_year <= max_year) &&
			(m_month >= 1 && m_month <= 12) &&
			(m_dayOfMonth <= mdays(m_year, m_month))
			)
		{
			test = true;
		}
		return test;

	}

	Date& Date::operator+=(int days)
	{
		if (isGood() == false) 
		{
			m_status = error_invalid_operation;
		}
		else {
			int number = m_dayOfMonth + days;

			if (number <= mdays(m_year, m_month) && number > 0)
			{
				m_dayOfMonth += days;
				m_status = no_error;
			}
			else {
				m_status = error_invalid_operation;
			}
		}
		return *this;
	}

	Date& Date::operator++() //prefix++
	{
		if (isGood() == false)
		{
			m_status = error_invalid_operation;
		}
		else {
			int number = m_dayOfMonth + 1;
			if (number <= mdays(m_year, m_month))
			{
				m_dayOfMonth += 1;
				m_status = no_error;
			}
			else {
				m_status = error_invalid_operation;
			}
		}
		return *this;
	}

	Date Date::operator++(int) //postfix
	{
		Date temp = *this;

		if (isGood() == false)
		{
			m_status = error_invalid_operation;
		}
		else {
			int number = m_dayOfMonth + 1;
			if (number <= mdays(m_year, m_month))
			{		
				m_dayOfMonth += 1;
				m_status = no_error;
			}
			else {
				m_status = error_invalid_operation;
			}

		}
		return temp;
	}

	Date Date::operator+(int days) const
	{
		Date plus = *this;
		plus += days;
		return plus;
	}

	bool Date::operator==(const Date& rhs) const
	{
		bool dayEqual = this->m_dayOfMonth == rhs.m_dayOfMonth;
		bool monthEqual = this->m_month == rhs.m_month;
		bool yearEqual = this->m_year == rhs.m_year;

		return (dayEqual && monthEqual && yearEqual);
	}

	bool Date::operator!=(const Date& rhs) const
	{
		return !(*this == rhs);
	}

	bool Date::operator<(const Date& rhs) const
	{
		bool yearLess = this->m_year < rhs.m_year;
		bool monthLess = this->m_month < rhs.m_month;
		bool dayLess = this->m_dayOfMonth < rhs.m_dayOfMonth;

		if (yearLess)
		{
			return true;
		}
		else if (monthLess)
		{
			return true;
		}
		else if (dayLess)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator>(const Date& rhs) const 
	{

		bool dayGreat = this->m_dayOfMonth > rhs.m_dayOfMonth;
		bool monthGreat = this->m_month > rhs.m_month;
		bool yearGreat = this->m_year > rhs.m_year;
		
		if (yearGreat)
		{
			return true;
		}
		else if (monthGreat)
		{
			return true;
		}
		else if (dayGreat)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator<=(const Date& rhs) const
	{
		return (*this < rhs || *this == rhs);
	}

	bool Date::operator>=(const Date& rhs) const
	{
		return (*this > rhs || *this == rhs);
	}

	std::istream& Date::read(std::istream& is)
	{
		int year = 0, month = 0, day = 0;
		is >> year;
		is.ignore();

		is >> month;
		is.ignore();

		is >> day;
		if (is.fail())
		{
			this->status(error_input);
		}
		else
			*this = Date(year, month, day);

		return is;
	}
	
	std::ostream& Date::write(std::ostream& os) const {
		os.fill('0');
		os.width(4);
		os << m_year;
		os << "/";
		os.fill('0');
		os.width(2);
		os.unsetf(ios::left);
		os << m_month;
		os << "/";
		os.fill('0');
		os.width(2);
		os << m_dayOfMonth;
		os.fill(' ');
	
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Date& date) {
		date.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Date& date) {
		date.read(is);
		return is;
	}
}




