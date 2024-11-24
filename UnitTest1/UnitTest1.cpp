#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../PR8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TransformStringTests
{
    TEST_CLASS(TransformStringTests)
    {
    public:

        TEST_METHOD(TestRemoveLeadingAndTrailingSpaces)
        {
            std::string input = "   Hello World   ";
            std::string expected = "Hello World";
            Assert::AreEqual(expected, TransformString(input));
        }

        TEST_METHOD(TestCollapseInternalSpaces)
        {
            std::string input = "Hello    World   !";
            std::string expected = "Hello World !";
            Assert::AreEqual(expected, TransformString(input));
        }

        TEST_METHOD(TestNoSpaces)
        {
            std::string input = "HelloWorld";
            std::string expected = "HelloWorld";
            Assert::AreEqual(expected, TransformString(input));
        }

        TEST_METHOD(TestAllSpaces)
        {
            std::string input = "      ";
            std::string expected = "";
            Assert::AreEqual(expected, TransformString(input));
        }

        TEST_METHOD(TestEmptyString)
        {
            std::string input = "";
            std::string expected = "";
            Assert::AreEqual(expected, TransformString(input));
        }

        TEST_METHOD(TestSingleSpaceBetweenWords)
        {
            std::string input = "This is a test.";
            std::string expected = "This is a test.";
            Assert::AreEqual(expected, TransformString(input));
        }
    };
}
