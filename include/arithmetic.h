#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

#include <iostream>
#include "stack.h"

using namespace std;

void PartitionIntoLexemes(char *s);
bool CheckBrackets(char* s) ;
bool CheckAmoutOperands(char* s);
bool CheckOperationsInRow(char *s);

#endif