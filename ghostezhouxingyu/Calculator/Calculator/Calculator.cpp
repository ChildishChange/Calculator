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

string Calculator::MakeFormula() 
{
	string formula = "";
	//srand((unsigned int)time(NULL));	
	int count = random(1, 2);		//should be (1,2)
	int start = 0;
	int number1 = random(1, 100);
	int dividend = number1;
	formula += to_string(number1);

	while (start <= count) 
	{
		int operation = random(0, 3);
		int number2 = random(1, 100);
		if (operation != 3)
		{
			dividend = number2;
		}
		else
		{
			while (dividend % number2 != 0)
			{
				number2 = random(1, 100);
			}
			dividend /= number2;
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
				if (k <= j) {
					tempStack->push_back(formula.substr(k, j - k + 1));	//substr(index, length)
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

	//for (auto i = tempStack->begin(); i < tempStack->end(); i++)
	//	cout << *i << endl;

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

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		cout << "there should be one paranum" << endl;
		exit(0);
	}

	FILE* stream;
	int n = atoi(argv[1]);
	freopen_s(&stream, "subject.txt", "w", stdout);
	srand((unsigned int)time(NULL));
	Calculator *calc = new Calculator();
	for (int i = 0; i < n; i++)
	{
		string question = calc->MakeFormula();
		string answer = calc->Solve(question);
		cout << answer << endl;
	}
	delete calc;
	return 0;
}



