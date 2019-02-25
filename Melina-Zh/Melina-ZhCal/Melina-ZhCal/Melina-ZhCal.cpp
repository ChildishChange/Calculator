

#include "pch.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include <fstream>
#include "Melina-ZhCal.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	int count = random(2, 3);//range error fixed
	int start = 0;
	int number1 = random(0, 100);
	int res = number1;
	formula += to_string(number1);
	while (start < count) {
		int operation = random(0, 3);
		int number2 = random(0, 100);
		if (operation == 2) {
			res *= number2;
		}
		else if (operation == 3) {

			while (number2 == 0||res%number2 !=0 ) {//add the function
				number2 = random(0, 100);
			}
			res /= number2;
		}
		else {
			res = number2;
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
					tempStack->push_back(formula.substr(k, j+1-k));//bug fixed
				}
				if (operatorStack->empty()) {
					operatorStack->push(formulaChar);
				}
				else {
					while (!operatorStack->empty()) {
						char stackChar = operatorStack->top();
						if ((stackChar == '+' || stackChar == '-')
							&& (formulaChar == '*' || formulaChar == '/')) {
							
							operatorStack->push(formulaChar);
							break;
						}
						else {
							
							tempStack->push_back(string(1, operatorStack->top()));

							operatorStack->pop();
							if (operatorStack->empty()) {
								operatorStack->push(formulaChar);
								break;
							}
						}

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
	int n;
	cin >> n;
	ofstream OpenFile("subject.txt");//print to file
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {//can't generate n formula.
		string question = calc->MakeFormula();
		
		string ret = calc->Solve(question);
		cout << ret << endl;
		OpenFile << ret << endl;
	}
	OpenFile.close();

	getchar();
}

