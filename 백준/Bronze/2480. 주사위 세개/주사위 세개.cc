#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    
    if(x == y && y == z){
        cout << 10000 + x*1000;
    }
    else if (x == y)
    {
        cout << 1000 + x*100;
    }
    else if (z == y)
    {
        cout << 1000 + z*100;
    }
    else if (z == x)
    {
        cout << 1000 + z*100;
    }
    else
    {
        int m = max(max(x, y), z);
        cout << m*100;
    }

        

    return 0;
}