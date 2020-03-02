#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include <cstdlib>
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	int count = random(1, 2);
	int start = 0;
	int number1 = random(1, 100);
	formula += to_string(number1);
	int pronumber = number1;
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(1, 100);
		if (operation == 2) {
			pronumber *= number2;
		}
		else if (operation == 3) {
			int up = pronumber < 100 ? pronumber : 100;
			while (pronumber % number2)
				number2 = random(1, up);
			pronumber /= number2;
		}
		else pronumber = number2;
		formula += op[operation] + to_string(number2);
		start++;
	}
	return formula;
};

string Calculator::Solve(string formula) {
	stack<char> opStack;
	stack<int> numStack;
	vector<int> polandExp;
	int len = formula.size();
	for (int i = 0, j; i < len; ++i) {
		char ch = formula[i];
		if (ch >= '0' && ch <= '9') {
			j = i; int number = 0;
			while (j < len && formula[j] >= '0' && formula[j] <= '9') {
				number = number * 10 + formula[j] - '0';
				++j;
			}
			i = j - 1;
			polandExp.push_back(number);
		}
		else {
			if (opStack.empty()) opStack.push(ch);
			else if (ch == '*' || ch == '/') {
				while (!opStack.empty() && (opStack.top() == '*' || opStack.top() == '/')) {
					polandExp.push_back((int)opStack.top() * -1);
					opStack.pop();
				}
				opStack.push(ch);
			}
			else {
				while (!opStack.empty()) {
					polandExp.push_back((int)opStack.top() * -1);
					opStack.pop();
				}
				opStack.push(ch);
			}
		}
	}
	while (!opStack.empty()) {
		polandExp.push_back((int)opStack.top() * -1);
		opStack.pop();
	}
	for (auto x : polandExp) {
		if (x >= 0) numStack.push(x);
		else {
			char operation = (char) -x;
			int b = numStack.top(); numStack.pop();
			int a = numStack.top(); numStack.pop();
			if (operation == '+') {
				a += b;
			}
			else if (operation == '-') {
				a -= b;
			}
			else if (operation == '*') {
				a *= b;
			}
			else if (operation == '/') {
				a /= b;
			}
			numStack.push(a);
		}
	}
	return formula + "=" + to_string((int) numStack.top());
}

int main()
{
	FILE* out;
	srand((unsigned int)time(NULL));
	auto err = fopen_s(&out, "subject.txt", "w");	
	Calculator* calc = new Calculator();
	int n;
	cin >> n;
	while (n--) {
		string question = calc->MakeFormula();
		fprintf(out, "%s\n", calc->Solve(question).c_str());
	}
}