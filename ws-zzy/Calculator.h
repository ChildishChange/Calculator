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
public:
	Calculator();
	vector<string> MakeFormula();
	string Solve(vector<string>& formula);
};
