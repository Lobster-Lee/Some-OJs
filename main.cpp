#include <iostream>
using namespace :: std;

int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << "true" << endl;
        return 0;
    }
    
    int A[n];
    for(int i = 0; i < n; i++)
        cin >> A[i];
    
    if(n == 2)
    {
        if(A[0] > 0)
        {
            cout << "true" << endl;
            return 0;
        }
        if(A[0] == 0)
        {
            cout << "flase" << endl;
            return 0;
        }
    }
    
    int max;
    for(int i = 0; i < n; i++)
		{
			if(i > max)
	        {
	            cout << "false" << endl;
	            return 0;
	        }
	        if(i+A[i] > max)
	            max = i+A[i];
		}
		cout << "true" << endl;
}
