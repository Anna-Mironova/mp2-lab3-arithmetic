#include "arithmetic.h"
#include <iostream>
#define MAX_SIZE 256;
int main()
{
	char str [256];
	int Size=MAX_SIZE;
	int flag1=1; int flag2=1; int p=0;int i=0;
	char * newstr ;

	setlocale(LC_ALL, "Russian");

	newstr = new char [Size];
	while (flag1==1)
	{
		cout << "Введите выражение : ";
		gets(str);
		if(ThereIsUnaryMinus(str))
		{
			ProcessingUnaryMinus(str,newstr);
		}
		else
		{
			while(str[i]!='\0')
			{
				newstr[i]=str[i];
				i++;
			}
			newstr[i]='\0';
		}
		if(CheckStr(newstr)!=true)
			cout << "Выражение некорректно! Введите выражение заново " <<endl;
		else
		{
			double result;
			char * newstr1 ;
			char * newstr2 ;
			newstr1 = new char [Size];
			newstr2 = new char [Size];
			ConvertInPostfixNotation(newstr,newstr1);
			cout << newstr1 << endl;
			while (flag2==1)
			{
				InputValues(newstr1,newstr2);
				result=EvaluationOfExpression(newstr2);
				cout << "Результат выражения = " << result <<endl;
				cout << "Хотите пересчитать данное выражение при других значениях параметров? " <<endl;
				cout << "1.Да" <<endl;
				cout << "2.Нет" <<endl;
				cin  >> p;
				if (p==2)
					flag2=0;
			}
			flag1=0;
			delete []newstr1;
			delete []newstr2;
		}
	}
	delete []newstr;
  return 0;
}
