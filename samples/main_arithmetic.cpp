#include "arithmetic.h"
#include <iostream>
#define MAX_SIZE 256;
int main()
{
	char str[]="5+6.5*(a+b*2)";
	int Size=MAX_SIZE;
	setlocale(LC_ALL, "Russian");

	if(CheckStr(str)!=true)
		cout << "Выражение некорректно! Введите выражение заново " <<endl;
	else
	{
		double result;
		char * vars;
		double *numbers;
		char * newstr1 ;
		char * newstr2 ;

		numbers=new double[Size];
		InputValues(str);
		ArrayOfNumbers(str,numbers);
		for (int i=0;i<3;i++)
			cout << numbers[i] << endl;
		newstr1 = new char [Size];
		ChangeOperand(str,newstr1);
		cout << newstr1 << endl;
		newstr2 = new char [Size];
		ConvertInPostfixNotation(newstr1,newstr2);
		cout << newstr2 << endl;	
		result=EvaluationOfExpression(newstr2,numbers);
		cout << "Результат выражения = " << result <<endl;
		delete []numbers;
		delete []newstr1;
		delete []newstr2;
	}
  return 0;
}