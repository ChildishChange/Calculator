#include <stack>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Calculator.h"
#include <random>

using namespace std;
default_random_engine e;
#define random(a, b) (e()%((b)-(a)+1)+(a))

Calculator::Calculator() {}

string Calculator::MakeFormula() {
    string formula;

    int count = random(2, 3);
    int number = random(0, 100);
    formula += to_string(number);
    for(int i=0;i<count;i++) {
        int operation = random(0, 3);
        if (operation==3) {
            vector<int> s;
            for(int j=1;j<=sqrt(number);j++) {
                if (number%j==0) s.push_back(j);
            }
            s.push_back(number);
            number = s[random(0, s.size()-1)];
        } else {
            number = random(0,100);
        }

        formula += op[operation] + to_string(number);
    }

    return formula;
};

string Calculator::Solve(string formula) {
    auto *tempStack = new vector<string>();
    auto *operatorStack = new stack<char>();
    int len = formula.length();
    int k = 0;
    for (int j = -1; j < len - 1; j++) {
        char formulaChar = formula[j + 1];
        if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||
            formulaChar == '*' || formulaChar == '/') {
            if (j == len - 2) {
                tempStack->push_back(formula.substr(k));
            } else {
                if (k < j) {
                    tempStack->push_back(formula.substr(k, j + 1));
                }
                if (operatorStack->empty()) {
                    operatorStack->push(formulaChar);
                } else {
                    char stackChar = operatorStack->top();
                    if ((stackChar == '+' || stackChar == '-')
                        && (formulaChar == '*' || formulaChar == '/')) {
                        operatorStack->push(formulaChar);
                    } else {
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
    auto *calcStack = new stack<string>();
    for (int i = 0; i < tempStack->size(); i++) {
        string peekChar = tempStack->at(i);
        if (peekChar != "+" && peekChar != "-"
            && peekChar != "/" && peekChar != "*") {
            calcStack->push(peekChar);
        } else {
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
            } else if (peekChar == "-") {
                calcStack->push(to_string(a1 - b1));
            } else if (peekChar == "*") {
                calcStack->push(to_string(a1 * b1));
            } else if (peekChar == "/") {
                calcStack->push(to_string(a1 / b1));
            }
        }
    }
    return formula + "=" + calcStack->top();
}



