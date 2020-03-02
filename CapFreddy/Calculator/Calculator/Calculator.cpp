// #include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include <string.h>
#include <fstream>
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)
#define is_op(x) (x == '+' || x == '-' || x == '*' || x == '/')

using namespace std;

Calculator::Calculator() {}

int is_valid(string formula) {
	char op;
	int i, digit_begin, current, previous;
	for (i = 0, digit_begin = 0; !is_op(formula[i]); i++);
	op = formula[i];
	current = stoi(formula.substr(digit_begin, i - digit_begin));
	previous = current;
	digit_begin = i + 1;

	for (i++; i < formula.length(); i++) {
		if (is_op(formula[i])) {
			current = stoi(formula.substr(digit_begin, i - digit_begin));
			if (op == '*') {
				previous *= current;
			}
			else if (op == '/') {
				if (current == 0 || previous % current) {
					return 0;
				}
				previous /= current;
			}
			else {
				previous = current;
			}
			op = formula[i];
			digit_begin = i + 1;
		}
		else if (i == formula.length() - 1) {
			current = stoi(formula.substr(digit_begin, i - digit_begin + 1));
			if (op == '/') {
				if (current == 0 || previous % current) {
					return 0;
				}
			}
		}
	}
	return 1;
}

string Calculator::MakeFormula() {
	string formula;
	do {
		formula = "";
		int count = random(1, 2);
		int start = 0;
		int number1 = random(1, 100);
		formula += to_string(number1);
		while (start <= count) {
			int operation = random(0, 3);
			int number2 = random(1, 100);
			formula += op[operation] + to_string(number2);
			start++;
		}
	} while (!is_valid(formula));
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
					else {
						string op;
						op.push_back(operatorStack->top());
						tempStack->push_back(op);
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

/*
int main(int argc, char **argv)
{
	srand((unsigned int)time(NULL));
	int n = atoi(argv[1]);

	ofstream ofs;
	ofs.open("subject.txt", ios::out);

	Calculator* calc = new Calculator();
	while (n--) {
		string question = calc->MakeFormula();
		ofs << calc->Solve(question);
		if (n != 0) {
			ofs << endl;
		}
	}
	ofs.close();
	return 0;
}
*/

int main() {
	for (int i = 0; i < 1000000; i++) {
		Calculator* calc = new Calculator();
		string question = calc->MakeFormula();
		cout << question << endl;
		string ret = calc->Solve("11+22");
		cout << ret << endl;
	}
}