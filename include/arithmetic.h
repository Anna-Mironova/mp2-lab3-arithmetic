#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "stack.h"

using namespace std;

enum{type1 , type2 , type3 }
typedef types;

void PartitionIntoLexemes(char *s);
int DeterminationType(char s);
bool CheckBrackets(char* s) ;
bool CheckAmoutOperands(char* s);
bool CheckOperationsInRow(char *s);

#endif