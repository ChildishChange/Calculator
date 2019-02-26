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

vector<string> Calculator::MakeFormula() {
	vector<string> formula;
	int count = random(2, 3);
	int start = 0;
	int number1 = random(0, 100);
	formula.push_back(to_string(number1));
	while (start < count) {
		int operation = random(0, 3);
		int number2 = random(0, 100);
		formula.push_back(op[operation]);
		formula.push_back(to_string(number2));
		start++;
	}
	return formula;
};

string Calculator::Solve(vector<string>& formula)
{
	vector<string>* tempStack = new vector<string>();
	stack<string>* operatorStack = new stack<string>();
	int len = formula.size();
	int k = 0;
	string question = "";
	for (string formulaChar : formula) {
		question += formulaChar;
		if (formulaChar == "+" || formulaChar == "-" ||
			formulaChar == "*" || formulaChar == "/") {
			if (operatorStack->empty()) {
				operatorStack->push(formulaChar);
			}
			else {
				string stackChar = operatorStack->top();
				if ((stackChar == "+" || stackChar == "-")
					&& (formulaChar == "*" || formulaChar == "/")) {
					operatorStack->push(formulaChar);
				}
				else {
					tempStack->push_back(operatorStack->top());
					operatorStack->pop();
					operatorStack->push(formulaChar);
				}
			}
		} else {
			tempStack->push_back(formulaChar);
		}
	}
	while (!operatorStack->empty())
	{
		tempStack->push_back(operatorStack->top());
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
				if (b1 == 0 || a1 % b1 != 0) return "error";
				calcStack->push(to_string(a1 / b1));
			}
		}
	}
	return question + "=" + calcStack->top();
}

int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	if (n < 0) { 
		printf("error"); 
		return 0; 
	}

	srand((unsigned int)time(NULL));
	vector<string> question;
	string ret;
	ofstream outfile;
	outfile.open("subject.txt");
	for (int i = 1; i <= n; i++) {
		Calculator* calc = new Calculator();
		do {
			question = calc->MakeFormula();
			ret = calc->Solve(question);
		} while (ret == string("error"));
		outfile << ret << endl;
	}
	outfile.close();
	return 0;
}