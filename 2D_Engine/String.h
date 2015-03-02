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

private:

	void Alloc(unsigned int required_memory)
	{
		size = required_memory;
		str = new char[size];

	}

	void Clear(){

		str[0] = '\0';
	}

public:

	//Constructors:

	String(){

		size = 1;
		str = new char[size];
		str[0] = '\0';

		/* This code would do the same as:
			
			Alloc (1);
			Clear ();
		So it keeps the same memory and clears the string

		*/
		
	}

	String(const char* cadena){
		
		size = strlen(cadena) + 1;
		str = new char[size];
		strcpy_s(str, size, cadena);
	}

	String(String& cadena){

		size = 1;
		size += strlen(cadena.str);
		str = new char[size];
	}
	
	String(const char *format, ...)
	{
		size = 0;
		if (format != NULL)
		{
			char tmp[TMP_SIZE];
			va_list args;

			va_start(args, format);
			int res = vsprintf_s(tmp, TMP_SIZE, format, args);
			va_end(args);

			if (res > 0)
			{
				Alloc(res + 1);
				strcpy_s(str, size, tmp);
			}
		}

		if (size == 0)
		{
			Alloc(1);
			Clear();
		}
	}
	/*
//Operators

	bool operator== (const String& cadena) const{

		return strcmp(cadena.str, str) == 0;
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

		if (str.Length() + 1 > size){

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



	void Alloc(unsigned int required_memory)
	{
		size = required_memory;
		str = new char[size];

	}
	void clear(){

		str[0] = '\0';
	}

	*/

	//Destructor
	virtual	~String()
	{
		delete[] str;
	}
};

#endif
