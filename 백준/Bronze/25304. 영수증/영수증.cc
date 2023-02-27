#include <iostream>

using namespace std;

int main()
{
    int x, t;
    cin >> x >> t;
    for (int i = 0; i < t; i++)
    {   
        int val, cnt;
        cin >> val >> cnt;
        x -= val*cnt;
    }
    if (x == 0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
    return 0;
}