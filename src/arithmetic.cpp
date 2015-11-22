#include "C:\Users\����\Documents\mp2-lab3-arithmetic\include\arithmetic.h"
using namespace std;

int DeterminationType(char s) //type1-�����; type2-����� ; type3-����� �������� ; type 4 - ����� ��� ������� double
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
bool CheckBrackets(char* s)//�������� ������������ ������
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
				cout<< "������ � ������������ ������ �� ������� � " << i+1 << endl;
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
			cout << "������ � ������������ ������ �� �������(��) � " ;
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
bool CheckAmoutOperands(char* s)// �������� �� ���������� ���������
{
	int len=strlen(s);
	if (IsSign(s[0]))
	{
		cout<< "���������� ��������� �� ������� � 1 " << endl;
		return false;
	}
	else if (IsSign(s[len-1]))
	{
			cout<< "���������� ��������� �� ������� � " << len << endl;
			return false;
	}
	else
		return true;
}
bool CheckOperationsInRow(char *s)//�������� �� ���-�� �������� ������
{
	int len=strlen(s);
	int flag=0;
	for (int i=0;i<len;i++)
	{
		if (IsSign(s[i]))
		{
			if (IsSign(s[i+1]))
			{
				cout<< "��� ����� �������� ������ �� �������� � " << i+1 << " � " << i+2 << endl;
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

bool CheckPlaceDotsOrCommas(char* s)//�������� �� ���������� ����������� ����� � ������� � double
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
bool CheckCorrectnessOfSymbols(char *s)//�������� �� ������� ������������ ��������
{
	int len = strlen(s);
	int flag=0;
	int type[256];
	for (int i=0;i<len;i++)
		type[i]=DeterminationType(s[i]);
	for (int i=0;i<len;i++)
		if(type[i]==0)
		{
			cout << "������������ ������" <<endl;
			flag=1;
			break;
		}
	if (flag==1)
		return false;
	else
		return true;

}
bool CheckStr(char* s)//�������� ���� ������� 
{
	if((CheckBrackets(s))&&(CheckAmoutOperands(s))&&(CheckOperationsInRow(s))&&(CheckPlaceDotsOrCommas(s))&&(CheckCorrectnessOfSymbols(s)))
		return true;
	else
		return false;
}

int Prioritet(char s)//��������� ��������
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

bool IsSign(char s)// ����������� ���� �������� ��� ���
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
bool IsOperation(char s)//����������� ���� �������� ��� ��� ��� ������
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

char* FindVars (char *s)//���������� ���������� � �������
{
	char newvars[256];
	char vars[256];
	int size,m,p;
	int j=0;
	int len = strlen(s);
	int type[256];
	for (int i=0;i<len;i++)
		type[i]=DeterminationType(s[i]);
	for (int i=0;i<len;i++)
		if(type[i]==2)
		{
			vars[j]=s[i];
			j++;
		}
	vars[j]='\0';
	size=strlen(vars);
    for(int i=0;i<size;i++)
    {
        for(int k=0;k<i;k++)
        {
            if(vars[i]==newvars[k])
            m=1;
        }
        if(m==0)
            newvars[p]=vars[i];
        p++;
        m=0;
    }	
	newvars[p]='\0';
	return newvars;
}
void InputValues(char *s) //������� ��� ����� �������� ����������
{
	int len=strlen(s);
	cout << "������� �������� ����������" <<endl;
	for (int i=0;i<len;i++)
	{
		cout << s[i]<< "=";
		cin >> s[i];
		cout <<endl;
	}
}

double* ArrayOfNumbers(char *s)//������ ��������� 
{
	int i=0;
	int j=0;
	int k=0;
	double res[256];
	for (int k=0;k<256;k++)
		res[k]=0;
	int len=strlen(s);
	int type[256];
	for (int j=0;j<len;j++)
		type[j]=DeterminationType(s[j]);
	while(s[i]!='\0')
	{
		if((type[i]==1))
		{ 
			double number;
			int l;
			char str[256];
			k=i+1;
			while ((type[k]!=3)||(type[k]!=2))
			{
				k++;
			}
			l=k-i;
			for (int j=0;j<l;j++)
				str[j]=s[i+j];
			str[l]='\0';
			number=GetNumber(str);	
			i+=l;
			
			res[j]=number;
			j++;
		}
		else
			i++;
	}
	return res;
}
char* ChangeOperand(char *s)
{
	char res [256];
	int k=0; int m=0; int p=0; int l=0;
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
			while ((type[p]!=3)||(type[p]!=2))
			{
				p++;
			}
			l=p-i;	
			i+=l;
			res[k]=m;
			m++;
		}
		k++;
	}
	return res;	
}

char* ConvertInPostfixNotation(char* s)//������� � ����������� ������
{
	TStack<char> sg(256);
	char res[256];
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
	return res;
}
double GetNumber(char *s)
{
	double res=atof(s);
	return res;
}
double EvaluationOfExpression(char *s,double *arr)//���������� ���������
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