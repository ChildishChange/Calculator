

// #include "stdafx.h"
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
	srand((unsigned int)time(NULL));
	string formula = "";
	// 修改了随机数生成的范围
	// srand((unsigned int)time(NULL));
	// int count = random(1, 3);
	int count = random(2, 3);
	int start = 0;
	// int number1 = random(1, 100);
	int number1 = random(0, 100);
	formula += to_string(number1);

	int pre_number = number1;

	// while (start <= count) {
	while (start < count) {
		int operation = random(0, 3);
		// int number2 = random(1, 100);
		int number2 = random(0, 100);
		// 这里为了保证出现除法时前面得到的结果一定可以被number2整除
		// 如果前一个数前是加减法，那么对于后面的表达式，作为被除数的就是前一个数
		// 如果前一个数前是乘除法，那么对于后面的表达式，被除数是前面乘除的结果
		if (operation == 2) {
			pre_number = number1 * number2;
		}
		else if (operation == 3) {
			while (number2 == 0 || pre_number / number2 * number2 != pre_number) {
				number2 = random(0, 100);
			}
			pre_number = pre_number / number2;
		}
		else {
			pre_number = number2;
		}
		formula += op[operation] + to_string(number2);
		start++;
	}
	return formula;
};

string Calculator::Solve(string formula) {
	vector<string>* tempStack = new vector<string>();
	stack<char>* operatorStack = new stack<char>();
	int len = formula.length();
	// k是数字的起始
	int k = 0;
	for (int j = -1; j < len - 1; j++) {
		char formulaChar = formula[j + 1];
		if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||
			formulaChar == '*' || formulaChar == '/') {
			if (j == len - 2) {
				tempStack->push_back(formula.substr(k));
			}
			else {
				// 改动条件
				if (k < j + 1) {
					// j+1位置是一个运算符
					tempStack->push_back(formula.substr(k, j + 1));
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
						// 前优先级高于后，前运算符出栈
						// tempStack->push_back(to_string(operatorStack->top()));
						tempStack->push_back(string(1, operatorStack->top()));
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

int main() {
	Calculator* calc = new Calculator();
	string question = calc->MakeFormula();
	cout << question << endl;
	string ret = calc->Solve(question);
	cout << ret << endl;
	getchar();
}


