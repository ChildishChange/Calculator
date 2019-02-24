

#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;


__declspec (naked) unsigned __int64 GetCpuCycle(void)//获取cpu周期时间 精确到微秒 具体原理不清楚
{
	_asm
	{
		rdtsc
		ret
	}
}

Calculator::Calculator() {}
string Calculator::MakeFormula() {
	string formula = "";
	
	unsigned __int64 iCpuCycle = GetCpuCycle();
	unsigned srnd = (unsigned)iCpuCycle;
	srand(srnd);

	int count = random(2, 3);//1-3改为2-3
	int start = 0;
	
	int last_op = 0;

	//formula += to_string(number1);
	while (start < count) {
		

		int number1;
		int number2;
		float ans;
		int operation;
		
		if (last_op == 3) {
			operation = random(0, 2);
		}
		else {
			operation = random(0, 3);
		}
		

		if (operation == 3) {
			ans = 0.1;
			while (ans  != (int)ans) {
				number1 = random(0, 100);
				number2 = random(1, 100);
				ans = (float)number1 / (float)number2;
			}
			formula += to_string(number1) + op[3] + to_string(number2);
		}
		else {
			if (last_op != 3) {
				number1 = random(0, 100);
				formula += to_string(number1)+ op[operation];
			}
			else {
				formula += op[operation];
			}
		}
		last_op = operation;
		start++;
	}
	if (last_op != 3) {
		formula += to_string(random(0, 100));
	}
	return formula;
};

string Calculator::Solve(string formula) {
	vector<string>* tempStack = new vector<string>();
	stack<char>* operatorStack = new stack<char>();
	int len = formula.length();		//字符串长度
	int k = 0;
	int numlen = 0;

	for (int j = -1; j < len - 1; j++) {
		char formulaChar = formula[j + 1];
		if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||//如果读到符号或读完
			formulaChar == '*' || formulaChar == '/') {
			if (j == len - 2) {                    //读到字符尾
			//	if (!operatorStack->empty() ){
			//		tempStack->push_back(string(1, operatorStack->top()));
			//		operatorStack->pop();
			//	}
				tempStack->push_back(formula.substr(k));
			}
			else {
				if (k <= j) {//原来是<
					tempStack->push_back(formula.substr(k, numlen));
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
						//tempStack->push_back(to_string(operatorStack->top()));
						tempStack->push_back(string(1, operatorStack->top()));
						operatorStack->pop();
						operatorStack->push(formulaChar);
					}
				}
			}
			k = j + 2;
			numlen = 0;
		}
		else {
			numlen++;
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
	int qn;

	cin >> qn;
	while (qn-- != 0) {
		Calculator* calc = new Calculator();
		string question = calc->MakeFormula();
		cout << question << endl;
		string ret = calc->Solve(question);
		cout << ret << endl;
		delete calc;
	}
	
	system("pause");
}


