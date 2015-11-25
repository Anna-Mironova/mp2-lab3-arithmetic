#include "arithmetic.h"
#include <iostream>
#define MAX_SIZE 256;
int main()
{
	char str[]="5+6,5*(a+b*2)";
	int Size=MAX_SIZE;
	setlocale(LC_ALL, "Russian");

	if(CheckStr(str)!=true)
		cout << "Выражение некорректно! Введите выражение заново " <<endl;
	else
	{
		double result;
		char * newstr ;
		newstr = new char [Size];
		ConvertInPostfixNotation(str,newstr);
		cout << newstr << endl;	
		InputValues(newstr);
		result=EvaluationOfExpression(newstr);
		cout << "Результат выражения = " << result <<endl;
		delete []newstr;
	}
  return 0;
}
