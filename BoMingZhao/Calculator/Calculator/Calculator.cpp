// Calculator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
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

Calculator::Calculator() {}
FILE* out;

string Calculator::MakeFormula() {
	string formula = "";
	//srand((unsigned int)time(NULL));
	int count = random(2, 3);//2-3个操作数
	int start = 1;
	int number1 = random(0, 100);
	formula += to_string(number1);
	int number2;
	while (start <= count) {
		int yueshu[100];
		int quotient;//商
		int product;//积
		int operation = random(0, 3);
		if (operation == 3) {//如果op是除法，需要让除数是被除数的约数
			int k = 0;
			int number;
			if (start == 1) {//第一个操作符
				number = number1;
			}
			else {//第二个到第三个操作符，操作数变为number2
				number = number2;
			}
			for (int i = 1; i <= number && i<=100; i++) {
				if (number % i == 0) {
					yueshu[k] = i;
					k++;
				}
			}
			int num;
			if (k == 1) {
				num = 0;
			}
			else if (k!=0){
				num = random(0,k-1);
			}
			if (number == 0) {//除数是0的情况
				number2 = random(0, 100);
			}
			else {
				number2 = yueshu[num];
			}
			quotient = number / number2;
		}
		else {
			if (operation == 2) {
				product = (start == 1)?number1:number2;
			}
			number2 = random(0, 100);
			if (operation == 2) {
				product *= number2;
			}
		}
		formula += op[operation] + to_string(number2);
		start++;
		if (operation == 3) {//为了防止连续除法时
			number2 = quotient;
		}
		else if (operation == 2) {
			number2 = product;
		}
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
							string Op = (&operatorStack->top());
							Op = Op.at(0);
							tempStack -> push_back(Op);
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
	/*int a = 0;
	while (a < tempStack->size()) {
		cout<< tempStack->at(a) <<endl;
		a++;
	}*/
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
	FILE* stream1;
	freopen_s(&stream1, "subject.txt", "w", stdout);
	int n;
	srand((unsigned int)time(NULL));
	cin >> n;
	for (int i = 1; i <= n;i++) {
		Calculator* calc = new Calculator();
		string question = calc->MakeFormula();
		cout << question << endl;
		//string ret = calc->Solve("60-41/1+14");
		string ret = calc->Solve(question);//这里应该是question
		cout << ret << endl;
	}
	fclose(stdout);
}


