//main_stack
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>

using namespace std;


int main()
{
	int res;
	TStack <int> v(5);
	setlocale(LC_ALL, "Russian");
	v.Include(5);
	v.Include(10);
	v.Include(15);
	v.Include(20);
	v.Include(25);
	cout << "Стек : " << v << endl;
	res=v.Exclude();
	cout << "res = " << res << endl;
	cout << "Стек : " << v << endl;
	res=v.Get();
	cout << "res = " << res << endl;
	cout << "Стек : " << v << endl;
}
