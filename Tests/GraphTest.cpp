#include "pch.h"
#include "CppUnitTest.h"
#include "../course_project_4sem/EdmondsKarp.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphTest
{
	TEST_CLASS(GraphTest)
	{
	public:
		
		TEST_METHOD(input_exception)
		{

			EdmondsKarp_algorithm test;
			try
			{
				test.input("C:\\Users\\adelya\\source\\repos\\GraphTest\\tessst.txt");

			}

			catch (invalid_argument x)
			{
				Assert::AreEqual("Please start your graph with S and finish with T", x.what());

			}

		}

		TEST_METHOD(correct_maxflow)
		{
			EdmondsKarp_algorithm test;
			test.input("C:\\Users\\adelya\\source\\repos\\GraphTest\\test2.txt");
			int expected = 5;
			int inreal = test.maxflow();
			Assert::AreEqual(expected, inreal);
		}

		TEST_METHOD(emptyfile_exception)
		{
			EdmondsKarp_algorithm test;
			try {
				int max = test.maxflow();
			}
			catch (invalid_argument x)
			{
				Assert::AreEqual(x.what(), "Please enter data for the graph");
			}
		}

		TEST_METHOD(nofile_exception) {
			EdmondsKarp_algorithm test;
			try {
				test.input("Randomfilename.txt");
			}
			catch (runtime_error x) {
				Assert::AreEqual(x.what(), "File was not found, check its name/location");
			}
		}

		TEST_METHOD(noways_exception) {
			EdmondsKarp_algorithm test;
			test.input("C:\\Users\\adelya\\source\\repos\\GraphTest\\test3.txt");
			try {
				int k = test.maxflow();
			}
			catch (invalid_argument x) {
				Assert::AreEqual(x.what(), "There are no ways from S to T at all");
			}
		}

	};
}
