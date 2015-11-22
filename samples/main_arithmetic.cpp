#include "arithmetic.h"

int main()
{
    int len;    //длина строки
	int size=MAX_SIZE;
	char str[]="5+6*(a+b*2)";
	char * nstr ;
	int s;
	


	setlocale(LC_ALL, "Russian");
	
	nstr = new char [size];
	nstr=ConvertInPostfixNotation(str);
	

  return 0;
}