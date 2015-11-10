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
		int Size;       // ������ �����
		int Top;        // ������ ���������� ��������

		TStack(int s);	                          //����������� �������������
		TStack(const TStack &v);                 //����������� �����������
		~TStack();                               //����������

		void Include(const ValType i);          //�������� �������
		ValType Exclude();                      // ������� ������� � ���������
		ValType Get();                          // ������� ������� ��� ��������
		bool CheckFull() const;                 //�������� �� ������������
		bool CheckEmpty() const;                //�������� �� �������
		void Clear();                           //�������� ����
				
		// �����
  friend ostream& operator<<(ostream &out, const TStack &v)
  {
    for (int i = 0; i < v.Top+1; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TStack<ValType>::TStack(int s)//����������� �������������
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

template <class ValType> //����������� �����������
TStack<ValType>::TStack(const TStack<ValType> &v)
{
	Size=v.Size;
	Top=v.Top;
	pVector=new ValType[Size];
	for (int i=0; i<Top; i++)
		pVector[i]=v.pVector[i];
} 

template <class ValType> //����������
TStack<ValType>::~TStack()
{
	if(pVector!=NULL)
		delete []pVector;	
}

template <class ValType>
void TStack<ValType>:: Include(const ValType i)//�������� �������
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
ValType TStack<ValType>::Exclude() // ������� ������� � ���������
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
ValType TStack<ValType>::Get()// ������� ������� ��� ��������
{
	if(this->CheckEmpty())
		throw "Empty stack";
	else
		return pVector[Top];
}
template <class ValType>
bool TStack<ValType>::CheckFull() const //�������� �� ������������
{
	if (Top==Size-1)
		return true;
	else
		return false;
}
template <class ValType>
bool TStack<ValType>::CheckEmpty() const //�������� �� �������
{
	if (Top==(-1))
		return true;
	else
		return false;
}
template <class ValType>
void TStack<ValType>::Clear() //�������� ����
{
	Top=-1;
}
#endif
