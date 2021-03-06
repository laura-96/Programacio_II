#include <stdio.h>
#include <string.h>
#include "String.h"

//Constructors:

String::String(){

	size = 1;
	str = new char[size];
	str[0] = '\0';

	/* This code would do the same as:

	Alloc (1);
	Clear ();
	So it keeps the same memory and clears the string

	*/
}


String::String(const String& cadena){

	size = 0;
	str = NULL;
	Alloc(cadena.size);
	memcpy(str, cadena.str, cadena.size + 1); //Copies block of memory
}

String::String(const char *format, ...)
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

//Operators:


bool String::operator== (const String& cadena) const{

	return strcmp(cadena.str, str) == 0;
}


bool String::operator== (const char* cadena) const{

	return strcmp(cadena, str) == 0;
}


bool String::operator!= (const String& cadena) const{

	return strcmp(cadena.str, str) != 0;
}


bool String::operator!= (const char* cadena) const{

	return strcmp(cadena, str) != 0;
}


String& String::operator= (const char* cadena) {

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


String& String::operator= (const String& cadena) {

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



String& String::operator+= (const String& cadena){
	
	String string;
	String& tmp(string);

	tmp.Alloc(strlen(str) + 1);
	strcpy_s(tmp.str, strlen(str) + 1, str);

	Alloc(strlen(cadena.str) + tmp.size + 1); //We reserve memory for both sentences		

	strcpy_s(str, strlen(tmp.str) + tmp.size + 1, tmp.str);

	strcat_s(str, strlen(cadena.str) + tmp.size + 1, cadena.str);


	return (*this);
}


String& String::operator+= (const char* cadena){
	
	if (cadena != NULL)
	{

		String tmp;

		tmp.Alloc(strlen(str) + 1);
		strcpy_s(tmp.str, strlen(str) + 1, str);

		Alloc(strlen(cadena) + tmp.size + 1);

		strcpy_s(str, strlen(tmp.str) + tmp.size + 1, tmp.str);

		strcat_s(str, strlen(cadena) + tmp.size + 1, cadena);


	}
	return (*this);
}
