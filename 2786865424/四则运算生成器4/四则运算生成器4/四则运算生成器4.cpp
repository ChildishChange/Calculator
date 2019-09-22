

#include "pch.h"
#include <iostream>
#include<string>
#include<ctime>
#include<stack>
#include<fstream>
#define random()(rand()%1000)
using namespace std;

stack<int> s1;
stack<char> s2;
typedef struct node {
	int sss[4];
	char oppp[4];
	int result=0;
	int ca;
}T;
T k[50];

char op(int a)
{
	char c[4] = { '+','-','*','/' };
	return c[a];
}
string formula(int n)
{
	string suanshi;
	int num1, num2, temp, a, t, count, i, j, Q;
	char c;
	k[n].sss[0] = random() % 100 + 1;
	suanshi += to_string(k[n].sss[0]);
	do {
		count = random() % 3 + 1;
		k[n].ca = count;
	} while (count == 1);
	for (i = 0; i < count; i++)
	{
		a = random() % 4;
		c = op(a);
		k[n].oppp[i] = c;
		k[n].sss[i + 1] = random() % 100 + 1;
		if (c == '/')
		{
			while(k[n].sss[i] < k[n].sss[i+1]){
				k[n].sss[i+1] = random() % 100 + 1;
			}
			while (k[n].sss[i] % k[n].sss[i+1] != 0)
			{
				Q = k[n].sss[i] % k[n].sss[i+1];
				k[n].sss[i+1]= Q;
			}
		}
		suanshi+= op(a) + to_string(k[n].sss[i+1]);
	}
	return suanshi;
}

void wenjian(string s[], int n)
{
	int i;
	ofstream out;
	out.open("daan.txt");
	for (i = 0; i < n; i++)
	{
		out<<s[i]<<endl;
	}
	out.close();
}

void Result(T k[], int n) {
	int i, top = 0, a = 0, b = 0, result = 0, l,t;
	char c;
	for (i = 0; i < n; i++)
	{
		while (top < k[i].ca) {
			if (top == 0)
			{
				s1.push(k[i].sss[top]);
				s1.push(k[i].sss[top + 1]);
				s2.push(k[i].oppp[top]);
				if (k[i].oppp[top] == '*')
				{
					a = s1.top();
					cout << a << endl;
					s1.pop();
					b = s1.top();
					cout << b << endl;
					s1.pop();
					s2.pop();
					result = b * a;
					cout << result << endl;
					s1.push(result);
				}
				else if (k[i].oppp[top] == '/')
				{
					a = s1.top();
					cout << a << endl;
					s1.pop();
					b = s1.top();
					cout << b << endl;
					s1.pop();
					s2.pop();
					result = b / a;
					cout << result << endl;
					s1.push(result);
					cout << s1.top()<<endl;
				}
				top++;
				cout << top << endl;
				//cout << s2.top() << endl;
				cout << s1.top() << endl;
			}
			if (top > 0 && top < k[i].ca - 1)
			{
				if (s2.top() == '-' && (k[i].oppp[top] == '-' || k[i].oppp[top] == '+'))
				{
					a = s1.top();
					s1.pop();
					b = s1.top();
					s1.pop();
					result = b - a;
					s1.push(result);
				}
				s1.push(k[i].sss[top + 1]);
				cout << s1.top() << endl;
				s2.push(k[i].oppp[top+1]);
				cout << s2.top() << endl;
				if (k[i].oppp[top] == '*')
				{
					a = s1.top();
					s1.pop();
					cout << a << endl;
					b = s1.top();
					cout << b << endl;
					s1.pop();
					s2.pop();
					result = b * a;
					s1.push(result);
				}
				if (k[i].oppp[top] == '/')
				{
					a = s1.top();
					s1.pop();
					cout << a << endl;
					b = s1.top();
					cout << b << endl;
					s1.pop();
					s2.pop();
					result = b / a;
					s1.push(result);
				}
			}
			if(k[i].ca==2)
			top++;
			 if (top == k[i].ca - 1)
			{
				if (s2.top() == '-' && (k[i].oppp[top] == '-' || k[i].oppp[top] == '+'))
				{
					a = s1.top();
					s1.pop();
					b = s1.top();
					s1.pop();
					result = b - a;
					s1.push(result);
				}
				s1.push(k[i].sss[top + 1]);
				s2.push(k[i].oppp[top]);
				cout << s1.size() << endl;
				cout << s2.top() << endl;
				do{
					a = s1.top();
					cout << a << endl;
					s1.pop();
					b = s1.top();
					cout << b << endl;
					s1.pop();
					c = s2.top();
					cout << c << endl;
					s2.pop();
					cout << s2.size() << endl;
					if (c == '-')
					{
						result = b - a;
						s1.push(result);
					}
					if (c == '+')
					{
						result = b + a;
						s1.push(result);
					}
					if (c == '*')
					{
						result = b * a;
						s1.push(result);
					}
					if (c == '/')
					{
						result = b / a;
						s1.push(result);
					}
				} while (s2.size() != 0);
			}
			k[i].result = result;
		}
	}
}




int main()
{
	srand((unsigned)time(0));
	int i, n;
	cout << "需要生成多少道题目（小于50）：";
	cin >> n;
	string c;
	string s[50];
	c = "=";
	for (i = 0; i < n; i++)
	{
		s[i] = formula(i)+c;
		cout << s[i] << endl;
	}
	wenjian(s, n);
	Result(k, n);
	cout << k[0].result << endl;
	

	
	return 0;
}