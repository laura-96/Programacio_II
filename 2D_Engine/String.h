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

	const char* GetString() const { return str; }

public:

	//Constructors:

	String();
	String(const String& cadena);
	String(const char *format, ...);

	//Operators

	bool operator== (const String& cadena) const;
	bool operator== (const char* cadena) const;
	bool operator!= (const String& cadena) const;
	bool operator!= (const char* cadena) const;
	String& operator= (const char* cadena);
	String& operator= (const String& cadena);
	String& operator+= (const char* cadena);
	String& operator+= (const String& cadena);

	//Destructor
	virtual	~String()
	{
		delete[] str;
	}
};

#endif
