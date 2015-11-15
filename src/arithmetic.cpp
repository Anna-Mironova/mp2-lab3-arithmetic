#include "C:\Users\Анна\Documents\mp2-lab3-arithmetic\include\arithmetic.h"

void PartitionIntoLexemes(char *s)
{
	

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
	char sign[]="-+*/";
	int len=strlen(s);
	int flag=0;
	for (int i=1;i<4;i++)
	{
		if (s[0]==sign[i])
		{
			cout<< "Недостаток операндов на позиции № 1 " << endl;
			flag=1;
			break;
			
		}
	}
	for (int i=0;i<4;i++)
	{
		if (s[len-1]==sign[i])
		{
			cout<< "Недостаток операндов на позиции № " << len << endl;
			flag=1;
			break;
		}
	}
	if (flag==1)
		return false;
	else
		return true;
}
bool CheckOperationsInRow(char *s)//проверка на кол-во операций подряд
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
						cout<< "Два знака операции подряд на позициях № " << i+1 << " и " << i+2 << endl;
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