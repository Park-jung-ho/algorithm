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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n,vector<int>(m));
    vector<int> res;
    while (k--)
    {
        int a, b, c, d;
        cin >> b >> a >> d >> c;
        for (int i = a; i < c; i++)
        {
            for (int j = b; j < d; j++)
            {
                arr[i][j] = 1;
            }
        }
    }
    
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1) continue;
            arr[i][j] = 1;
            deque<ip> q = {{i,j}};
            int cnt = 1;
            
            while (!q.empty())
            {
                auto [x,y] = q.front();
                q.pop_front();
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 1) continue;
                    arr[nx][ny] = 1;
                    q.push_back({nx,ny});
                    cnt++;
                }
            }
            res.push_back(cnt);
        }
    }
    cout << res.size() << "\n";
    sort(all(res));
    for (auto c : res) cout << c << " ";
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
