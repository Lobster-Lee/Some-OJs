#include <iostream>
#include <stack>
#include <vector>
#include "math.h"
using namespace :: std;

struct ternary
{
    int bits[21] = {0};
    int value = 0;
};

void NumTransform(ternary A[], int m)
{
    int i = 0;
    int n = fabs(A[m].value);
    int temp;
    
    while(n != 0)
    {
        temp = n % 3;
        n = n / 3;
        A[m].bits[i] = temp;
        i++;
    }
}

int main()
{
    int temp;
    int Num = 0;
    stack<int> mystack;
    int n;
    cin >> n;
    ternary A_positive[n];
    ternary A_negative[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp >= 0)
            A_positive[i].value = temp;
        if(temp < 0 && temp != -2147483648)
            A_negative[i].value = temp;
        if(temp == -2147483648)
            Num++;
    }
    
    for(int i = 0; i < n; i++)
    {
        NumTransform(A_positive, i);
        NumTransform(A_negative, i);
    }
    
    int sum_positive;
    int sum_negative;
    bool symbol = 0;
    for(int i = 0; i < 21; i++)
    {
        sum_positive = 0;
        sum_negative = 0;
        for(int j = 0; j < n; j++)
        {
            sum_positive = sum_positive + A_positive[j].bits[i];
            sum_negative = sum_negative + A_negative[j].bits[i];
        }
        sum_positive = sum_positive % 3;
        sum_negative = sum_negative % 3;
        if(sum_positive == 0 && sum_negative != 0)
            symbol = 1;
        if(sum_positive != 0 && sum_negative == 0)
            symbol = 0;
        mystack.push(fabs(sum_positive + sum_negative));
    }
    
    int i = 20;
    int result = 0;
    while(!mystack.empty())
    {
        result = result + mystack.top() * (int)pow(3,i);
        i--;
        mystack.pop();
    }
    
    if(Num == 1)
    {
        cout << -2147483648 << endl;
    }
    else if(Num == 3 || Num == 0)
    {
        if(symbol)
            cout << 0 - result << endl;
        else
            cout << result << endl;
    }
}
