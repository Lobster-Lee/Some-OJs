#include <iostream>
#include <string>
using namespace :: std;

int main()
{
    int n;
    string str[30];
    str[0] = "1";
    str[1] = "11";
    int count;
    char temChar;

    if(n == 1)
    {
        cout << str[0] << endl;
        return 0;
    }
    if(n == 2)
    {
        cout << str[1] << endl;
        return 0;
    }
    
    
    for(int i = 2; i < 30; i++)
    {
        for(int j = 0; j < str[i-1].length(); j++)
        {
            if(j == 0)
            {
                count = 1;
                temChar = str[i-1].at(0);
            }
            else 
            {
                if(str[i-1].at(j) == str[i-1].at(j-1))
                {
                    count++;
                }
                else
                {
                    str[i].push_back((char)(int('0') + count));
                    str[i].push_back(str[i-1].at(j-1));
                    
                    temChar = str[i-1].at(j);
                    count = 1;
                }
                
                if(j == str[i-1].length()-1)
                {
                    if(str[i-1].at(j-1) == str[i-1].at(j))
                    {
                        str[i].push_back((char)(int('0') + count));
                        str[i].push_back(temChar);
                    }
                    else
                    {
                        str[i].push_back('1');
                        str[i].push_back(temChar);
                    }
                }
            }
        }
    }

    while(cin >> n)
        cout << str[n-1] << endl;
}
