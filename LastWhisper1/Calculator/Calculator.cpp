//#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"

#define ALLOWDIVISION 0 //是否包含除法
//#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
    string formula = "";
    //srand((unsigned int)time(NULL));
    int count = random(2, 3);
    int start = 0;
    int number1 = random(1, 100);
    formula += to_string(number1);
    while (start < count) {
        //目测这里没有实现除法结果一定为整数
        //先不考虑除法
#ifdef ALLOWDIVISION
        int operation = random(0, 3);
        int number2 = 0;
        if (operation==3) {
            //除法
            int factor = findFactor(number1);
            if (factor == 1) {
                //为了题目质量不生成a/1或a/a这样的算式
                operation = random(0, 2);
                number2 = random(1, 100);
            }
            else {
                number2 = random(0, 1) ? factor : (number1/factor);
            }
        }
        else {
            number2 = random(1, 100);
        }
#else 
        int operation = random(0, 2);
        int number2 = 0;
        number2 = random(1, 100);
#endif // ALLOWDIVISION
        formula += op[operation] + to_string(number2);
        number1 = number2;
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
                    //string.str(start, length)
                    tempStack->push_back(formula.substr(k, j + 1 - k));
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
                        //char被强转为int，按字符字面值转换为string
                        string ts = "a";
                        ts[0] = operatorStack->top();
                        tempStack->push_back(ts);
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
        //表达式的计算部分
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
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++) {
        string question = calc->MakeFormula();
        cout << question << endl;
        string ret = calc->Solve(question);
        cout << ret << endl;
    }
    getchar();
}


