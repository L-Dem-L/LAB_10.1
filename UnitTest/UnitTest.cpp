#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_10.1/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        TEST_METHOD(TesthasTripleStars)
        {
            // Create a temporary file with triple stars
            std::ofstream tempFile("temp.txt");
            tempFile << "This is a *** test file *** with triple stars." << std::endl;
            tempFile.close();

            // Test if the function detects triple stars in the temporary file
            Assert::IsTrue(hasTripleStars("temp.txt"));

            // Delete the temporary file
            std::remove("temp.txt");

        }
    };
}
