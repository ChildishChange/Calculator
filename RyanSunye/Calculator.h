//
// Created by HP on 2020/3/1.
//

#ifndef RYANSUNYE_CALCULATOR_H
#define RYANSUNYE_CALCULATOR_H


#pragma once
#include <stack>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>

using namespace std;

#define DEBUG 0

class Calculator {
private:
    string op[4] = { "+", "-", "*", "/" };
public:
    Calculator();
    string MakeFormula();
    string Solve(string formula);
};

extern default_random_engine e;

#endif //RYANSUNYE_CALCULATOR_H
