//
// Created by HP on 2020/3/1.
//

#include "Calculator.h"

int main()
{
    Calculator* calc = new Calculator();
    string question = calc->MakeFormula();
    cout << question << endl;
    string ret = calc->Solve("11+22");
    cout << ret << endl;
    getchar();
}
