#include "stdafx.h"
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

string Calculator::MakeFormula() 
{
	/*
	string formula = "";
	srand((unsigned int)time(NULL));
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
	*/
	
	string formula = "";

	int count = random(1, 2);
	int start = 0;
	int number1 = random(1, 100);
	int numberNow = number1;
	formula += to_string(number1);
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(1, 100);
		/*
		当出现除法运算时，检查是否可能出现结果为非整数的情况，
		若出现，改变被除数的值，使结果为整数
		*/
		if (operation == 3) {
			while(numberNow % number2 != 0) {
				if (number2 > numberNow && numberNow > 1) {
					number2 = numberNow;
				}
				number2--;
			}
		}
		formula += op[operation] + to_string(number2);
		/*
		更新numberNow的值
		*/
		if (operation == 0 || operation == 1) {
			numberNow = number2;
		}
		else {
			if (operation == 2) {
				numberNow *= number2;
			}
			else {
				numberNow /= number2;
			}
		}
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
				/*
				if (k < j)
				*/
				if (k <= j) 
				{
					/*
					tempStack->push_back(formula.substr(k, j + 1));
					*/
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
						/*
						tempStack->push_back(to_string(operatorStack->top()));
						*/
						string tempOp(1, operatorStack->top());
						tempStack->push_back(tempOp);

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
	string outputFile = "d:/subject.txt";
	ofstream fout;           //创建ofstream
	fout.open(outputFile);   //关联一个文件

	int questionsNum;
	cin >> questionsNum;
	Calculator* calc = new Calculator();
	int i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < questionsNum; i++) {
		string question = calc->MakeFormula();
		//cout << question << endl;
		string ret = calc->Solve(question);
		cout << ret << endl;
		fout << ret << endl;   //写入
	}
	fout.close();            //关闭
	getchar();
}