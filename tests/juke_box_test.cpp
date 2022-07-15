#include "some_class.h"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>


using namespace std;

TEST(SomeLibTest, basic_test)
{
	app::SomeClass cls;

	auto expected = 1;

	auto actual = cls.GetNum();

	EXPECT_EQ(actual, expected);
}


TEST(SomeLibTest1, basic_test)
{
	const char* filename = "example.txt";
	fstream infile(filename, ios::in);

	if (infile.is_open()) {

		unsigned int a;
		infile >> hex >> a;
		cout << hex << a;
	}
	else {
		cout << "couldnt open file!" << endl;
	}

}