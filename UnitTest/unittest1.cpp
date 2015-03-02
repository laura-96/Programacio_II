#include "stdafx.h"
#include "CppUnitTest.h"

#include "../2D_Engine/Point2d.h"
#include "../2D_Engine/Point2d.cpp"
#include "../2D_Engine/String.h"
#include "../2D_Engine/String.cpp"
#include "../2D_Engine/Log.h"
#include "../2D_Engine/Log.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(SetZero)
		{
			Point2d punt;
			punt.SetZero();
			Assert::IsTrue(punt.x == 0.0f && punt.y == 0.0f);
		}

		TEST_METHOD(IsZero)
		{
			Point2d punt;
			punt.SetZero();
			Assert::IsTrue(punt.x == 0.0f && punt.y == 0.0f);
		}

	};
}