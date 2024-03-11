#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

void solve()
{
    int N, Q, k;
    cin >> N >> Q;
    vector<ll> arr(N+1);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    int cnt = 0;
    int a, b;

    while (Q--)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> a;
            cnt += N-a;
        }
        if (k == 2)
        {
            cin >> a;
            cnt += a;
        }
        if (k == 3)
        {
            cin >> a >> b;
            a += cnt;
            b += cnt;
            if (a > N) a -= N;
            if (b > N) b -= N;
            if (a <= b)
            {
                cout << arr[b] - arr[a-1] << "\n";
            }
            else
            {
                cout << arr[N] - arr[a-1] + arr[b] << "\n";
            }
        }

        cnt %= N;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}