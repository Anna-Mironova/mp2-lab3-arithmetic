#include "C:\Users\����\Documents\mp2-lab3-arithmetic\include\arithmetic.h"

void PartitionIntoLexemes(char *s)
{
	

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