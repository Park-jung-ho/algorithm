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

long long N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
    int cnt = 1;
	
    while (1)
    {
        long long a = (cnt+1) * (long long)pow(2,(cnt+1)) - 1;
        if (a >= N)
        {
            break;
        }
        cnt++;
    }
    cout << cnt;
}
