/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca		        *
*	Student Number: 104497185					        *
*	Workshop MILESTONE 2								*
********************************************************/


#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std;
namespace ama {
	//constructors:
	ErrorState::ErrorState(const char* errorMessage)
	{
		if (errorMessage == nullptr || errorMessage == '\0')// || errorMessage == "")
		{
			m_errMsg = nullptr;
		}
		else
		{
			m_errMsg = new char[strlen(errorMessage) + 1];
			strcpy(m_errMsg, errorMessage);
		}

		/*m_errMsg = nullptr;
			message(errorMessage);
	*/
	}

	//deconstructor:
	ErrorState::~ErrorState()
	{
		delete[] m_errMsg;
		m_errMsg = nullptr;
	}

	//operator= :
	ErrorState& ErrorState::operator=(const char* pText)
	{
		if (pText == nullptr || pText[0] == '\0' || pText == "")
		{
			m_errMsg = nullptr;
		}
		else
		{
			//m_errMsg = nullptr;

			message(pText);
		}


		return *this;

	}

	//bool
	ErrorState::operator bool() const // isGood?
	{
		if (m_errMsg != nullptr) {
//			cout << endl << "                                                  bool true" << endl;
			return true;
		}
		else
		{
//			cout << endl << "                                                  bool false" << endl;
			return false;
		}
	}

	//message
	void ErrorState::message(const char* pText)
	{	
		if (pText == nullptr || pText == '\0' || pText == "")
		{
			m_errMsg = nullptr;
		}
		else
		{
			m_errMsg = nullptr;
			int storage = strlen(pText);
			this->m_errMsg = new char[storage + 1];
			strcpy(this->m_errMsg, pText);
		}
	}

	const char* ErrorState::message() const
	{
		if (m_errMsg)//(m_errMsg != nullptr)
		{
			return m_errMsg;
		}
		else
		{
			return nullptr;
		}
	}
																		//<<
	std::ostream& operator<<(std::ostream& os, const ErrorState& erState)
	{
		if (erState.message() != nullptr)
		{
			os << erState.message();
		}
		return os;


	}
}
