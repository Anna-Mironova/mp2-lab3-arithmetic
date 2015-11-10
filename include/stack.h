#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 100000000;


template <class ValType>
class TStack
{
	public:
		ValType *pVector;
		int Size;       // размер стека
		int Top;        // индекс последнего элемента

		TStack(int s);	                          //конструктор инициализатор
		TStack(const TStack &v);                 //конструктор копирования
		~TStack();                               //деструктор

		void Include(const ValType i);          //добавить элемент
		ValType Exclude();                      // извлечь элемент с удалением
		ValType Get();                          // извлечь элемент без удаления
		bool CheckFull() const;                 //проверка на переполнение
		bool CheckEmpty() const;                //проверка на пустоту
		void Clear();                           //очистить стек
				
		// вывод
  friend ostream& operator<<(ostream &out, const TStack &v)
  {
    for (int i = 0; i < v.Top+1; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TStack<ValType>::TStack(int s)//конструктор инициализатор
{
	if (s<0)
		throw "Negative size";
	else if(s>MAX_STACK_SIZE)
		throw "Size more than MAX_VECTOR_SIZE";
	else
	{
		Top=-1;
		Size=s;
		pVector=new ValType[Size];
	}		
} 

template <class ValType> //конструктор копирования
TStack<ValType>::TStack(const TStack<ValType> &v)
{
	Size=v.Size;
	Top=v.Top;
	pVector=new ValType[Size];
	for (int i=0; i<Top; i++)
		pVector[i]=v.pVector[i];
} 

template <class ValType> //деструктор
TStack<ValType>::~TStack()
{
	if(pVector!=NULL)
		delete []pVector;	
}

template <class ValType>
void TStack<ValType>:: Include(const ValType i)//добавить элемент
{
	if(this->CheckFull())
		throw "Full stack" ;
	else
	{
		Top++;
		pVector[Top]=i;
	}
}
template <class ValType>
ValType TStack<ValType>::Exclude() // извлечь элемент с удалением
{
	if(this->CheckEmpty())
		throw "Empty stack";
	else
	{
		ValType res;
		res=pVector[Top];
		Top--;
		return res;
	}
}
template <class ValType>
ValType TStack<ValType>::Get()// извлечь элемент без удаления
{
	if(this->CheckEmpty())
		throw "Empty stack";
	else
		return pVector[Top];
}
template <class ValType>
bool TStack<ValType>::CheckFull() const //проверка на переполнение
{
	if (Top==Size-1)
		return true;
	else
		return false;
}
template <class ValType>
bool TStack<ValType>::CheckEmpty() const //проверка на пустоту
{
	if (Top==(-1))
		return true;
	else
		return false;
}
template <class ValType>
void TStack<ValType>::Clear() //очистить стек
{
	Top=-1;
}
#endif
