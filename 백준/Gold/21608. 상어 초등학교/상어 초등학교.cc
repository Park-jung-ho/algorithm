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
    int n, a;
    cin >> n;
    vector<vector<int>> arr((n*n)+1,vector<int>(4));
    vector<vector<int>> res(n,vector<int>(n));
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    auto find = [&]()
    {
        int good = -1;
        int empty = -1;
        ip point = {n,n};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int g = 0;
                int e = 0;
                if (res[i][j] > 0) continue;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (res[nx][ny] == 0)
                    {
                        e++;
                        continue;
                    }
                    for (int h = 0; h < 4; h++)
                    {
                        if (res[nx][ny] == arr[a][h])
                        {
                            g++;
                            break;
                        }
                    }
                }
                if (g > good || (g == good && e > empty))
                {
                    point = {i,j};
                    good = g;
                    empty = e;
                }
            }
        }
        res[point.first][point.second] = a;
    };
    for (int i = 0; i < n*n; i++)
    {
        cin >> a;
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[a][j];
        }
        find();
    }
    int sol = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                for (int h = 0; h < 4; h++)
                {
                    if (res[nx][ny] == arr[res[i][j]][h])
                    {
                        cnt++;
                        break;
                    }
                }
            }
            sol += pow(10,cnt-1);
        }
    }
    cout << sol;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}