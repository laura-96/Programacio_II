#ifndef __STRING_H__
#define __STRING_H__

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#define TMP_SIZE 5000

class String {

public:
	char* str;
	int size;


	//Methods:

	void Alloc(unsigned int required_memory)
	{
		size = required_memory;
		str = new char[size];

	}

	void Clear(){

		str[0] = '\0';
	}

	int Length() const{
		return strlen(str);
	}

	int Capacity() const{
		return (strlen(str) + 1);
	}

	const char* GetString()const { return str; }

public:

	//Constructors:

	String();
	String(const char* cadena);
	String(String& cadena);
	String(const char *format, ...);

	//Operators

	bool operator== (const String& cadena) const{

		return strcmp(cadena.str, str) == 0;
	}

	bool operator== (const char* cadena) const{

		return strcmp(cadena, str) == 0;
	}


	
	String& operator= (const char* cadena) {

		if (str != NULL){
			if (strlen(cadena) + 1 < size){
				delete[] str;
				Alloc(strlen(cadena) + 1);
			}

			strcpy_s(str, size, cadena);
		}
		else
		{
			Clear();
		}
		return (*this);
	}

	
	String& operator= (const String& cadena) {

		if (cadena.Length() + 1 > size){

			delete[] str;
			Alloc(strlen(cadena.str) + 1);
			strcpy_s(str, size, cadena.GetString());
		}

	
		else
		{
			Clear();
		}
		return (*this);
}



	//Destructor
	virtual	~String()
	{
		delete[] str;
	}
};

#endif
