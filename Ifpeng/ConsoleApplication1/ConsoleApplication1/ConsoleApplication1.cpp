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
	//srand((unsigned int)time(NULL)); //bug:程序运行过快，随机种子是一样的，导致运行式都是一样的
	int count = random(1, 3);
	int start = 0;
	int number1 = random(1, 100);
	int preNumber = 0;
	formula += to_string(number1);
	preNumber = number1;
	while (start <= count && start <= 2) { //（debug：运算符产生了2-4个，而非2-3个）
		int operation = random(0, 3);
		int number2 = random(1, 100); //（debug:生成了产生非整数结果的除法）
		//fixed up
		if (operation == 3) {
			do {
				number2 = random(1, 19);
			} while (preNumber%number2 != 0);
		}

		formula += op[operation] + to_string(number2);
		preNumber = number2;
		start++;
	}
	return formula;

	/*
	生成形如
	1+4+5
	或
	1+2+3+4+5
	的表达式

	bug: 运算符数量在2-4之间，而非题目要求的2-3之间
	*/
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
				if (k <= j) { //(debug:当数字在0-9之间时不会计入)
					tempStack->push_back(formula.substr(k, j - k + 1)); //(debug:substr的使用不正确）
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
						tempStack->push_back(string(1, operatorStack->top())); //（debug:符号会被转换成数字）
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
	Calculator* calc = new Calculator();
	srand((unsigned int)time(NULL)); //(debug:把随机生成种子设置放在循环外，仅设置一次）
	ofstream outFile;
	outFile.open("subject.txt");

	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		string question = calc->MakeFormula();
		cout << question << endl;
		string ret = calc->Solve(question);
		cout << ret << endl;
		outFile << ret << endl;
	}
	outFile.close();
	getchar();
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
