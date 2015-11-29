#include <gtest.h>
#include "arithmetic.h"

TEST(Arithmetic,can_identify_type)
{
	int types [6];
	char str[]="6.5*a ";
	for (int i=0;i<6;i++)
		types[i]=DeterminationType(str[i]);
	EXPECT_EQ(1,types[0]);
	EXPECT_EQ(4,types[1]);
	EXPECT_EQ(1,types[2]);
	EXPECT_EQ(3,types[3]);
	EXPECT_EQ(2,types[4]);
	EXPECT_EQ(5,types[5]);
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

TEST(Arithmetic,can_identify_unary_minus)
{
	char str[]="(-6.5*a)+5";
	EXPECT_TRUE(ThereIsUnaryMinus(str));
}

TEST(Arithmetic,can_process_unary_minus_at_the_beginning)
{
	char str[]="-6*a";
	char newstr[256];
	ProcessingUnaryMinus(str,newstr);
	EXPECT_EQ('0',newstr[0]);
	EXPECT_EQ('-',newstr[1]);
	EXPECT_EQ('6',newstr[2]);
	EXPECT_EQ('*',newstr[3]);
	EXPECT_EQ('a',newstr[4]);
}

TEST(Arithmetic,can_process_unary_minus_after_open_bracket)
{
	char str[]="5+(-6)";
	char newstr[256];
	ProcessingUnaryMinus(str,newstr);
	EXPECT_EQ('5',newstr[0]);
	EXPECT_EQ('+',newstr[1]);
	EXPECT_EQ('(',newstr[2]);
	EXPECT_EQ('0',newstr[3]);
	EXPECT_EQ('-',newstr[4]);
	EXPECT_EQ('6',newstr[5]);
	EXPECT_EQ(')',newstr[6]);
}

TEST(Arithmetic,can_get_number)
{
	char str[]="6.5";
	EXPECT_EQ(6.5,GetNumber(str));
}

TEST(Arithmetic,can_find_vars)
{
	char str[]="6.5+a*(b+c)";
	int res[4];
	for(int i=0;i<4;i++)
		res[i]=-1;
	FindVars(str,res);
	EXPECT_EQ(4,res[0]);
	EXPECT_EQ(7,res[1]);
	EXPECT_EQ(9,res[2]);
	EXPECT_EQ(-1,res[3]);
}

TEST(Arithmetic,can_input_one_digit_number) //вводить 1
{
	char str[]="6.5+a";
	char newstr[15];
	char newstr1[15];
	ConvertInPostfixNotation(str,newstr);
	InputValues(newstr,newstr1);
	EXPECT_EQ('6',newstr1[0]);
	EXPECT_EQ('.',newstr1[1]);
	EXPECT_EQ('5',newstr1[2]);
	EXPECT_EQ(' ',newstr1[3]);
	EXPECT_EQ('1',newstr1[4]);
	EXPECT_EQ(' ',newstr1[5]);
	EXPECT_EQ('+',newstr1[6]);
}
TEST(Arithmetic,can_input_multi_digit_number)//вводить 100
{
	char str[]="6.5+a";
	char newstr[15];
	char newstr1[15];
	ConvertInPostfixNotation(str,newstr);
	InputValues(newstr,newstr1);
	EXPECT_EQ('6',newstr1[0]);
	EXPECT_EQ('.',newstr1[1]);
	EXPECT_EQ('5',newstr1[2]);
	EXPECT_EQ(' ',newstr1[3]);
	EXPECT_EQ('1',newstr1[4]);
	EXPECT_EQ('0',newstr1[5]);
	EXPECT_EQ('0',newstr1[6]);
	EXPECT_EQ(' ',newstr1[7]);
	EXPECT_EQ('+',newstr1[8]);
}
TEST(Arithmetic,can_input_negative_number)//вводить -1
{
	char str[]="6.5+a";
	char newstr[15];
	char newstr1[15];
	ConvertInPostfixNotation(str,newstr);
	InputValues(newstr,newstr1);
	EXPECT_EQ('6',newstr1[0]);
	EXPECT_EQ('.',newstr1[1]);
	EXPECT_EQ('5',newstr1[2]);
	EXPECT_EQ(' ',newstr1[3]);
	EXPECT_EQ('0',newstr1[4]);
	EXPECT_EQ(' ',newstr1[5]);
	EXPECT_EQ('1',newstr1[6]);
	EXPECT_EQ(' ',newstr1[7]);
	EXPECT_EQ('-',newstr1[8]);
	EXPECT_EQ('+',newstr1[9]);	
}

TEST(Arithmetic,can_convert_in_postfix_notation)
{
	char str[]="6.5+a";
	char newstr[15];
	ConvertInPostfixNotation(str,newstr);
	EXPECT_EQ('6',newstr[0]);
	EXPECT_EQ('.',newstr[1]);
	EXPECT_EQ('5',newstr[2]);
	EXPECT_EQ(' ',newstr[3]);
	EXPECT_EQ('a',newstr[4]);
	EXPECT_EQ(' ',newstr[5]);
	EXPECT_EQ('+',newstr[6]);	
}

TEST(Arithmetic,can_add_values)
{
	char str[]="6.5+5";
	double res;
	char newstr[15];
	ConvertInPostfixNotation(str,newstr);
	res=EvaluationOfExpression(newstr);
	EXPECT_EQ(11.5,res);	
}
TEST(Arithmetic,can_subtract_values)
{
	char str[]="6.5-5";
	double res;
	char newstr[15];
	ConvertInPostfixNotation(str,newstr);
	res=EvaluationOfExpression(newstr);
	EXPECT_EQ(1.5,res);	
}
TEST(Arithmetic,can_multiply_values)
{
	char str[]="6.5*2";
	double res;
	char newstr[15];
	ConvertInPostfixNotation(str,newstr);
	res=EvaluationOfExpression(newstr);
	EXPECT_EQ(13,res);	
}
TEST(Arithmetic,can_divide_values)
{
	char str[]="13/2";
	double res;
	char newstr[15];
	ConvertInPostfixNotation(str,newstr);
	res=EvaluationOfExpression(newstr);
	EXPECT_EQ(6.5,res);	
}
TEST(Arithmetic,can_involute_values)
{
	char str[]="2^5";
	double res;
	char newstr[15];
	ConvertInPostfixNotation(str,newstr);
	res=EvaluationOfExpression(newstr);
	EXPECT_EQ(32,res);	
}

TEST(Arithmetic,can_calculate_expression_with_brackets)
{
	char str[]="(5+2*7)*3-21";
	double res;
	char newstr[50];
	ConvertInPostfixNotation(str,newstr);
	res=EvaluationOfExpression(newstr);
	EXPECT_EQ(36,res);	
}
TEST(Arithmetic,can_calculate_expression_without_brackets)
{
	char str[]="5+2*7*3-21";
	double res;
	char newstr[50];
	ConvertInPostfixNotation(str,newstr);
	res=EvaluationOfExpression(newstr);
	EXPECT_EQ(26,res);	
}
TEST(Arithmetic,can_replacement_point_to_comma)
{
	char str[]="5.2";
	ReplacementPointToCommaInDouble(str);
	EXPECT_EQ(',',str[1]);	
}
TEST(Arithmetic,can_identify_vars)
{
	char str[]="(5*a)+2";
	EXPECT_TRUE(ThereAreVars(str));
}
