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

#include "Product.h"
#include "ErrorState.h"
#include "Utilities.h"

using namespace std;
namespace ama
{
	void Product::message(const char* pText)
	{
		errorState.message(pText);
	}

	bool Product::isClear() const
	{
		return (errorState.message() ? false : true);
	}

	Product::Product(char type) : m_type(type)
	{
		m_sku[0] = '\0';
		m_name = nullptr;
		m_unit[0] = '\0';
		m_price = 0;
		m_qtyOnhand = 0;
		m_qtyNeeded = 0;
		taxStatus = false;
	}

	//A Custom Constructor with 7 arguments
	Product::Product(const char* sku, const char* name, const char* unit, double price, int qtyNeeded, int qtyOnhand, bool tax) : Product('N')
	{
		if (name == nullptr && name[0] == '\0' && price == 0 && sku == nullptr) {

			strncpy(m_sku, "", max_length_sku);
			strncpy(m_unit, "", max_length_unit);
			m_name = nullptr;
			m_price = 0;
			m_qtyNeeded = 0;
			m_qtyOnhand = 0;
			taxStatus = false;
		}
		else {
			strncpy(m_sku, sku, max_length_sku);
			int nameLength = strlen(name);
			m_name = new char[nameLength + 1];
			strcpy(m_name, name); 	
			strncpy(m_unit, unit, max_length_unit);
			m_price = price;
			m_qtyNeeded = qtyNeeded;
			m_qtyOnhand = qtyOnhand;
			taxStatus = tax;
		}
	}

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

	Product::~Product()
	{
		delete[] m_name;
	}

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
			return m_qtyOnhand;

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
		return (strcmp(m_sku, sku) > 0) ? true : false;
	}

	const char Product::type() const {
		return m_type;
	}

	const char* Product::name() const {
		return m_name;
	}

	bool Product::operator>(const iProduct& object) const
	{
		return (strcmp(m_name, object.name()) > 0) ? true : false;
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
		if (m_name == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void Product::sku(char sku[max_length_sku+1])
	{
		strcpy(m_sku, sku);
	}

	void Product::unit(char unit[max_length_unit+1])
	{
		strncpy(m_unit, unit, max_length_unit);
	}

	void Product::name(const char* name)
	{
		m_name = new char[strlen(name) + 1];
		strncpy(m_name, name, max_length_sku);
	}

	std::istream& Product::read(std::istream& in, bool interractive)
	{
		if (interractive == false)
		{
			in.getline(this->m_sku, max_length_sku, ',');
			m_name = new char[max_length_name + 1];
			in.getline(m_name, max_length_name, ',');
			in.getline(m_unit, max_length_unit, ',');
			in >> m_price;
			in.ignore();
			in >> taxStatus;
			in.ignore();
			in >> m_qtyOnhand;
			in.ignore();
			in >> m_qtyNeeded;
			in.ignore();


		}
		else {
			char taxYN;

			cout << right << setw(max_length_label) << "Sku: ";
			in >> m_sku;
			m_name = new char[max_length_name];
			cout << right << setw(max_length_label) << " Name (no spaces): ";
			in >> m_name;
			cout << right << setw(max_length_label) << " Unit: ";
			in >> m_unit;
			cout << right << setw(max_length_label) << " Taxed? (y/n): "; 
			in >> taxYN;

			if (taxYN == 'Y' || taxYN == 'y')
				taxStatus = true;
			else if (taxYN == 'N' || taxYN == 'n')
				taxStatus = false;
			else {
				in.setstate(ios::failbit);
				message("Only (Y)es or (N)o are acceptable!");
			}

			if (in.fail() == false)
			{
				cout << right << setw(max_length_label) << " Price: ";
				in >> m_price;
				if (in.fail() == true)
				{
					in.setstate(ios::failbit);
					message("Invalid Price Entry!");
				}

				if (in.fail() == false)
				{
					cout << right << setw(max_length_label) << " Quantity on hand: ";
					in >> m_qtyOnhand;

					if (in.fail() == true)
					{
						in.setstate(ios::failbit);
						message("Invalid Quantity Available Entry!");
					}

					if (in.fail() == false)
					{
						cout << right << setw(max_length_label) << " Quantity needed: ";
						in >> m_qtyNeeded;

						if (in.fail() == true)
						{
							in.setstate(ios::failbit);
							message("Invalid Quantity Needed Entry!");
						}
					}
				}
			}
		}
		if (!in.fail())
		{
			Product theProd(m_sku, m_name, m_unit, m_price, m_qtyNeeded, m_qtyOnhand, taxStatus);
			*this = theProd;
		}
		return in;
	}

	std::ostream& Product::write(std::ostream& out, int writeMode) const
	{
		if (errorState)
		{
			out << errorState;
		}
		else if (!isEmpty()) {

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
			else if (writeMode == write_table)
			{
				out << right << setw(max_length_sku+1) << m_sku << " | ";
				if (m_name != nullptr && (strlen(m_name) > 16))
				{
					string str = m_name;
					string th = str.substr(0, 13);
					string dot = "...";
					string name = th + dot;
					out << left << setw(16) << name; 
				}
				else
				{
					out << left << setw(16) << m_name;
				}

				out << " | ";
				out << left << setw(10) << m_unit << right << " | ";
				out << right << setw(7);
				out.setf(ios::fixed);
				out << setprecision(2);
				out << m_price << " | ";

				string ts = "yes";
				if (!taxStatus) {
					ts = "no";
				}

				out << right<< setw(3) << ts  << " | ";
				out << right << setw(6) << m_qtyOnhand << " | ";
				out << right << setw(6) << m_qtyNeeded <<  " |";
			}
			else if (writeMode == write_human)
			{
				out << right << setw(max_length_label) << "Sku: " << m_sku << endl;
				out << right << setw(max_length_label) << "Name: " << m_name << endl;

				out.setf(ios::fixed);
				out << right << setw(max_length_label);
				out << setprecision(2);
				out << "Price: " << m_price << endl;
				out.setf(ios::fixed);
				out << right << setw(max_length_label);
				out << setprecision(2);
				out << "Price after Tax: " << oneTax() << endl;
				out << right << setw(max_length_label) << "Quantity Available: " << m_qtyOnhand << " " << m_unit << endl;
				out << right << setw(max_length_label) << "Quantity Needed: " << m_qtyNeeded << " " << m_unit << endl;
			}
		}
		return out;
	}


}
