/*#include <iostream>
#include <string> 
#include <stack>
#include <stdlib.h>
#include <sstream>
#include <ctime>

using namespace std;

static string op[4] = { "+", "-", "*", "/" };// Operation set
static int mem = 0;

static string MakeFormula() {
	srand((int)time(0));
	string build = "\0";
	int count = rand() % 2 + 1; // generate random count
	int start = 0;
	int number1 = rand() % 100;
	build = to_string(number1);
	while (start <= count) {
		int operation = rand() % 4; // generate operator
		int number2 = rand() % 100 + 1;
		build = build + op[operation] + to_string(number2);
		start++;
	}
	return build;
}

static string Solve(string formula) {
	stack<string> tempStack;//Store number or operator
	stack<char> operatorStack;//Store operator
	const int len = formula.length();
	int k = 0,i = 0;
	string str;
	for (int j = -1; j < len - 1; j++) {
		str = "";
		char formulaChar = formula[j + 1];
		if (j == len - 2 || formulaChar == '+' || formulaChar == '-' || formulaChar == '/' || formulaChar == '*') {
			if (j == len - 2) {
				tempStack.push(formula.substr(k));
			}
			else {
				if (k < j) {
					tempStack.push(formula.substr(k, j + 1 - k));
				}
				if (operatorStack.empty()) {
					operatorStack.push(formulaChar); //if operatorStack is empty, store it
				}
				else {
					char stackChar = operatorStack.top();
					if ((stackChar == '+' || stackChar == '-')
						&& (formulaChar == '*' || formulaChar == '/')) {
						operatorStack.push(formulaChar);
					}
					else {
						str = str + operatorStack.top();
						operatorStack.pop();
						tempStack.push(str);
						operatorStack.push(formulaChar);
					}
				}
			}
			k = j + 2;
		}
	}
	while (!operatorStack.empty()) { // Append remaining operators
		str = "";
		str = str + operatorStack.top();
		operatorStack.pop();
		tempStack.push(str);
	}
	char line[6][4];
	k = tempStack.size();
	for (i = 0; i < k; i++) {
		str = tempStack.top();
		stringstream ss;
		ss << str;
		ss >> line[k - i - 1];
		//line[k - i - 1] = str;
		tempStack.pop();
	}
	stack<string> calcStack;
	for (i = 0; i < k; i++) { // Reverse traversing of stack
		if ((strcmp(line[i],"+") != 0) && (strcmp(line[i] , "-") != 0) && (strcmp(line[i], "*") != 0) && (strcmp(line[i], "/") != 0)) {
			calcStack.push(line[i]); // Push number to stack
		}
		else {
			int a1 = 0;
			int b1 = 0;
			if (!calcStack.empty()) {
				str = calcStack.top();
				calcStack.pop();
				stringstream ss;
				ss << str;
				ss >> b1;
			}
			if (!calcStack.empty()) {
				str = calcStack.top();
				calcStack.pop();
				stringstream ss;
				ss << str;
				ss >> a1;
			}
			if (strcmp(line[i] , "+") == 0) {
				calcStack.push(to_string(a1 + b1));
			}
			else if (strcmp(line[i] ,"-") == 0) {
				calcStack.push(to_string(a1 - b1));
			}
			else if (strcmp(line[i], "*") == 0) {
				calcStack.push(to_string(a1 * b1));
			}
			else {
				if (a1 % b1 != 0) {
					return "ER";
				}
				calcStack.push(to_string(a1 / b1));
			}
		}
	}
	return calcStack.top();
}

void main() {
	mem = 0;
	cin >> mem;
	string question = MakeFormula();
	cout << question << endl;
	string ret = Solve(question);
	cout << ret << endl;
}*/


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

string Calculator::MakeFormula() {
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

int main()
{
	Calculator* calc = new Calculator();
	string question = calc->MakeFormula();
	cout << question << endl;
	string ret = calc->Solve("11+22");
	cout << ret << endl;
	getchar();
}


