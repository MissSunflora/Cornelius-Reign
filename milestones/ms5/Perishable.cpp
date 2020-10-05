/********************************************
*	Name: Nesa Rosmar Jan Bertanico			*
*	Seneca Email: nrjebrtanico@myseneca.ca	*
*	Student Number: 104497185				*
*	Workshop MILESTONE 5					*
*	Date: 04/06/2019						*
*********************************************/
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Perishable.h"


using namespace std;
namespace ama {

	Perishable::Perishable() :Product ('P')
	{}

	ostream& Perishable::write(ostream& out, int writeMode) const 
	{
		Product::write(out, writeMode);

		if (this->isEmpty() == false && this->isClear()) {
			if (writeMode == write_condensed) {
				out << ",";
				expiryDate.write(out);
			}
			else if (writeMode == write_human) {
				out.setf(ios::right);
				out.width(max_length_label);
				out << "Expiry Date: ";
				expiryDate.write(out);
				out << endl;
			}
			else if (writeMode == write_table) {
				out.setf(ios::right);
				out << " ";
				out.width(10);
				expiryDate.write(out);
				out << " |";
			}
		}
		return out;

	}

	istream& Perishable::read(istream& in, bool interractive)
	{
		Product::read(in, interractive);
		Date dt;
		if (interractive == true) {
			if (this->isClear())
			{
				cout.setf(ios::right);
				cout.width(max_length_label);
				cout << "Expiry date (YYYY/MM/DD): ";
				in >> dt;
			}
			if (this->isClear() && dt.status() != no_error)
			{
				if (dt.status() == ama::error_day)
				{
					this->message("Invalid Day in Date Entry");
					in.setstate(ios::failbit);
				}
				else if (dt.status() == ama::error_mon)
				{
					this->message("Invalid Month in Date Entry ");
					in.setstate(ios::failbit);
				}
				else if (dt.status() == ama::error_year)
				{
					this->message("Invalid Year in Date Entry");
					in.setstate(ios::failbit);
				}
				else if (dt.status() == ama::error_input)
				{
					this->message("Invalid Date Entry");
					in.setstate(ios::failbit);
				}
			}
			
			if(isClear())
			{
					expiryDate = dt;
			}
		}
		else
		{
			expiryDate.read(in);
			in.ignore();
		}
		return in;
	}
}
