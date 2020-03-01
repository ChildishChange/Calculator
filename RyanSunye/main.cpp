//
// Created by HP on 2020/3/1.
//

#include "Calculator.h"
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
    int n;
    cin>>n;

    ofstream out("subject.txt");
    auto* calc = new Calculator();

    e.seed((unsigned int)time(nullptr));

    for(int i=0;i<n;i++){
        string question = calc->MakeFormula();
        string ret = calc->Solve(question);
//        cout << ret << endl;
//        out << ret << endl;
    }

    out.close();
}
