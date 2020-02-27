#pragma once
// #include "stdafx.h"
// 在VS2019中，stdafx.h已经设置为预编译头，因此此处注释掉
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
	string MakeFormula();
	string Solve(string formula);
};
