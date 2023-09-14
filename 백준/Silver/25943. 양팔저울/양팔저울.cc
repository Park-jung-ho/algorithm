#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int l = arr[0];
    int r = arr[1];
	for (int i = 2; i < N; i++)
    {
        if (l <= r)
        {
            l += arr[i];
        }
        else
        {
            r += arr[i];
        }
    }
    // cout << l << " " << r << "\n";
	int res = 0;
    int g[] = {100,50,20,10,5,2,1};
    // debug(l,r);
	
    int cnt = abs(l-r);
    int p = 0;
    for (int i = 0; i < 7; i++)
    {
        // debug(cnt,(int)cnt/g[i],p);
        if ((int)cnt/g[i] > 0)
        {
            p += (int)cnt/g[i];
            cnt -= (int)cnt/g[i] * g[i];
        }
        if (cnt == 0)
        {
            break;
        }
        
    }
    
    
    

    cout << p;
    
}
