#include <gtest/gtest.h>

#include <adder.h>

TEST(Adder, add_two_positive_integers)
{
	Adder adder;

	const int expected = 3;
	int actual = adder.add(1, 2);

	ASSERT_EQ(expected, actual);
}
