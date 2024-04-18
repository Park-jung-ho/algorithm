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

vector<vector<int>> arr;
vector<vector<int>> v;
int n, m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void bt(int x, int y)
{
    if (x == n-1 && y == m-1)
    {
        v[x][y] = 1;
        return;
    }
    int cnt = 0;
    int can = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] >= arr[x][y]) 
        {
            cnt++;
            continue;
        }
        if (v[nx][ny] == -1)
        {
            v[nx][ny] = 0;
            bt(nx,ny);
        }
        if (v[nx][ny] > 0)
        {
            can += v[nx][ny];
        }
    }
    if (can > 0) v[x][y] = can;
    if (cnt == 4) v[x][y] = 0;
}

void solve()
{
    
    cin >> n >> m;
    arr.resize(n,vector<int>(m));
    v.resize(n,vector<int>(m,-1));
    for (auto& ar : arr) for (auto& a : ar) cin >> a;
    v[0][0] = 0;
    bt(0,0);
    cout << v[0][0];
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}