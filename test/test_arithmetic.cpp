#include <gtest.h>
#include "arithmetic.h"

TEST(Arithmetic,can_identify_type)
{
	int types [5];
	char str[]="6.5*a";
	for (int i=0;i<5;i++)
		types[i]=DeterminationType(str[i]);
	EXPECT_EQ(1,types[0]);
	EXPECT_EQ(4,types[1]);
	EXPECT_EQ(1,types[2]);
	EXPECT_EQ(3,types[3]);
	EXPECT_EQ(2,types[4]);
}

TEST(Arithmetic,can_check_brackets)
{
	char str[]="(6.5+b)*a";
	EXPECT_TRUE(CheckBrackets(str));
}

TEST(Arithmetic,can_check_amout_of_operands)
{
	char str[]="5+";
	EXPECT_TRUE(!CheckAmountOperands(str));
}

TEST(Arithmetic,can_check_operations_in_row)
{
	char str[]="5+*a+b";
	EXPECT_TRUE(!CheckOperationsInRow(str));
}

TEST(Arithmetic,can_check_place_dots_or_commas)
{
	char str[]="5.2+a-2";
	EXPECT_TRUE(CheckPlaceDotsOrCommas(str));
}

TEST(Arithmetic,can_check_correctness_of_symbols)
{
	char str[]="5+2&a*b";
	EXPECT_TRUE(!CheckCorrectnessOfSymbols(str));
}
TEST(Arithmetic,can_check_str_at_all)
{
	char str[]="(5+2&a*b*";
	EXPECT_TRUE(!CheckStr(str));
}

TEST(Arithmetic,can_identify_prioritet)
{
	int pr;
	char str[]="6.5*a";
	pr=Prioritet(str[3]);
	EXPECT_EQ(2,pr);
}

TEST(Arithmetic,can_identify_sign)
{
	char str[]="(6.5*a)+5";
	EXPECT_TRUE(IsSign(str[0]));
}

TEST(Arithmetic,can_identify_operation)
{
	char str[]="(6.5*a)+5";
	EXPECT_TRUE(IsOperation(str[4]));
}
