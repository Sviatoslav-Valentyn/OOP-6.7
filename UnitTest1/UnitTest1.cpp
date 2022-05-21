#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 6.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[5] = { 1, 2, 3, 4, 5 };
			Predicate<int>* Foreach = new for_each<int>();
			Assert::AreEqual(1, a[0]);
		}
	};
}
