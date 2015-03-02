#ifndef __LOG_H__
#define __LOG_H__

#include <Windows.h>
#include <stdio.h>
#include <assert.h>
#include <wtypes.h>

#define log(format, ...) PrintLog(__FILE__, __LINE__, format, __VA_ARGS__);

class Log {

public:
	
	//Constructor
	Log();

	void PrintLog(const char file[], int line, const char* format, ...)
	{

		assert(format != 0);	//Makes sure the format is different from 0
		
		int nSize = 0;
		static char buffer_a[5000];
		static char buffer_b[5000];
		memset(buffer_a, 0, sizeof(buffer_a)); //Reserves memory
		memset(buffer_b, 0, sizeof(buffer_b));


		static va_list args; // It collects all the arguments
		
		va_start(args, format);
		
		nSize = vsnprintf_s(buffer_a, _countof(buffer_a), _TRUNCATE, format, args);
		if (nSize < 0)
		{
			printf("Error, that log is too long.");
		}


		va_end(args);

	}

	//Destructor:
	~Log(){}
};

#endif