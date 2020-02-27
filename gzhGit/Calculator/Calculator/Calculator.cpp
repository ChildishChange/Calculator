//#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;
int floatThreat = 0;
Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	//srand((unsigned int)time(NULL));
	int count = random(2, 3);
	int start = 1;
	int number1 = random(0, 100);
	formula += to_string(number1);
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(0, 100);
		if (operation == 3) {
			while (number2 == 0) {
				number2 = random(0, 100);
			}
		}
		formula += op[operation] + to_string(number2);
		start++;
		number1 = number2;
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
					//tempStack->push_back(formula.substr(k, j + 1));
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
						//tempStack->push_back(to_string(operatorStack->top()));
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

/*	cout << "begin" << endl;
	int o = 0;
	for (; o < tempStack->size(); o++) {
		cout << tempStack->at(o) << endl;
	}
	cout << "end" << endl; */

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
				if (a1 != a1 / b1 * b1) {
					floatThreat = 1;
				}
				calcStack->push(to_string(a1 / b1));
			}
		}
	}
	return formula + "=" + calcStack->top();
}

/*int main()
{
	Calculator* calc = new Calculator();
	string question = calc->MakeFormula();
	cout << question << endl;
	string ret = calc->Solve("11+22");
	cout << ret << endl;
	getchar();
}*/

int main()
{
	srand((unsigned int)time(NULL));
	int num;
	cin >> num;
	Calculator* calc = new Calculator();
	/*string question = calc->MakeFormula();
	cout << question << endl;
	string ret = calc->Solve("11+22");
	cout << ret << endl;*/
	int i = 0;
	for (; i < num; i++) {
		string q = calc->MakeFormula();
		string r = calc->Solve(q);
		if (floatThreat == 1) {
			num++;
			floatThreat = 0;
		}
		else cout << r << endl;
	} 
	//string q = "12*2+23-80";//"38/1*37" "7*0-2-48"
	//cout << calc->Solve(q) << endl;
	getchar();
}