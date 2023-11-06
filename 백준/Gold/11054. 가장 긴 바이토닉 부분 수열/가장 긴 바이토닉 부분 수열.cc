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
#include "DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    vector<int> dpu(n);
    vector<int> dpd(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n-1; i++){
        if (dpu[i]==0)
        {
            dpu[i]++;
        }
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                dpu[j] = max(dpu[j],dpu[i]+1);
            }
        }
    }
    for (int i = n-1; i > 0; i--){
        if (dpd[i]==0)
        {
            dpd[i]++;
        }
        for (int j = i-1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                dpd[j] = max(dpd[j],dpd[i]+1);
            }
        }
    }
    int mx = 1;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx,dpu[i]+dpd[i]-1);
    }
    cout << mx;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}