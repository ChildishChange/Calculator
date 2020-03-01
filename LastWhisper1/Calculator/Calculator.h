#pragma once
//#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>  
using namespace std;

#define random(a,b) (rand()%(b-a+1)+a)

class Calculator {
private:
	string op[4] = { "+", "-", "*", "/" };
public:
	Calculator();
	string MakeFormula();
	string Solve(string formula);
};

int findFactor(int num) {
	//对一个100以内的正整数尝试寻找因子
	//如果是合数，则在2~10以内随机返回一个因子
	//如果是质数，返回1
	int farr[9] = {0};
	int fcnt = 0;
	for (int i = 2; i <= 10; i++) {
		if (num % i == 0 && num != i) {
			farr[fcnt++] = i;
		}
	}
	if (fcnt == 0) return 1;
	else {
		//srand((unsigned int)time(NULL));
		return farr[random(0, fcnt-1)];
	}
}
