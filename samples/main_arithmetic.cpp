#include "arithmetic.h"
#include <iostream>
#define MAX_SIZE 256;
int main()
{
	char str [256];
	int Size=MAX_SIZE;
	int flag1 =1; int flag3=1; int p=0; 
	char * newstr ;

	setlocale(LC_ALL, "Russian");

	newstr = new char [Size];
	cout << "�����������,����������� ���������� ��������������� ��������� � ������������� �������." <<endl;
	cout << "��������� � �������� ��������� ����� ��������� ���������� � ������������ �����, � ��� ����� � �������������." <<endl;
	cout << "�������� ���������� ����� ��������� ������ ���� �����." <<endl;
	cout << "���������� �������� : +, -, /, *, ^. " <<endl;
	while (flag1==1)
	{
		cout << "������� ��������� : ";
		gets(str);
		ReplacementPointToCommaInDouble(str);
		if(ThereIsUnaryMinus(str))
		{
			ProcessingUnaryMinus(str,newstr);
		}
		else
		{
			int i=0;
			while(str[i]!='\0')
			{
				newstr[i]=str[i];
				i++;
			}
			newstr[i]='\0';
		}

		if(CheckStr(newstr)!=true)
			cout << "��������� �����������! ������� ��������� ������ " <<endl;
		else
		{
			double result;
			int flag2=1; 
			char * newstr1 ;
			char * newstr2 ;
			newstr1 = new char [Size];
			newstr2 = new char [Size];
			ConvertInPostfixNotation(newstr,newstr1);
			while (flag2==1)
			{
				InputValues(newstr1,newstr2);
				ReplacementPointToCommaInDouble(newstr2);
				result=EvaluationOfExpression(newstr2);
				cout << "��������� ��������� = " << result <<endl;
				if(ThereAreVars(str))
				{
					cout << "������ ����������� ������ ��������� ��� ������ ��������� ����������? " <<endl;
					cout << "1.��" <<endl;
					cout << "2.���" <<endl;
					cin  >> p;
					if (p==2)
						flag2=0;
				}
				else
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