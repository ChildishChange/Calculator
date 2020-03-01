//#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include <fstream>
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	//srand((unsigned int)time(NULL));
	int count = random(1, 2);
	int start = 0;
	int number1 = random(0, 100);
	formula += to_string(number1);
	while (start <= count) {
		int operation = random(0, 3);
		//fix bug: 随机数字范围出错
		int number2 = random(0, 100);
		if (operation == DIV) {
			number2 = random(1, 100);
		}
		formula += op[operation] + to_string(number2);
		number1 = number2;
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
				if (k <= j) {
					//fix bug: substr使用出错
					tempStack->push_back(formula.substr(k, j + 1 - k));
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
					else {
						//fix bug: char变string出错
						tempStack->push_back(string(1, operatorStack->top()));
						operatorStack->pop();
						//fix bug: 保证左边底或者同优先级的都被处理了
						j -= 1;
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
				if (a1 % b1 != 0) {
					return "NOT ACCEPT";
				}
				calcStack->push(to_string(a1 / b1));
			}
		}
	}
	return formula + "=" + calcStack->top();
}

int main()
{
	int n;
	cin >> n;
	Calculator* calc = new Calculator();
	srand((unsigned int)time(NULL));
	ofstream fout;
	fout.open("subject.txt");
	while (n > 0) {
		string expression = calc->Solve(calc->MakeFormula());
		if (expression == "NOT ACCEPT") {
			continue;
		}
		cout << expression << endl;
		fout << expression << endl;
		n--;
	}
}
