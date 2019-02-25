

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

int nums[100];
int getDivNum(int before) {
	if (before == 0) return 1;
	int count = 0;
	for (int i = 1; i <= before; i++) {
		if (before % i == 0) {
			nums[count++] = i;
		}
	}
	return nums[random(0, count - 1)];
}

string Calculator::MakeFormula() {
	string formula = "";
	srand((unsigned int)time(NULL));
	//" 1 - 3 "  改为 " 1 - 2 " 运算符为2-3个之间
	int count = random(1, 2);
	int start = 0;
	//按照题意 2 - 3 之间为2或3 ，" 0 - 100 " 之间 按照题意应该包括0 
	int number1 = random(0, 100);
	formula += to_string(number1);
	/*
		要求不能出现小数 
	*/
	int beforeNum = number1;
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(0, 100);
		if (operation == 3) number2 = getDivNum(beforeNum);
		formula += op[operation] + to_string(number2);
		beforeNum = number2;
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
				if ( k < j + 1 ) {
					//substr 后面的数字似乎代表长度
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
						// to_string 似乎出了点问题
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

int main()
{	
	/*
	Calculator* calc = new Calculator();
	string question = calc->MakeFormula();
	cout << question << endl;
	string ret = calc->Solve("99*1-5");
	cout << ret << endl;
	getchar();
	*/
	for (int i = 0; i < 10000000; i++) {
		Calculator* calc = new Calculator();
		string question = calc->MakeFormula();
		cout << question << endl;
		string ret = calc->Solve("11+22");
		cout << ret << endl;
	}
}


