

#include "pch.h"
#include <stack>
#include <vector>
#include <iostream>
#include<fstream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	int count = random(2, 3);//operation num
	int start = 0;
	int number1 = random(1, 100);
	int divee = number1;// record dividend
	formula += to_string(number1);
	while (start < count) {// change less than to less
		int operation = random(0, 3);
		int number2 = random(1, 100);
		if (operation != 3) divee = number2;
		while (operation == 3 && divee % number2 != 0) {
			number2 = random(1, 100);//be sure not to appear float when doing division
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
	int k = 0;
	for (int j = -1; j < len - 1; j++) {
		char formulaChar = formula[j + 1];
		if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||
			formulaChar == '*' || formulaChar == '/') {
			if (j == len - 2) {
				tempStack->push_back(formula.substr(k));
			}
			else {
				if (k < j) {
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
						tempStack->push_back(to_string(operatorStack->top()));
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

int main(int argc, char *argv[])
{	
	cout << argv[1] << endl;
	int n = atoi(argv[1]);
	cout << n << endl;
	ofstream outFile("subject.txt");
	streambuf* backup = cout.rdbuf();
	cout.rdbuf(outFile.rdbuf());// 设置cout流缓冲区指针为out.txt的流缓冲区指针，将控制台输出重定向到文件输出
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		Calculator* calc = new Calculator();
		string question = calc->MakeFormula();
		//cout << question << endl;
		string ret = calc->Solve(question);
		cout << ret << endl;
	}
	//getchar();
}


