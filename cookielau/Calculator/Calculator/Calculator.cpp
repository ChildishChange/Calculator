

//#include "stdafx.h"
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
	srand((unsigned int)time(NULL));
	int count = random(2, 3);
	int start = 0;
	int number1 = random(1, 100);
	// since we need to find a/b where a%b=0
	// so we generate reversely
	bool isDiv = false;
	int lastNum;
	int number2;
	while (start < count) {
		int operation = random(0, 3);
		while (isDiv && op[operation] == "/") {
			operation = random(0, 3);
		}
		if (isDiv) {
			number2 = lastNum * random(1, 100 / lastNum);
		}
		else {
			number2 = random(1, 100);
		}
		formula = op[operation] + to_string(number2) + formula;
		start++;
		isDiv = (op[operation] == "/") ? true : false;
		if (isDiv) {
			lastNum = number2;
		}
	}
	if (isDiv) {
		number2 = lastNum * random(1, 100 / lastNum);
	}
	else {
		number2 = random(1, 100);
	}
	formula = to_string(number2) + formula;
	return formula;
};

string Calculator::Solve(string formula) {
	vector<string>* tempStack = new vector<string>();
	stack<char>* operatorStack = new stack<char>();
	int len = formula.length();
	int k = 0;
	for (int j = -1; j < len - 1; j++) {
		char formulaChar = formula[j + 1];
		if (j >= len - 2 || formulaChar == '+' || formulaChar == '-' ||
			formulaChar == '*' || formulaChar == '/') {
			if (j >= len - 2) {
				tempStack->push_back(formula.substr(k));
			}
			else {
				//if (k <= j) {
				tempStack->push_back(formula.substr(k, j + 1 - k));
				//}
				if (operatorStack->empty()) {
					operatorStack->push(formulaChar);
				}
				else {
					char stackChar = operatorStack->top();
					if ((stackChar == '+' || stackChar == '-')
						&& (formulaChar == '*' || formulaChar == '/')) {
						operatorStack->push(formulaChar);
						//tempStack->push_back(string(1, formulaChar));
					}
					else {
						int flag = (formulaChar == '*' || formulaChar == '/') ? 2 : 1; // 2 for mul/div 1 for add/sub
						while (true) {
							tempStack->push_back(string(1, stackChar));
							operatorStack->pop();
							if (operatorStack->empty()) {
								break;
							}
							else {
								stackChar = operatorStack->top();
								int temp = (stackChar == '*' || stackChar == '/') ? 2 : 1;
								if (temp != flag)
									break;
							}
						}
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
	Calculator* calc = new Calculator();
	string question = calc->MakeFormula();
	cout << question << endl;
	string ret;
	//ret = calc->Solve("46-88/88*37+88");
	ret = calc->Solve(question);
	cout << ret << endl;
	//getchar();
}


