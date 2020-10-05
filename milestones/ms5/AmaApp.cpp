/********************************************
*	Name: Nesa Rosmar Jan Bertanico			*
*	Seneca Email: nrjebrtanico@myseneca.ca	*
*	Student Number: 104497185				*
*	Workshop MILESTONE 5					*
*	Date: 04/06/2019						*
*********************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <string>
#include "AmaApp.h"


using namespace std;
namespace ama
{

	AmaApp::AmaApp(const char* filename)
	{
		if (filename != 0)
			strncpy(m_filename, filename, 256);
		else
			strncpy(m_filename, "", 256);

		for (int i = 0; i < 100; i++)
		{
			m_products[i] = nullptr;
		}
		m_noOfProducts = 0;
		loadProductRecords();
	}

	//destructor
	AmaApp::~AmaApp()
	{
		for (int j = 0; j < m_noOfProducts; j++)
		{
			delete m_products[j];
			m_products[j] = nullptr;
		}
	}

	void AmaApp::pause() const
	{
		cout << "Press Enter to continue..." << endl;
		cin.ignore();
	}

	int AmaApp::menu() const
	{
		int option = 0;
		cout << "Disaster Aid Supply Management Program" << endl
			<< "--------------------------------------" << endl
			<< "1- List products" << endl
			<< "2- Search product" << endl
			<< "3- Add non-perishable product" << endl
			<< "4- Add perishable product" << endl
			<< "5- Add to product quantity" << endl
			<< "6- Delete product" << endl
			<< "7- Sort products" << endl
			<< "0- Exit program" << endl
			<< "> ";
		cin >> option;

		if (option >= 0 && option <= 7)
		{
			cin.clear();
			cin.ignore();
			return option;
		}
		else
		{
			cin.clear();
			cin.ignore();
			return -1;
		}
	}


	void AmaApp::loadProductRecords()
	{
		for (int j = 0; j < m_noOfProducts; j++)
		{
			delete m_products[j];
			m_products[j] = nullptr;
		}

		fstream file;
		char oneChar;
		int i = 0;

		file.open(m_filename, ios::in | ios::out);
		if (file.is_open())
		{
			do
			{
				file >> oneChar;
				if (file.fail())
				{
					break;
				}
				file.ignore();

				m_products[i] = ama::createInstance(oneChar);

				if (m_products[i] != nullptr)
				{
					m_products[i]->read(file, false);
					i++;
				}
			} while (!file.eof());
			m_noOfProducts = i;
		}
		file.close();
	}

	void AmaApp::saveProductRecords() const
	{
		fstream file;
		file.open("inventory.txt", ios::out);
		for (int i = 0; i < m_noOfProducts; i++)
		{
			m_products[i]->write(file, write_condensed);
			file << endl;
		}
		file.clear();
		file.close();
	}

	void AmaApp::listProducts() const
	{
		fstream file("inventory.txt", ios::in | ios::out);
		double total = 0;

		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl;
		cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

		for (int i = 0; i < m_noOfProducts; i++)
		{
			cout << "|";
			cout << right << setw(4) << i + 1 << " |";
			m_products[i]->write(cout, ama::write_table);
			cout << endl;
			total += *this->m_products[i];
		}

		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                      Total cost of support ($): | ";
		cout << setw(10) << setprecision(2) << total;
		cout << " |" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl << endl;
		pause();
	}

	void AmaApp::deleteProductRecord(iProduct* product)
	{
		fstream file;
		file.open(m_filename, ios::out);

		for (int i = 0; i < m_noOfProducts; i++)
		{
			if (m_products[i] != product)
			{
				m_products[i]->write(file, write_condensed);
				file << endl;
			}
		}
	}

	void AmaApp::sort()
	{
		sict::sort(m_products, m_noOfProducts);//T sort(const T* data, int n)
	}

	iProduct* AmaApp::find(const char* sku) const
	{
		for (int i = 0; i < m_noOfProducts; i++)
		{
			if (*m_products[i] == sku)
			{
				return m_products[i];
			}
		}
		return nullptr;
	}

	void AmaApp::addQty(iProduct* product)
	{
		int value = 0;
		int qty = 0;

		product->write(cout, ama::write_human);
		cout << endl << endl;
		cout << "Please enter the number of purchased items: ";
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(123, '\n');
			cout << "Invalid quantity value!" << endl << endl;
		}
		else
		{
			qty = product->qtyNeeded() - product->qtyAvailable();
			if (qty <= value)
			{
				int extra = value - qty;
				cout << "Too many items; only " << qty << " is needed. Please return the extra " << extra << " items." << endl;
				*product += qty;
			}
			else
			{
				*product += value;
			}

			cout << endl << "Updated!" << endl << endl;

			cin.clear();
			cin.ignore(1000, '\n');
		}
		saveProductRecords();
	}

	void AmaApp::addProduct(char tag)
	{
		iProduct* prod = ama::createInstance(tag);

		if (prod != nullptr)
		{
			cin >> *prod;

			if (cin.fail())
			{
				cout << endl << *prod << endl << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				delete prod;
			}
			else {
				m_products[m_noOfProducts] = prod;
				m_noOfProducts++;
				saveProductRecords();
				cout << endl << "Success!" << endl << endl;
			}
			cin.clear();
		}
	}

	int AmaApp::run()
	{
		int menuOption = 0;
		int flag = 0;

		iProduct* theProd = nullptr;
		Product oneprod;

		do {
			menuOption = menu();

			switch (menuOption) {

			case 1://List the products
				AmaApp::listProducts();
				break;
			case 2: //Display product 
				char mm_sku[123];
				cout << "Please enter the product SKU: ";
				cin >> mm_sku;
				cout << endl;
				cin.ignore(123, '\n');
				theProd = find(mm_sku);
				if (theProd != nullptr)
				{
					theProd->write(cout, write_human);
					cout << endl;
				}
				else
				{
					cout << "No such product!" << endl;
				}
				pause();

				break;
			case 3: //Add non-perishable product 
				addProduct('n');
				loadProductRecords();
				break;
			case 4:// Add perishable product
				addProduct('p');
				loadProductRecords();
				break;
			case 5: // Add to quantity of purchased products 
				char add_sku[123];
				cout << "Please enter the product SKU: ";
				cin >> add_sku;
				theProd = find(add_sku);

				if (theProd != nullptr)
				{
					cout << endl;
					AmaApp::addQty(theProd);
				}
				else
				{
					cout << endl << "No such product!" << endl << endl;
				}
				break;
			case 6: //Delete product
				char del_sku[123];
				cout << "Please enter the product SKU: ";
				cin >> del_sku;
				theProd = find(del_sku);

				if (theProd != nullptr)
				{
					deleteProductRecord(theProd);

					loadProductRecords();
					cout << endl << "Deleted!" << endl;
				}
				else
				{
					cout << endl << "No such product!" << endl;
				}
				break;
			case 7:// Sort products 
				AmaApp::sort();
				AmaApp::saveProductRecords();
				cout << "Sorted!" << endl << endl;
				break;
			case 0: //Exit program
				cout << "Goodbye!" << endl;
				return 0;
				break;

			default:
				cout << "~~~Invalid selection, try again!~~~" << endl;
				pause();
				break;
			}
		} while (flag == 0);
		return 0;
	}
}

