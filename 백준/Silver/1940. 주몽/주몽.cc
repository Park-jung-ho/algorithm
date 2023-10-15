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

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    int idx = N-1;
    int res = 0;
    if (N == 1)
    {
        cout << 0;
        return;
    }
    for (int i = 0; i < N-1; i++)
    {
        for (int j = idx; j > i; j--)
        {
            if (arr[i] + arr[j] == M)
            {
                // debug(i,j,arr[i],arr[j]);
                res++;
            }
            if (arr[i] + arr[j] <= M)
            {
                idx = j;
                break;
            }
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}