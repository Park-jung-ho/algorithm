#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <cmath>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
    cin >> N;
    vector<bool> run(4,true);
    vector<pair<int,int>> p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    int dx, dy;
    cin >> dx >> dy;
    
    for (int i = 0; i < N; i++)
    {
        int x, y;
        x = p[i].first - dx;
        y = p[i].second - dy;
        if (x >= 0 && y >= 0)
        {
            if (x == y)
            {
                run[0] = false;
                run[1] = false;
            }
            else if (x > y)
            {
                run[1] = false;
            }
            else if (x < y)
            {
                run[0] = false;
            }
        }
        else if (x >= 0 && y <= 0)
        {
            if (x == -y)
            {
                run[1] = false;
                run[2] = false;
            }
            else if (x > -y)
            {
                run[1] = false;
            }
            else if (x < -y)
            {
                run[2] = false;
            }
        }
        else if (x <= 0 && y <= 0)
        {
            if (x == y)
            {
                run[2] = false;
                run[3] = false;
            }
            else if (-x > -y)
            {
                run[3] = false;
            }
            else if (-x < -y)
            {
                run[2] = false;
            }
        }
        else if (x <= 0 && y >= 0)
        {
            if (-x == y)
            {
                run[0] = false;
                run[3] = false;
            }
            else if (-x > y)
            {
                run[3] = false;
            }
            else if (-x < y)
            {
                run[0] = false;
            }
        }
    }
    bool canrun = false;
    for (int i = 0; i < 4; i++)
    {
        if (run[i] == true)
        {
            canrun = true;
            break;
        }
    }
    if (canrun)
    {
        cout << "YES";
    }
    else{
        cout << "NO";
    }
	
    
	
	
	
}
