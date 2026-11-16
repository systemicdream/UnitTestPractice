/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, has_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Password");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, has_mixed_case_all_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("password");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, has_mixed_case_all_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("PASSWORD");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, has_mixed_case_one_upper_rest_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("pASSWORd");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, has_mixed_case_with_digits)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Pass123!");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, has_mixed_case_no_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("123456!");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, has_mixed_case_empty)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}