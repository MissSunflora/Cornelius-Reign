/********************************************************
*	Name: Nesa Rosmar Jan Bertanico						*
*	Seneca Email: nrjebrtanico@myseneca.ca		        *
*	Student Number: 104497185					        *
*	Workshop MILESTONE 2								*
*	DATE: 3/12/19										*
********************************************************/


#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std;
namespace ama {
																	//constructors:
	ErrorState::ErrorState(const char* errorMessage)// = nullptr)
	{
		if (errorMessage == nullptr || *errorMessage == '\0')// || errorMessage == "")
		{
			m_errMsg = nullptr;
		}
		else
		{
			message(errorMessage);
		}


	}

																	//deconstructor:
	ErrorState::~ErrorState()
	{
		delete[] m_errMsg;
		m_errMsg = nullptr;
	}


	ErrorState& ErrorState::operator=(const char* pText)
	{
		if (pText == nullptr || !*pText) //|| pText[0] == '\0' || pText == NULL)
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
		//int strLength = strlen(pText);
		//m_errMsg = new char[strLength + 1];
		//strncpy(m_errMsg, pText, strLength);
		//m_errMsg[0] = '\0';
		if (pText == nullptr || *pText == 0)// || pText == '\0' || pText == NULL)
		{
			m_errMsg = nullptr;
		}
		else
		{
			m_errMsg = nullptr;

			m_errMsg = new char[strlen(pText) + 1];
			strcpy(m_errMsg, pText);//strcpy_s(m_errMsg, pText);
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
