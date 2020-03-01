#include <stack>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Calculator.h"
#include <random>
#include <cassert>

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

bool is_add(char op){
    return op=='+'||op=='-';
}

bool is_mul(char op){
    return op=='*'||op=='/';
}

int excute(int num1, int num2, char op) {
    switch (op){
        case '+':
            return num1+num2;
        case '-':
            return num1-num2;
        case '*':
            return num1*num2;
        case '/':
            return num1/num2;
        default:
            cout<<"no such operation!"<<endl;
            exit(1111);
    }
}

string Calculator::Solve(string formula) {
    stack<int> num_stack;
    stack<char> op_stack;

    if(DEBUG)cout<<formula<<endl;
    int j=0;
    for(int i=0;i<formula.size();i++) {
        if(is_add(formula[i])||is_mul(formula[i])) {
            num_stack.push(stoi(formula.substr(j,i-j)));
            j=i+1;

            if(!op_stack.empty())
                if (is_add(formula[i])||(is_mul(formula[i])&&is_mul(op_stack.top()))){
                    char operation = op_stack.top();
                    op_stack.pop();
                    int num2 = num_stack.top();
                    num_stack.pop();
                    int num1 = num_stack.top();
                    num_stack.pop();
                    num_stack.push(excute(num1, num2, operation));
                    if(DEBUG)cout<<num1<<operation<<num2<<'='<<excute(num1, num2, operation)<<endl;
                }
            op_stack.push(formula[i]);

        }
    }
    num_stack.push(stoi(formula.substr(j, formula.size()-j)));
    while(!op_stack.empty()){
        char operation = op_stack.top();
        op_stack.pop();
        int num2 = num_stack.top();
        num_stack.pop();
        int num1 = num_stack.top();
        num_stack.pop();
        num_stack.push(excute(num1, num2, operation));
        if(DEBUG)cout<<num1<<operation<<num2<<'='<<excute(num1, num2, operation)<<endl;
    }

    return formula + '='+ to_string(num_stack.top());
}



