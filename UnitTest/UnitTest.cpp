#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_10.1/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestContainsThreeConsecutiveStars)
		{
            // Arrange
            const char* testFilename = "test.txt";

            // Act
            ofstream testFile(testFilename);
            testFile << "No stars here" << endl;
            testFile << "*** Three stars ***" << endl;
            testFile << "One * star" << endl;
            testFile << "Two ** stars" << endl;
            testFile << "No consecutive stars" << endl;
            testFile << "***** Consecutive stars *****" << endl;
            testFile.close();

            // Assert
            Assert::IsTrue(ContainsThreeConsecutiveStars(testFilename));

            // Arrange
            testFile.open(testFilename, ofstream::out | ofstream::trunc);
            testFile << "No consecutive stars" << endl;
            testFile.close();

            // Assert
            Assert::IsFalse(ContainsThreeConsecutiveStars(testFilename));
		}
	};
}
