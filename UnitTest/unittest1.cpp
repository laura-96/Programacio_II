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
			Assert::IsTrue(punt.IsZero());
		}

		TEST_METHOD(DistanceTo)
		{
			Point2d a;
			Point2d b;
			Point2d c;

			a.x = 2;
			a.y = 0;
			b.x = 2;
			b.y = 0;
			c.x = 4;
			c.y = 0;
			float dist1 = a.DistanceTo(b);
			float dist2 = a.DistanceTo(c);
			
			Assert::AreEqual(dist1, 0.0f);
			Assert::AreEqual(dist2, 2.0f);
		}
		
		TEST_METHOD(suma)
		{
			Point2d a;
			Point2d b;

			a.x = 2;
			a.y = 0;
			b.x = 4;
			b.y = (-3);
			
			Point2d sum = a.operator+(b);

			Assert::AreEqual(sum.x, 6.0f);
			Assert::AreEqual(sum.y, -3.0f);

		}

		TEST_METHOD(resta)
		{
			Point2d a;
			Point2d b;

			a.x = 2;
			a.y = 0;
			b.x = 4;
			b.y = (-3);

			Point2d res = a.operator-(b);

			Assert::AreEqual(res.x, -2.0f);
			Assert::AreEqual(res.y, 3.0f);

		}

		TEST_METHOD(increase)
		{
			Point2d a;
			Point2d b;

			a.x = 2;
			a.y = 0;
			b.x = 4;
			b.y = (-3);

			a.operator+=(b);

			Assert::AreEqual(a.x, 6.0f);
			Assert::AreEqual(a.y, -3.0f);

		}

		TEST_METHOD(decrease)
		{
			Point2d a;
			Point2d b;

			a.x = 2;
			a.y = 0;
			b.x = 4;
			b.y = (-3);

			a.operator-=(b);

			Assert::AreEqual(a.x, -2.0f);
			Assert::AreEqual(a.y, 3.0f);

		}

		TEST_METHOD(EqualTo)
		{
			Point2d punt;
			punt.SetZero();
			Point2d pt;
			pt.SetZero();
			bool equal = pt.operator==(punt);
			Assert::IsTrue(equal);
		}

		TEST_METHOD(DifferentFrom)
		{
			Point2d punt;
			punt.SetZero();
			Point2d pt;
			pt.SetZero();
			bool diff = pt.operator!=(punt);
			Assert::IsFalse(diff);
		}
	};
}