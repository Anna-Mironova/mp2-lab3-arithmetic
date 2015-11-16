#include "C:\Users\����\Documents\mp2-lab3-arithmetic\include\arithmetic.h"

void PartitionIntoLexemes(char *s)
{
	int k=0; int l=0; int m=0;
	int len = strlen(s);
	int type[256];
	double digits[256];
	char vars[256];
	char signs[256];

	for (int i=0;i<256;i++)
	{
		type[i]=0;
		digits[i]=0;
	}
		
	for (int i=0;i<len;i++)
		type[i]=DeterminationType(s[i]);
	for (int i=0;i<len;i++)
	{
		if(type[i]==1)
		{
			digits[k] = std::stod(s[i]) ;
			k++;
		}
		else if(type[i]==2)
		{
			vars[l]=s[i];
			l++;
		}
		else if (type[i]==3)
		{
			signs[m]=s[i];
			m++;
		}
	}
}
int DeterminationType(char s) //type1-�����; type2-����� ; type3-����� ��������;
{
	int flag=0;
	char sign[]="-+*/()";
	if ( isdigit(s) )
		return 1;
	else if ( isalpha(s) )
		return 2;
	else 
	{
		for(int i=0;i<6;i++)
			if (s==sign[i])
			{
				flag=1;
				break;
			}
		if(flag ==1)
			return 3;
		else 
		{
			cout << "������������ ������" <<endl;
			return 0;
		}
	}
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
	char sign[]="-+*/";
	int len=strlen(s);
	int flag=0;
	for (int i=1;i<4;i++)
	{
		if (s[0]==sign[i])
		{
			cout<< "���������� ��������� �� ������� � 1 " << endl;
			flag=1;
			break;
			
		}
	}
	for (int i=0;i<4;i++)
	{
		if (s[len-1]==sign[i])
		{
			cout<< "���������� ��������� �� ������� � " << len << endl;
			flag=1;
			break;
		}
	}
	if (flag==1)
		return false;
	else
		return true;
}
bool CheckOperationsInRow(char *s)//�������� �� ���-�� �������� ������
{
	char sign[]="-+*/";
	int len=strlen(s);
	int flag=0;
	for (int i=0;i<len;i++)
	{
		for(int j=0;j<4;j++)
			if (s[i]==sign[j])
			{
				for(int j=0;j<4;j++)
					if (s[i+1]==sign[j])
					{
						cout<< "��� ����� �������� ������ �� �������� � " << i+1 << " � " << i+2 << endl;
						flag=1;
						break;
					}
				if (flag==1)
					break;
			}
		if (flag==1)
			break;
	}
	if (flag==1)
		return false;
	else
		return true;
}