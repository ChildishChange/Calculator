// Calculator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//



#include "pch.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)//获得a到b之间（包括b）的随机数

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	srand((unsigned int)time(NULL));
	int count = random(1, 3);
	int start = 0;
	int number1 = random(1, 99);
	formula += to_string(number1);
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(1, 99);
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
				//cout << "操作数 " << formula.substr(k, j + 1) << endl;
			}
			else {
				if (k <= j) { //这里把"k < j"改为"k <= j"
					tempStack->push_back(formula.substr(k, j + 1 - k)); //这里把"j + 1"改成"j + 1 - k"，每次读取一个操作数
					//cout << "操作数 " << formula.substr(k, j + 1 - k) << endl;
				}
				if (operatorStack->empty()) {
					operatorStack->push(formulaChar);
					//cout << "操作符入栈 " << formulaChar << endl;
				}
				else {
					char stackChar = operatorStack->top();
					if ((stackChar == '+' || stackChar == '-')
						&& (formulaChar == '*' || formulaChar == '/')) {
						operatorStack->push(formulaChar);
						//cout << "操作符入栈 " << formulaChar << endl;
					}
					else {
						tempStack->push_back(string(1, operatorStack->top()));//这里把"to_string(operatorStack->top())"(值为43)改成"string(1, operatorStack->top())"(值为+)
						//cout << "操作符出栈 " << string(1, operatorStack->top()) << endl;
						operatorStack->pop();
						//cout << "操作符入栈 " << formulaChar << endl;
						operatorStack->push(formulaChar);
					}
				}
			}
			k = j + 2;
		}
	}
	while (!operatorStack->empty()) {
		tempStack->push_back(string(1, operatorStack->top()));
		//cout << "操作符出栈 " << string(1, operatorStack->top()) << endl;
		if (to_string(operatorStack->top()) == string(1, operatorStack->top())) {
			cout << "yes!" << endl;
		}
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
	for (int i = 0; i < 10000000; i++) {
		Calculator* calc = new Calculator();
		string question = calc->MakeFormula();
		cout << question << endl;
		string ret = calc->Solve("1+51/17");
		cout << ret << endl;
		//getchar();
	}
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
