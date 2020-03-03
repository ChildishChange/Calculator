//#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"
#include <sstream>

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

bool Calculator::isPrime(int num) {
	
	if (num < 3)
		return num >= 1;
		
	if (num % 6 != 1 && num % 6 != 5)
		return false;
	int sq = (int)sqrt(num);
	for (int i = 5; i <= sq; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return false;
	}
	return true;
	
}

string Calculator::MakeFormula() {
	string formula = "";
	
	int count = random(1, 3);
	int start = 0;
	int number1 = random(0, 100);
	int tmp = number1;
	formula += to_string(number1);
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(0, 100);
		if (op[operation] == "+" || op[operation] == "-") {
			tmp = number2;
		}
		else if (op[operation] == "*") {
			tmp *= number2;
		}
		if (op[operation] == "/") {
			if (tmp != 0 && isPrime(tmp)) {
				if (number2 % 2 == 0 || tmp > 100) {
					number2 = 1;
				}
				else {
					number2 = tmp;
				}
			}
			else {
				int max = 100;
				int min = 1;
				do {
					number2 = random(min, max);
					if (tmp % number2 == 0) {
						break;
					}
					else {
						if (100 < sqrt(tmp)) {
							if (max - number2 > number2 - min) {
								min = number2 + 1;
							}
							else {
								max = number2 - 1;
							}
						}
						else {
							if (number2 > sqrt(tmp)) {
								max = number2 - 1;
							}
							else {
								min = number2+ 1;
							}
						}
					}
				} while (min < max);
				if (min >= max) {
					if (number2 % 2 == 0 || tmp > 100) {
						number2 = 1;
					}
					else {
						number2 = tmp;
					}
				}
			}
			tmp /= number2;
			
		}
		//cout << number2 << endl;
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
					tempStack->push_back(formula.substr(k, j + 1 - k));
				}
				if (operatorStack->empty()) {
					operatorStack->push(formulaChar);
				}
				else {
					while (not operatorStack->empty()) {
						char stackChar = operatorStack->top();
						if ((stackChar == '+' || stackChar == '-')
							&& (formulaChar == '*' || formulaChar == '/')) {
							break;
						}
						else {
							tempStack->push_back(string(1, operatorStack->top()));
							operatorStack->pop();
							
						}
					}
					operatorStack->push(formulaChar);
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

QuestionBuilder::QuestionBuilder(Calculator *calc) {
	this->calc = calc;
	writer = ofstream(FILENAME);
	if (writer.fail()) {
		cerr << "Open file fail!" << endl;
		exit(-1);
	}
}

void QuestionBuilder::Make(int n) {
	srand((unsigned int)time(NULL));
	this->total = n;
	string question;
	string ret;
	for (int i = 0; i < this->total; ++i) {
		question = calc->MakeFormula();
		ret = calc->Solve(question);
		writer << ret << endl;
		//cout << ret << endl;
	}
	writer.close();
}

int main(int argc, char* argv[])
{
	Calculator* calc = new Calculator();
	
	int n;
	
	if (argc < 2) {
		cout << "Please give the total number n!" << endl;
	}
	else {
		string num = argv[1];
		stringstream check(num);
		if (check >> n) {
			QuestionBuilder* builder = new QuestionBuilder(calc);
			builder->Make(n);
		}
		else {
			cout << "The number n should be integer!" << endl;
		}
	}
	//cin >> n;
	
	/*string question = calc->MakeFormula();
	cout << question << endl;
	string ret = calc->Solve("3*60-2");
	cout << ret << endl;*/
	//getchar();
}


