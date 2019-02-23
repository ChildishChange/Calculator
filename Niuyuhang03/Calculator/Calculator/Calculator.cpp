

#include "pch.h"
#include <stack>
#include <vector>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	int count = random(1, 2); // bug1, operators' number should be 2 or 3
	int start = 0;
	int number1 = random(0, 100); // bug2, number should be [0,100]
	int mult_div_res = number1; // bug3, be sure that the result is integer
	formula += to_string(number1);
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(0, 100);
		if (operation == 2)
			mult_div_res *= number2;
		else if (operation == 3) {
			while (number2 == 0 || mult_div_res % number2 != 0)
				number2 = random(0, 100);
		}
		else
			mult_div_res = number2;
		formula += op[operation] + to_string(number2);
		start++;
	}
	
	return formula;
};

string Calculator::Solve(string formula) {
	vector<string>* tempStack = new vector<string>();
	stack<char>* operatorStack = new stack<char>();
	int len = formula.length();
	int k = 0;
	for (int j = -1; j < len - 1; j++) {
		char formulaChar = formula[j + 1];
		if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||
			formulaChar == '*' || formulaChar == '/') {
			if (j == len - 2) {
				tempStack->push_back(formula.substr(k));
			}
			else {
				if (k <= j) { // bug4, length of number is wrong
					tempStack->push_back(formula.substr(k, j - k + 1));
				}
				if (operatorStack->empty()) {
					operatorStack->push(formulaChar);
				}
				else {
					char stackChar = operatorStack->top();
					if ((stackChar == '+' || stackChar == '-')
						&& (formulaChar == '*' || formulaChar == '/')) {
						operatorStack->push(formulaChar);
					}
					else { // bug5, operator should be original char in tempStack
						tempStack->push_back(string(1,operatorStack->top()));
						operatorStack->pop();
						operatorStack->push(formulaChar);
					}
				}
			}
			k = j + 2;
		}
	}
	while (!operatorStack->empty()) {
		tempStack->push_back(string(1, operatorStack->top()));
		operatorStack->pop();
	}
	stack<string>* calcStack = new stack<string>();
	for (int i = 0; i < tempStack->size(); i++) {
		string peekChar = tempStack->at(i);
		if (peekChar != "+" && peekChar != "-"
			&& peekChar != "/" && peekChar != "*") {
			calcStack->push(peekChar);
		}
		else {
			int a1 = 0;
			int b1 = 0;
			if (!calcStack->empty()) {
				b1 = stoi(calcStack->top());
				calcStack->pop();
			}
			if (!calcStack->empty()) {
				a1 = stoi(calcStack->top());
				calcStack->pop();
			}
			if (peekChar == "+") {
				calcStack->push(to_string(a1 + b1));
			}
			else if (peekChar == "-") {
				calcStack->push(to_string(a1 - b1));
			}
			else if (peekChar == "*") {
				calcStack->push(to_string(a1 * b1));
			}
			else if (peekChar == "/") {
				calcStack->push(to_string(a1 / b1));
			}
		}
	}
	return formula + "=" + calcStack->top();
}

int main()
{
	int n, i;
	Calculator* calc = new Calculator();
	cin >> n; // bug6, generate fomular n times and reset random
	ofstream outfile("subject.txt"); // bug7, write in file
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {
		string question = calc->MakeFormula();
		string ret = calc->Solve(question);
		outfile << ret << endl;
	}
	outfile.close();
	getchar();
}


