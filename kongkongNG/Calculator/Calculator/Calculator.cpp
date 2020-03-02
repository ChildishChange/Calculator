
#include "Calculator.h"

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";

	int count = random(2, 3);
	int start = 1;
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
	string num = "";
	for (int j = 0; j < len; j++) {
		char formulaChar = formula[j];
		if (formulaChar == '+' || formulaChar == '-' ||
			formulaChar == '*' || formulaChar == '/') {
			/*if (k < j) {
				tempStack->push_back(formula.substr(k, j));
			}*/
			tempStack->push_back(num);
			num = "";
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
		else {
			num.push_back(formulaChar);
		}
	}
	tempStack->push_back(num);

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
				if (a1 % b1 != 0) {
					return "wrong";
				}
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
	string question;
	srand((unsigned int)time(NULL));
	cin >> n;
	while (n) {
		question = calc->MakeFormula();
		//cout << question << endl;
		string ret = calc->Solve(question);
		if (ret == "wrong") {
			continue;
		}
		cout << ret << endl;
		n--;
	}
	
	//getchar();
	return 0;
	//for (int i = 0; i < 10000000; i++) {
	//	Calculator* calc = new Calculator();
	//	string question = calc->MakeFormula();
	//	cout << question << endl;
	//	string ret = calc->Solve("11+22");
	//	cout << ret << endl;
	//}
}


