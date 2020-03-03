
 
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"
#include <fstream>

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";

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
	double num = 0;
	for (int i = 0; i < formula.length();) {
		bool plus = true;
		if (i != 0) {
			plus = formula[i++] == '+';
		}
		int start = i;
		while (isdigit(formula[i])) {
			i++;
		}
		double tmp = stoi(formula.substr(start, i));
		while (i < formula.length() && (formula[i] == '*' || formula[i] == '/')) {
			char op = formula[i++];
			 
				int start = i;
				while (isdigit(formula[i])) {
					i++;
				}
				if (op == '*') {
					tmp = tmp * stoi(formula.substr(start, i));
				}
				else {
					tmp = tmp / stoi(formula.substr(start, i));
				}

		}
		if (tmp - (int)tmp != 0) {
			return "";
		}
		if (plus) {
			num = num + tmp;
		}
		else {
			num = num - tmp;
		}
		
	}
	return formula + "=" + to_string((int)num);
}

int main()
{
	Calculator* calc = new Calculator();
	int n;
	cin >> n;
	ofstream file;
	file.open("subject.txt");
	for (int i = 0; i < n; i++) {
		string question = calc->MakeFormula();
		string ret = calc->Solve(question);
		if (ret == "") {
			i--;
			continue;
		}
		file << ret << endl;
	}
}
 


