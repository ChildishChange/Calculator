#include "stdafx.h"
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
	//int count = random(1, 3);
	int count = random(1, 2);
	int start = 0;
	int number1 = random(1, 100);
	formula += to_string(number1);
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(1, 100);
		if (operation == 3 && number1 % number2 != 0) {//若运算为除法且无法整除
			int i;
			for (i = 2; i < 10; i++) {
				if (number1 % i == 0) {
					number2 = i;
					break;
				}
			}
			if (i == 10) {
				number2 = 1;
			}
		}
		formula += op[operation] + to_string(number2);
		start++;
		//记录前面的运算数
		if(operation == 3){
			number1 = number1 / number2;
		}
		else if (operation == 2) {
			number1 = number1 * number2;
		}
		else {
			number1 = number2;
		}
	}
	return formula;
};

string Calculator::Solve(string formula) {
	//tempStack中存放 转换后的 后缀表达式
	vector<string>* tempStack = new vector<string>();
	stack<char>* operatorStack = new stack<char>();
	int len = formula.length();
	int k = 0;
	for (int j = -1; j < len - 1; j++) {
		char formulaChar = formula[j + 1];
		//formulaChar 为最后一个字符 或者为运算符
		if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||
			formulaChar == '*' || formulaChar == '/') {
			if (j == len - 2) {
				tempStack->push_back(formula.substr(k));
			}
			else {//formulaChar为运算符
				//if(k< j) 错！
				if (k <= j) {//将 substr(k,j+1)表示的操作数加入 tempStack
					//tempStack->push_back(formula.substr(k, j + 1));
					//substr(pos,n)从pos开始长度为n的字符串
					tempStack->push_back(formula.substr(k, j + 1-k));
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
					else {//当操作符小于等于栈顶操作符的优先级时，栈顶操作符写入后缀表达式，！！！重复此过程
						while (!((stackChar == '+' || stackChar == '-')
							&& (formulaChar == '*' || formulaChar == '/'))) {
							//tempStack->push_back(to_string(operatorStack->top()));
							// to_string  将数字转乘字符串  会把运算符装成ASSIC的字符串
							tempStack->push_back(string(1, stackChar));
							operatorStack->pop();
							if (operatorStack->empty()) {
								break;
							}
							stackChar = operatorStack->top();							
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

	//开始计算后缀表达式
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
int main()
{
	
	for (int i = 0; i < 10000000; i++) {
		Calculator* calc = new Calculator();
		string question = calc->MakeFormula();
		cout << question << endl;
		string ret = calc->Solve("11+22");
		cout << ret << endl;
	}
	
}
*/

int main(int argc, char* argv[]) {
	int n;
	//cout << argc << endl;
	n = atoi(argv[1]);//接收命令行参数n
	//cout << n << endl;
	Calculator* calc = new Calculator();
    ofstream outfile;
	outfile.open(".\\subject.txt", ios::app);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		string question = calc->MakeFormula();
		string ret = calc->Solve(question);
		//cout << ret << endl;
		//将ret中的"/"替换为 "÷"
		outfile << ret << endl;
	}

	outfile.close();
	return 0;

}


