/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca		        *
*	Student Number: 104497185					        *
*	Workshop MILESTONE 2								*
*	DATE: 3/27/19										*
********************************************************/

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
//#include <stdio.h>

#include "Product.h"
#include "ErrorState.h"

using namespace std;
namespace ama
{


	void Product::message(const char* pText)
	{
		errorState.message(pText);
	}

	bool Product::isClear() const
	{
	//	return errorState.(m_errMsg);
	//return (errorState.message());
	//	
		return (errorState.message() ? "true" : "false");
		//if (errorState.message() != nullptr)
		//	return true;
		//else
		//	return false;
	}

	Product::Product(char type) : m_type(type)
	{
		strncpy(m_sku, "", max_length_sku);
		m_name = nullptr;
		//strncpy(*m_name, "x", max_length_name);
		strncpy(m_unit, "", max_length_unit);
		m_qtyOnhand = 0;
		m_qtyNeeded = 0;
		m_price = 0;
		taxStatus = false;
	}

	//A Custom Constructor with 7 arguments
	Product::Product(const char* sku, const char* name, const char* unit, double price, int qtyNeeded, int qtyOnhand, bool tax) : m_type('N')
	{
		if (name == nullptr && name[0] == '\0' && price == 0 && sku == nullptr) {

			strncpy(m_sku, "", max_length_sku);
			//strncpy(m_name, "", sizeof(m_name)); //max_length_name);
			strncpy(m_unit, "", max_length_unit);

			//strcpy_s(m_sku, "");
			m_name = nullptr;
			//strcpy_s(m_unit, "");
			m_price = 0;
			m_qtyNeeded = 0;
			m_qtyOnhand = 0;

			taxStatus = false;
		}
		else {
			strncpy(m_sku, sku, max_length_sku);
			
			int nameLength = strlen(name);
			m_name = new char[nameLength + 1];
			strcpy(m_name, name); //strncpy(m_name, name, sizeof(m_name));
			
			strncpy(m_unit, unit, max_length_unit);
			m_price = price;
			m_qtyNeeded = qtyNeeded;
			m_qtyOnhand = qtyOnhand;
			taxStatus = tax;
		}
	}


//	//The Copy Constructor.
	Product::Product(const Product& object) : m_type('N')
	{
		strncpy(m_sku, object.m_sku, max_length_sku);
		
		int nameLength = strlen(object.m_name);
		m_name = new char[nameLength + 1];
		strcpy(m_name, object.m_name);
		
		strncpy(m_unit, object.m_unit, max_length_unit);
		m_qtyOnhand = object.m_qtyOnhand;
		m_qtyNeeded = object.m_qtyNeeded;
		m_price = object.m_price;
		taxStatus = object.taxStatus;
	}

//	//The Destructor
	Product::~Product()
	{
		delete[] m_name;
	//	m_name = nullptr;
	}

	//The Copy Assignment Operator
	Product& Product::operator=(const Product& object)
	{
		strcpy(m_sku, object.m_sku);

		int nameLength = strlen(object.m_name);
		m_name = new char[nameLength + 1];
		strcpy(m_name, object.m_name);

		strcpy(m_unit, object.m_unit);
		m_qtyOnhand = object.m_qtyOnhand;
		m_qtyNeeded = object.m_qtyNeeded;
		m_price = object.m_price;
		taxStatus = object.taxStatus;

		return *this;
	}

	int Product::operator+=(int cnt)
	{
		if (cnt > 0) {
			m_qtyOnhand += cnt;
			return m_qtyOnhand;
		}
		else
		{
			return m_qtyOnhand;

		}
	}


	bool Product::operator==(const char* sku) const
	{
		if (strcmp(m_sku, sku) == 0)
				return true;
		else
				return false;
	}

	bool Product::operator>(const char* sku) const
	{
		//cout << endl <<"                                           " << m_sku << " > " << sku << endl;

		return (strcmp(m_sku, sku) > 0) ? true : false;
		//if (m_sku > sku) //1234>1233
		//{
		//	return true;
		//}
		//else
		//{
		//	return false;
		//}
	}

	//needed for the ms4 operator>
	const char Product::type() const {
		return m_type;
	}

	//needed for the ms4 operator>
	const char* Product::name() const {
		return m_name;
	}

	bool Product::operator>(const iProduct& object) const//bool Product::operator>(const Product& object) const
	{
		//cout << endl<<"                                           " << m_name << " > " << object.m_name << endl;
		return (strcmp(m_name, object.name()) > 0) ? true : false;
		//if (m_name > object.m_name) 
		//	return true;
		//else
		//	return false;
	}

	int Product::qtyAvailable() const
	{
		return m_qtyOnhand;
	}

	int Product::qtyNeeded() const
	{
		return m_qtyNeeded;
	}

	double Product::oneTax() const
	{
		if (taxStatus == true)
			return m_price * (1 + tax_rate);
		else
			return m_price;
	}

	double Product::total_cost() const
	{
		return (oneTax() * (m_qtyOnhand));
	}

	bool Product::isEmpty() const
	{
		return m_sku[0] == 0 && m_name == nullptr && m_price == 0 && m_qtyOnhand == 0 && m_qtyNeeded == 0;
	//	if (m_name == nullptr && m_sku[0] == '\0' && m_price == 0)//(*this == nullptr)
	//	{
	//		return true;
	//	}
	//	else{
	//		return false;
	//}
	}
	std::istream& Product::read(std::istream& in, bool interractive)
	{
		if (interractive == false)
		{
			//char taxYN;
			//bool valid;

			//char* tag = new char[max_length_sku + 1];
			char* sku = new char[max_length_sku + 1];
			char* name = new char[max_length_name + 1];
			char* unit = new char[max_length_unit + 1];
			char* price = new char[max_length_sku + 1];
			char* tax = new char[5];
			char* qtyA = new char[max_length_unit + 1];
			char* qtyN = new char[max_length_unit + 1];

			//in.getline(tag, ama::max_length_sku, ',');
			in.getline(sku, ama::max_length_sku, ',');
			//cout << sku;
			strcpy(m_sku, sku);
			//cout << m_type << "," << m_name << "," << m_unit << "," << m_price << ",";
			in.getline(name, ama::max_length_name, ',');
			//cout << name; //thats it? no need to make a function? this is the function for it?

			int nameLength = strlen(name);
			m_name = new char[nameLength + 1];
			strcpy(m_name, name);
			//strcpy(m_name, name);
			in.getline(unit, ama::max_length_unit, ',');
			strcpy(m_unit, unit);
			//cout << unit;
			in.getline(price, 10, ',');
			//cout << price;
			m_price = stod(price);
			in.getline(tax, 5, ',');
			taxStatus = stod(tax);
			//cout << tax;
			//if (m_tax == 0)
			//	taxStatus == false;
			//else
			//	taxStatus == true;
			in.getline(qtyA, 5, ',');
			//cout << qtyA;
			m_qtyOnhand = std::atoi(qtyA);
			in.getline(qtyN, 5, '\n');
			//cout << qtyN;
			m_qtyNeeded = std::atoi(qtyN);


		}
		else {
			char sku[max_length_sku + 1];
			char *name = new char[max_length_name + 1];
			char unit[max_length_unit + 1];
			int qtyA;
			int qtyN;
			double price;
			//char tax;
			//bool taxable;
			char taxYN[2];
			bool valid;

			//ErrorState error;
			cout << right << setw(max_length_label) << "Sku: ";
			in >> sku;
			//strcpy(m_sku, sku);
			cout << right << setw(max_length_label) << " Name (no spaces): ";
			in >> name;
			//int nameLength = strlen(name);
			//m_name = new char[nameLength + 1];
			//strcpy(m_name, name);

			cout << right << setw(max_length_label) << " Unit: ";
			in >> unit;
			//strcpy(m_unit, unit);

			cout << right << setw(max_length_label) << " Taxed? (y/n): "; //Taxed? (y/n):␣<User Types Here – y, Y, n, or N are acceptable
			in >> taxYN;

			valid = !strcmp(taxYN, "Y") || !strcmp(taxYN, "y") || !strcmp(taxYN, "N") || !strcmp(taxYN, "n");

			if (!valid) {
				//cout << "noy valid";
				in.setstate(std::ios::failbit);
				message("Only (Y)es or (N)o are acceptable!");
			}
			
			if (in.fail() == false)
			{
				cout << right << setw(max_length_label) << " Price: ";
				in >> price;
				//m_price = stod(price);
				if (in.fail() == true)
				{
					in.setstate(ios::failbit); //in.setstate(ios::failbit);
					message("Invalid Price Entry!");
				}

				if (in.fail() == false)
				{
					cout << right << setw(max_length_label) << " Quantity on hand: ";
					in >> qtyA;
					//m_qtyOnhand = stod(qtyA);
					if (in.fail() == true)
					{
						in.setstate(ios::failbit);
						message("Invalid Quantity Available Entry!");
					}

					if (in.fail() == false)
					{
						cout << right << setw(max_length_label) << " Quantity needed: ";
						in >> qtyN;

						if (in.fail() == true)
						{
							//cout << "in.fail() == true";
							in.setstate(ios::failbit);
							message("Invalid Quantity Needed Entry!");
							//cout << "nooooooooooooo" << endl;
						}//else
							//m_qtyNeeded = stod(qtyN);
					}
				}
			}

			
			if (!in.fail())
					{
				Product temp;

				if (!strcmp(taxYN, "Y") || !strcmp(taxYN, "y"))
					temp = Product(sku, name, unit, price, qtyN, qtyA, 1);
				else
					temp = Product(sku, name, unit, price, qtyN, qtyA, 0);

						//Product temp = Product(sku, name, unit, price, qtyN, qtyA, taxaYN);
						*this = temp;
					}

			//delete[] name;
			//name = nullptr;
			
			return in;// .total_cost();
		}
		return in;
	}

	std::ostream& Product::write(std::ostream& out, int writeMode) const
	{
		if (!isEmpty()) {

			if (writeMode == write_condensed)
			{
				out << m_type << "," << m_sku << "," << m_name << "," << m_unit << ",";

				out.setf(ios::fixed);
				out << setprecision(2);
				out << m_price << ",";

				int tax = 1;
				if (!taxStatus) {
					tax = 0;
				}

				out << tax << "," << m_qtyOnhand << "," << m_qtyNeeded;
			}
			if (writeMode == write_table)
			{
				out << right << setw(max_length_sku+1) << m_sku << " | ";

				/*				char temp[17];
								strncpy(temp, m_name, 17);
								if (strlen(m_name) > 16)
								{
									temp[13] = temp[14] = temp[15] = '.';
								}
								temp[16] = '\0';
								cout << "DEBUG: " << temp;*/ // you make it work too easy, i dont why is it so hard.

				if (m_name != nullptr && (strlen(m_name) > 16))
				{
					string str = m_name;
					string th = str.substr(0, 13);
					string dot = "...";
					string name = th + dot;
					out << left << setw(16) << name; //that should also work

				}
				else
				{
					out << m_name;
				}

				out << " | "; //<< left << setw(16)
				out << left << setw(10) << m_unit << right << " | ";

				out << right << setw(7);
				out.setf(ios::fixed);
				out << setprecision(2);
				out << m_price << " | ";

				string ts = "yes";
				if (!taxStatus) {
					ts = "no";
				}

				out << left << setw(3) << ts << right << " | ";

				out << right << setw(6) << m_qtyOnhand << right << " | ";
				out << right << setw(6) << m_qtyNeeded << right << " |";
			}
			if (writeMode == write_human)
			{
				//out.setf(ios::right);
				//out << setw(24);
				out << right << setw(max_length_label) << "Sku: " << m_sku << endl;
				out << right << setw(max_length_label) << "Name: " << m_name << endl;

				out.setf(ios::fixed);// , ios::floatfield);
				out << right << setw(max_length_label);
				out << setprecision(2);
				out << "Price: " << m_price << endl;
				//out.unsetf(ios::fixed);

				out.setf(ios::fixed);
				out << right << setw(max_length_label);
				out << setprecision(2);
				out << "Price after Tax: " << oneTax() << endl;
				//out.unsetf(ios::fixed);

				out << right << setw(max_length_label) << "Quantity Available: " << m_qtyOnhand << " " << m_unit << endl;
				out << right << setw(max_length_label) << "Quantity Needed: " << m_qtyNeeded << " " << m_unit << endl;
				//out.unsetf(ios::floatfield);
			}
			else
			{
				return out;
			}
		}
		else
			if (errorState.message() != nullptr)// ? "null" : msg.message())
				out << errorState.message();

		return out;
	}


}
