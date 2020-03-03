

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
	return formula;
};

string Calculator::aaaa() {
	string formula = "";
	srand((unsigned int)time(NULL));
	int count = random(1, 2);
	int start = 0;
	double redo = 1.1;

	int op1[4] = {};
	int num[5] = {};

	while (redo != int(redo))
	{
		op1[0] = random(0, 3);
		op1[1] = random(0, 3);
		for (int i = 0; i < 3; i++)
		{
			num[i] = random(1, 100);
		}

		if (count == 1) //生成两个运算符
		{
			if (op1[0] == 3) {
				redo = float(num[0]) / num[1];
				if (op1[1] == 3) 
				{
					redo = redo / num[2];
				}
			}
			else {
				if (op1[1] == 3) {
					redo = float(num[1]) / num[2];
				}
				else {
					redo = 1;
				}
			}
		}
		else { //三个运算符
			op1[2] = random(0, 3);
			num[3] = random(1, 100);
			if (op1[0] == 3) {
				redo = float(num[0]) / num[1];
				if (op1[1] == 3)
				{
					redo = redo / num[2];
					if (op1[2] == 3) {
						redo = redo / num[3];
					}
				}
				else {
					if (op1[2] == 3) {
						double redo2 = float(num[2]) / num[3];
						if (redo2 != int(redo2))
						{
							redo = redo2;
						}
					}
				}
			}
			else {
				if (op1[1] == 3) {
					redo = float(num[1]) / num[2];
					if (op1[2] == 3) {
						redo = redo / num[3];
					}
				}
				else {
					if (op1[2] == 3) {
						redo = float(num[2]) / num[3];
					}
					else {
						redo = 1;
					}
				}
			}
		}
	}
	formula += to_string(num[0]);
	while (start <= count) {
		formula += op[op1[start]] + to_string(num[start + 1]);
		start++;
	}
	return formula;
}

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
						while (!operatorStack->empty()) {

							string temp = (&operatorStack->top());
							temp = temp.at(0);

							tempStack->push_back(temp);
							operatorStack->pop();
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
	//string question = calc->MakeFormula();
	//for (int i = 0; i < 100; i++) {
		string question = calc->aaaa();
		cout << question << endl;
	//}
	string ret = calc->Solve("15/3+10/5");
	cout << ret << endl;
	getchar();
}


