#include "C:\Users\Анна\Documents\mp2-lab3-arithmetic\include\arithmetic.h"

bool CheckBrackets(char* s) 
{
	TStack<int> br(256);
	int len;
	len=strlen(s);
	for (int i=0;i<len;i++)
	{
		if (s[i]=='(')
			br.Include(i);
		else if(s[i]==')')
		{
			if (br.CheckEmpty())
			{
				cout<< "Ошибка в расставлении скобок на позиции № " << i << endl;
				break;
			}
			else
			{
				br.Exclude();
			}
				
		}
	}
	if(br.CheckEmpty())
		return true;
	else 
	{
		cout << "Ошибка в расставлении скобок на позиции(ях) № " ;
		while (br.CheckEmpty()!=true)
		{
			int res;
			res=br.Exclude();
			cout << res << ";";
		}
		cout << endl; 
		return false;
	}		
}
bool CheckAmoutOperands(char* s)
{
	return true;
}