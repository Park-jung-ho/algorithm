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

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

void solve()
{
    int n, lx,ly, ex, ey;
    cin >> n >> lx >> ly >> ex >> ey;
    vector<vector<int>> arr(n,vector<int>(n));
    deque<ip> q = {{lx,ly}};
    arr[lx][ly] = 1;
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop_front();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != 0) continue;
            arr[nx][ny] = arr[x][y] + 1;
            q.push_back({nx,ny});
        }
        if (arr[ex][ey] != 0) break;
    }
    cout << arr[ex][ey] - 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}