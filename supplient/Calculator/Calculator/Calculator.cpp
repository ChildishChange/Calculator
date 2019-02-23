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
	const int min_num = 0, max_num = 100;

	string formula;
	int start = 0;
	int count = random(2, 3);

	string item;
	unsigned int iter;

	int number1 = random(min_num, max_num);
	formula = to_string(number1);
	item = formula;
	while (start < count) {
		iter = 0;
		int operation, number2;
		while(true){
			iter++;
			if(iter>MAX_ITER)
				throw string("MakeFormula failed.");

			operation = random(0, 3);
			number2 = random(min_num, max_num);

			if(operation == 3){ 
				if(number2 == 0)
					continue;
				// is divide, check whether can completely divide
				int left = stoi(Solve(item));
				if(left % number2 == 0)
					break;
			}
			else{
				// not divide, just use the number2
				break;
			}
		}
		formula += op[operation] + to_string(number2);
		start++;

		switch(operation){
			case 0:
			case 1:
				// +, -
				item = to_string(number2);
				break;
			case 2:
			case 3:
				// *, /
				item += op[operation] + to_string(number2);
				break;
			default:
				throw string("Unknown operation code: " + to_string(operation));
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
				if (k < j+1) {
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
	return calcStack->top();
}

int main()
{
	srand((unsigned int)time(NULL));

	unsigned int n;
	cin >> n;
	ofstream out("subject.txt");

	Calculator* calc = new Calculator();
	for (int i = 0; i < n; i++) {
		string question = calc->MakeFormula();
		string ans = calc->Solve(question);
		string subject = question + "=" + ans;
		cout << subject << endl;
		out << subject << endl;
	}

	getchar();
	return 0;
}


