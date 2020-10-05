/****************************************************************************************
*	Name: Nesa Rosmar Jan Bertanico														*
*	Seneca Email: nrjebrtanico@myseneca.ca												*
*	Student Number: 104497185															*
*****************************************************************************************/


#ifndef Book_H //header safeguards
#define Book_H

namespace sict
{
	const int max_title_size = 33;	//const char* max_title_size[33];
	const int max_name_size = 17;		//const char* max_name_size[17];
	const long long min_isbn_value = 1000000000000;
	const long long max_isbn_value = 9999999999999;
	
	class Book
	{
		char family_name[max_name_size];
		char given_name[max_name_size];
		long long isbn;
		char title[max_title_size];

	public:
		void set(const char*, const char*, const char*, long long);
		bool isEmpty() const; //strncpy
		void display() const;

	};
}
#endif



