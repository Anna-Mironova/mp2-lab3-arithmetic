#include "C:\Users\Анна\Documents\mp2-lab3-arithmetic\include\arithmetic.h"
using namespace std;

int DeterminationType(char s) //type1-цифра; type2-буква ; type3-знаки операций ; type 4 - точка или запятая double
{
	if ( isdigit(s) )
		return 1;
	else if ( isalpha(s) )
		return 2;
	else if(IsSign(s))
		return 3;
	else if((s=='.')||(s==','))
		return 4;
	else 
		return 0;
}
bool CheckBrackets(char* s)//проверка расставления скобок
{
	TStack<int> br(256);
	int len=strlen(s);
	int flag=0;
	for (int i=0;i<len;i++)
	{
		if (s[i]=='(')
			br.Include(i);
		else if(s[i]==')')
		{
			if (br.CheckEmpty())
			{
				cout<< "Ошибка в расставлении скобок на позиции № " << i+1 << endl;
				flag=1;
				break;
			}
			else
			{
				br.Exclude();
			}
				
		}
	}
	if (flag==1)
		return false; 
	else 
	{
		if(br.CheckEmpty())
			return true;
		else 
		{
			cout << "Ошибка в расставлении скобок на позиции(ях) № " ;
			while (br.CheckEmpty()!=true)
			{
				int res;
				res=br.Exclude();
				res++;
				cout << res << ";";
			}
			cout << endl; 
			return false;
		}
	}
}
bool CheckAmoutOperands(char* s)// проверка на недостаток операндов
{
	int len=strlen(s);
	if (IsOperation(s[0]))
	{
		cout<< "Недостаток операндов на позиции № 1 " << endl;
		return false;
	}
	else if (IsOperation(s[len-1]))
	{
			cout<< "Недостаток операндов на позиции № " << len << endl;
			return false;
	}
	else
		return true;
}
bool CheckOperationsInRow(char *s)//проверка на кол-во операций подряд
{
	int len=strlen(s);
	int flag=0;
	for (int i=0;i<len;i++)
	{
		if (IsOperation(s[i]))
		{
			if (IsOperation(s[i+1]))
			{
				cout<< "Два знака операции подряд на позициях № " << i+1 << " и " << i+2 << endl;
				flag=1;
				break;
			}
		}
	}
	if (flag==1)
		return false;
	else
		return true;
}

bool CheckPlaceDotsOrCommas(char* s)//проверка на правильную расстановку точек и запятых у double
{
	int len = strlen(s);
	int flag=0;
	int type[256];
	for (int i=0;i<len;i++)
		type[i]=DeterminationType(s[i]);
	if ((type[0]==4)||(type[len-1]==4))
		return false;
	else 
	{
		for (int i=1;i<len-1;i++)
			if(type[i]==4)
			{
				if((type[i-1]!=1)||(type[i+1]!=1))
					flag=1;
					break;
			}
		if(flag==1)
			return false;
		else 
			return true;
	}	
}
bool CheckCorrectnessOfSymbols(char *s)//проверка на наличие некорректных символов
{
	int len = strlen(s);
	int flag=0;
	int type[256];
	for (int i=0;i<len;i++)
		type[i]=DeterminationType(s[i]);
	for (int i=0;i<len;i++)
		if(type[i]==0)
		{
			cout << "Неопознанный символ" <<endl;
			flag=1;
			break;
		}
	if (flag==1)
		return false;
	else
		return true;

}
bool CheckStr(char* s)//проверка всех условий 
{
	if((CheckBrackets(s))&&(CheckAmoutOperands(s))&&(CheckOperationsInRow(s))&&(CheckPlaceDotsOrCommas(s))&&(CheckCorrectnessOfSymbols(s)))
		return true;
	else
		return false;
}

int Prioritet(char s)//приоритет операций
{
	switch(s)
	{
	case '(' :
		{
			return 0;
			break;
		}
	case '+':
		{
			return 1;
			break;
		}
	case '-':
		{
			return 1;
			break;
		}
	case '*':
		{
			return 2;
			break;
		}
	case '/':
		{
			return 2;
			break;
		}
	case '^':
		{
			return 3;
			break;
		}
	}
}

bool IsSign(char s)// определение знак операции или нет
{
	int flag=0;
	char sign[]="-+*/()^";
	for(int i=0;i<7;i++)
		if (s==sign[i])
		{
			flag=1;
			break;
		}
	if(flag ==1)
		return true ;
	else 
		return false;
}
bool IsOperation(char s)//определение знак операции или нет без скобок
{
	int flag=0;
	char sign[]="-+*/^";
	for(int i=0;i<5;i++)
		if (s==sign[i])
		{
			flag=1;
			break;
		}
	if(flag ==1)
		return true ;
	else 
		return false;
}

void FindVars (const char *s, int * res)//нахождение переменных в формуле
{
	int j=0;
	int len = strlen(s);
	int type[256];
	for (int i=0;i<len;i++)
		type[i]=DeterminationType(s[i]);
	for (int i=0;i<len;i++)
		if(type[i]==2)
		{
			res[j]=i;
			j++;
		}
}
void InputValues(char *s) //функция для ввода значений переменных
{
	int *num;
	int Size=256;
	int i=1;
	num=new int[Size];
	for (int j=0;j<Size;j++)
		num[j]=0;
	FindVars(s,num);
	int len=strlen(s);
	cout << "Введите значения переменных" <<endl;
	if (num[0]==0)
	{
		cout << s[num[0]]<< "=";
		cin >> s[num[0]];
		cout <<endl;
	}
	else 
		i=0;
	while (num[i]!=0)
	{
		cout << s[num[i]]<< "=";
		cin >> s[num[i]];
		cout <<endl;
		i++;
	}
}

void ChangeOperand(const char *s,char *res)//изменение операндов на более удобные
{
	char m[]="0123456789";
	int k=0; int n=0 ; int p=0; int l=0;
	int len=strlen(s);
	int type[256];
	for (int j=0;j<len;j++)
		type[j]=DeterminationType(s[j]);
	for (int i=0;i<len;)
	{
		if ((type[i]==3)||(type[i]==2))
		{
			res[k]=s[i];
			i++;
			
		}
		else if ((type[i]==1))
		{
			p=i+1;
			while ((type[p]!=3)&&(type[p]!=2))
			{
				p++;
			}
			l=p-i;	
			i+=l;
			res[k]=m[n];
			n++;
		}
		k++;
	}	
	res[k]='\0';
}
void ArrayOfNumbers(const char *s,double *res)//массив операндов 
{
	int i=0; int k=0; int m=0;
	for (int p=0;p<256;p++)
		res[p]=0;
	int len=strlen(s);
	int type[256];
	for (int j=0;j<len;j++)
		type[j]=DeterminationType(s[j]);
	while(s[i]!='\0')
	{
		if(type[i]==1)
		{ 
			double number;
			int l;
			char str[256];
			k=i+1;
			while ((type[k]!=3)&&(type[k]!=2))
			{
				k++;
			}
			l=k-i;
			for (int j=0;j<l;j++)
				str[j]=s[i+j];
			str[l]='\0';
			number=GetNumber(str);	
			i+=l;
			
			res[m]=number;
			m++;
		}
		else
			i++;
	}
}

double GetNumber(char *s)//получение числа из char
{
	double res=atof(s);
	return res;
}

void ConvertInPostfixNotation(const char* s,char *res)//перевод в постфиксную запись
{
	TStack<char> sg(256);
	int len = strlen(s);
	int type[256];
	for (int i=0;i<len;i++)
		type[i]=DeterminationType(s[i]);
	int j=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')
			sg.Include('(');
		if (s[i]==')')
		{
			char a =sg.Exclude();
			while (a !='(')
			{
				res[j]=a;
				j++;
				a=sg.Exclude();
			}
		}
		if(IsOperation(s[i]))
		{
			if (sg.CheckEmpty())
				sg.Include(s[i]);
			else 
			{
				char op = sg.Get();
				while(Prioritet(s[i])<=Prioritet(op))
				{
					res[j]=sg.Exclude();
					j++;
					op=sg.Exclude();
				}
				sg.Include(s[i]);
			}
		}
		if ((type[i]==1)||(type[i]==2))
		{
			res[j]=s[i];
			j++;
		}	
	}
	while(sg.CheckEmpty()!=true)
	{
		res[j]=sg.Exclude();
		j++;
	}
	res[j]='\0';
}

double EvaluationOfExpression(char *s,double *arr)//вычисление выражения
{
	TStack <char> op(256);
	TStack <double> num(256);
	int len=strlen(s);
	int i=0;
	int k=0;
	double res;
	int type[256];
	for (int j=0;j<len;j++)
		type[j]=DeterminationType(s[j]);
	while(s[i]!='\0')
	{
		if(type[i]==1)
		{ 
			char str[256];
			str[0]=s[i];
			str[1]='\0';
			int k=atoi(str);
			double number=arr[k];	
			num.Include(number);
		}
		if(type[i]==2)
		{
			num.Include(s[i]);
		}
		if (IsOperation(s[i]))
		{
			double opright,opleft;
			opright=num.Exclude();
			opleft=num.Exclude();
			switch(s[i])
			{
				case '+':
				{
					res=opleft+opright;
					break;
				}
				case '-':
				{
					res=opleft-opright;
					break;
				}
				case '*':
				{
					res=opleft*opright;
					break;
				}
				case '/':
				{
					res=opleft/opright;
					break;
				}
				case '^':
				{
					int op;
					op=(int)opright; 
					int count = 1; 
					res=opleft;
					do
					{
						if (op == 0)
							res = 1;
						else if ((op != 1) && (op > 0))
							res= res * opleft; 
						count++; 
					} 
					while ( op > count); 
					break;
				}
			}
			num.Include(res);
		}
		i++;
	}
	return num.Exclude();
}