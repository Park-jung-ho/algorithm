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
vector<int> op(4);
vector<int> arr;
int N;
int mx = -1000000001;
int mn = 1000000001;

int oper(int i, int a, int b)
{
    if (i == 0)
    {
        return a+b;
    }
    if (i == 1)
    {
        return a-b;
    }
    if (i == 2)
    {
        return a*b;
    }
    if (i == 3)
    {
        return a/b;
    }
}

void back(int n,int v)
{
    if (n == N)
    {
        mx = max(mx,v);
        mn = min(mn,v);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;
            back(n+1,oper(i,v,arr[n]));
            op[i]++;
        }
    }
}

void solve()
{
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i]; 
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> op[i]; 
    }
    debug(arr,op);
    back(1,arr[0]);
    cout << mx << " " << mn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}