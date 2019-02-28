
//666
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
	//srand((unsigned int)time(NULL));  放这没起作用
	int count = random(1, 2);   //操作符多了
	int start = 0;
	int number1 = random(0, 100);
	int pre;
	pre = number1;
	formula += to_string(number1);
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(1, 100);
		//避免非整数除法
		if (operation == 3) {  
			while (pre%number2 != 0) {
				int tmp;
				tmp = random(1, pre);
				number2 = tmp;
			}
		}
		formula += op[operation] + to_string(number2);
		start++;
		pre = number2;
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
				if (k <= j) {					//有问题
					tempStack->push_back(formula.substr(k, j -k+ 1));
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
						tempStack->push_back(string(1,operatorStack->top()));  //有问题
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
	//加了个循环
	ofstream Out("subject.txt");
	cout << "请输入题目数量" << endl;
	int totaln = 0;
	cin >> totaln;
	srand((unsigned int)time(NULL));
	Calculator* calc = new Calculator();
	for (int i = 0; i < totaln; i++) {
		string question = calc->MakeFormula();
		string ret = calc->Solve(question);
		Out << ret << endl;
		cout << ret << endl;
	}
	getchar();
}


