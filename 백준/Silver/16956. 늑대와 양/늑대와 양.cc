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
    int n, m;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    cin >> n >> m;
    vector<string> arr(n);
    for (auto& a : arr) cin >> a;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'W')
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == 'W') continue;
                    if (arr[x][y] == 'S')
                    {
                        cout << 0;
                        return;
                    }
                    arr[x][y] = 'D';
                }
            }
        }
    }
    cout << "1\n";
    for (auto& a : arr) cout << a << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}