#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__

#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "stack.h"
#define MAX_SIZE 256;
using namespace std;

int DeterminationType(char s);

bool CheckBrackets(char* s) ;
bool CheckAmoutOperands(char* s);
bool CheckOperationsInRow(char *s);
bool CheckPlaceDotsOrCommas(char *s);
bool CheckCorrectnessOfSymbols(char *s);
bool CheckStr(char *s);

int Prioritet(char s);
bool IsSign(char s);
bool IsOperation(char s);
char* FindVars (char *s);
void InputValues(char *s);
char* ChangeOperand(char *s);
double* ArrayOfNumbers(char *s);
double GetNumber(char *s);

char* ConvertInPostfixNotation(char* s);
double EvaluationOfExpression(char *s,double *arr);

#endif