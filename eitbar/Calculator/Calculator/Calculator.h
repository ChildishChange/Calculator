#pragma once
//#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>  
using namespace std;
#define PLUS 0
#define SUB  1
#define MUL  2
#define DIV  3

class Calculator {
private:
	string op[4] = { "+", "-", "*", "/" };
public:
	Calculator();
	string MakeFormula();
	string Solve(string formula);
};
