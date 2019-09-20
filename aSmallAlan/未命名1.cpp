#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string.h>
using namespace std;
int ri = 0;
int divisor (int a,int b)
{
  int  temp;
  if(a<b)
  {
      temp=a;
      a=b;
      b=temp;
    }
   while(b!=0)
   {
      temp=a%b;
      a=b;
      b=temp;
    }
  return a;
}
int CheckResult(char result[])
{
    char answer[10] ;
    cin>>answer;
    if(strcmp(answer,result)==0)
    {
        cout<<"回答正确"<<endl<<endl;
        ri++;
    }
    else
    {
        cout<<"回答错误,正确答案为"<<result<<endl<<endl;
    }
}
void integer()
{
    int x,y,z,temp;
    char result[10];
    srand(time(NULL));
    x = rand() % 10;
    y = rand() % 10+1;
    z = rand()%4;
    switch(z)
    {
        case 0 :
            cout<<x<<" + "<<y<<"=";
            temp = x + y;
            sprintf(result, "%d", temp);
            break;
        case 1 :
            if(x<y)
            {
                temp=x;
                x=y;
                y=temp;
            }
            cout<<x<<" - "<<y<<"=";
            temp = x - y;
            sprintf(result, "%d", temp);
            break;
        case 2 :
            cout<<x<<" * "<<y<<"=";
            temp = x * y;
            sprintf(result, "%d", temp);
            break;
        case 3 :
            cout<<x<<" ÷"<<y<<"=";
            if(x%y==0)
            {
                temp = x / y;
                sprintf(result, "%d", temp);
            }
            else
            {
                temp = divisor(x,y);
                x = x/temp;
                y = y/temp;
                sprintf(result, "%d/%d", x, y);
            }
            break;
    }
    CheckResult(result) ;
}

int main()
{
    int n,q;
    cout<<"输入要生成的题数:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a = rand();
    	integer();
    }
    q=(ri*100)/n;
    cout<<"回答对了"<<ri<<"题"<<endl;
    cout<<"正确率为:"<<q<<"%"<<endl<<endl;
}