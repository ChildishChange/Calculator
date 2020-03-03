#pragma once
//#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>  
#include <fstream>
using namespace std;

class Calculator {
private:
	string op[4] = { "+", "-", "*", "/" };
	static bool isPrime(int m);
public:
	Calculator();
	string MakeFormula();
	string Solve(string formula);
};

class QuestionBuilder {
private:
	const string FILENAME = "subject.txt";
	ofstream writer;
	int total;
	Calculator *calc;
public:
	QuestionBuilder(Calculator *calc);
	void Make(int n);
};
