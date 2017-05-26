#include <iostream>
#include <string>
using namespace :: std;

struct NumList
{
    char RomeNum;
    int realNum;
} List[7] = {
        'I', 1, 'V', 5, 'X', 10, 'L', 50, 'C', 100, 'D', 500, 'M', 1000
    };

int main()
{
    int s = 0;
    int temp, tempCopy;
    string inputStr;
    cin >> inputStr;
    for(int i = 0; i < inputStr.size(); i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(inputStr[i] == List[j].RomeNum)
            {
                temp = List[j].realNum;
                break;
            }
        }

        if(i != 0)
        {
            if(temp > tempCopy && (tempCopy == 1 || tempCopy == 10 || tempCopy == 100))
                s = s + temp - 2 * tempCopy;
            else
                s = s + temp;
        }
        else if(i == 0)
            s = s + temp;

        tempCopy = temp;
    }

    cout << s << endl;
}
