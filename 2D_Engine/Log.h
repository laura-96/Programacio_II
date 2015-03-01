#ifndef __LOG_H__
#define __LOG_H__

#include <Windows.h>
#include <stdio.h>
#include <assert.h>

class Log {

public:
	
	Log(){}


	void LogPrint(const char file[], int line, const char* format, ...)
	{

		assert(format != 0);	//Makes sure the format is different from 0
		int nSize = 0;
		static char buff[5000];
		static char finalString[5000];
		memset(finalString, 0, sizeof(finalString)); //Reserves memory
		memset(buff, 0, sizeof(buff));



		static va_list args; // It collects all the arguments

		va_start(args, format);
		nSize = vsnprintf_s(buff, _countof(buff), _TRUNCATE, format, args);
		if (nSize < 0)
		{
			printf("Error");
		}



		sprintf_s(finalString, 4096, "\n%s(%d) - Message: %s\n", file, line, buff);
		OutputDebugString(finalString);

		va_end(args);

	}

	~Log(){}
};

#endif