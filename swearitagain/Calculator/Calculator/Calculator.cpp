

#include "pch.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"
#include <fstream>

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	//srand((unsigned int)time(NULL));
	int count = random(1, 3);
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

string Calculator::Solve(string formula) {
	vector<string>* tempStack = new vector<string>();//操作数栈
	stack<char>* operatorStack = new stack<char>();//操作符栈
	int len = formula.length();
	int k = 0;
	for (int j = -1; j < len - 1; j++) {
		char formulaChar = formula[j + 1];
		if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||
			formulaChar == '*' || formulaChar == '/') {
			if (j == len - 2) {
				tempStack->push_back(formula.substr(k));
			}//表达式结束，把最后一个操作数入栈
			else {
				if (k <= j) {
					tempStack->push_back(formula.substr(k, j + 1 - k));
				}//该操作符前的操作数入栈
				if (operatorStack->empty()) {
					operatorStack->push(formulaChar);
				}//操作符栈为空则入栈
				else {
					char stackChar = operatorStack->top();
					if ((stackChar == '+' || stackChar == '-')
						&& (formulaChar == '*' || formulaChar == '/')) {
						operatorStack->push(formulaChar);
					}//如果当前是乘除而栈顶是加减，则入栈
					else {
						string str;
						str += (operatorStack->top());
						tempStack->push_back(str);
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
				if (a1 % b1) return "Illegal!";
				calcStack->push(to_string(a1 / b1));
				
			}
		}
	}
	return formula + "=" + calcStack->top();
}

int main()
{
	//Calculator* calc = new Calculator();
	//string question = calc->MakeFormula();
	//cout << question << endl;
	//string ret = calc->Solve("11+22");
	//cout << ret << endl;
	//getchar();
	srand((unsigned int)time(NULL));
	Calculator* calc = new Calculator();
	//string ret = calc->Solve("5*54+83");
	int n;
	cin >> n;
	ofstream fout;
	fout.open("subject.txt");
	for (int i = 0; i < n; i++) {
		string question = calc->MakeFormula();
		//cout << question << endl;
		string ret = calc->Solve(question);
		if (ret == "Illegal!") i--;
		else fout << ret << endl;
		//getchar();
	}
}


