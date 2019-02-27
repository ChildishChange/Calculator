#include "pch.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	int count = random(1, 3);
	int start = 0;
	int number1 = random(1, 100);
	formula += to_string(number1);
	int lastnum = number1;
	while (start < count) {
		int operation = random(0, 3);
		int number2;
		if (operation == 3) {
			number2 = random(1, 100);
			while(lastnum % number2 != 0)
				number2 = random(1, 100);
		}
		else
			number2 = random(1, 100);
		formula += op[operation] + to_string(number2);
		start++;
		lastnum = number2;
	}
	return formula;
};

string Calculator::Solve(string formula) {
	vector<string>* tempStack = new vector<string>();	//tempStack中存的是后缀表达式
	stack<char>* operatorStack = new stack<char>();		//opStack是运算符栈
	int len = formula.length();
	int k = 0;
	for (int j = 0; j < len; j++) {
		char formulaChar = formula[j];
		if (j == len - 1 || formulaChar == '+' || formulaChar == '-' || formulaChar == '*' || formulaChar == '/') {
			if (j == len - 1) {
				tempStack->push_back(formula.substr(k));
			}
			else {
				if (k < j) {
					tempStack->push_back(formula.substr(k, j - k));
				}
				if (operatorStack->empty()) {
					operatorStack->push(formulaChar);
				}
				else {
					char stackChar = operatorStack->top();
					if ((stackChar == '+' || stackChar == '-') && (formulaChar == '*' || formulaChar == '/')) {
						operatorStack->push(formulaChar);
					}
					else {
						tempStack->push_back(string(1,operatorStack->top()));
						operatorStack->pop();
						operatorStack->push(formulaChar);
					}
				}
			}
			k = j + 1;
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
	cin >> n;
	srand((unsigned)time(0));
	for (i = 0; i < n; i++) {
		Calculator* calc = new Calculator();
		string question = calc->MakeFormula();
		//cout << question << endl;
		string ret = calc->Solve(question);
		cout << ret << endl;
	}
	getchar();
}


