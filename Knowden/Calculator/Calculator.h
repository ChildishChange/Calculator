#pragma once
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>  
using namespace std;

class Calculator {
private:
	string op[4] = { "+", "-", "*", "/" };

	vector<int>* getAllFactors(int number);
public:
	Calculator();
	string MakeFormula();
	string Solve(string formula);
};
