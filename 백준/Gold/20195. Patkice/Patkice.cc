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

int n, m, xx, yy;

vector<string> arr;
vector<vector<int>> v;
int dx[] = {0,-1,1,0};
int dy[] = {1,0,0,-1};
int moveto(char c)
{
    if (c == '>') return 0;
    if (c == '^') return 1;
    if (c == 'v') return 2;
    if (c == '<') return 3;
    else return -1;
}
int go(int x, int y, int c)
{
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '.' || v[x][y] == 1) return -1;
    if (arr[x][y] == 'x') return c;
    v[x][y] = 1;
    int m = moveto(arr[x][y]);
    return go(x+dx[m],y+dy[m],c+1);
}
void solve()
{
    cin >> n >> m;
    
    arr.resize(n);
    v.resize(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'o')
            {
                xx = i;
                yy = j;
            }
        }
    }
    
    int res = -1;
    int cnt = 100000000;
    for (int i = 0; i < 4; i++)
    {
        int nx = xx+dx[i];
        int ny = yy+dy[i];
        for (int c = 0; c < n; c++)
        {
            for (int r = 0; r < m; r++)
            {
                v[c][r] = 0;
            }
        }
        v[xx][yy] = 1;
        int r = go(nx,ny,0);
        if (r != -1 && r < cnt)
        {
            res = i;
            cnt = r;
        }
    }
    if (res == -1) cout << ":(";
    if (res == 0) cout << ":)\nE";
    if (res == 1) cout << ":)\nN";
    if (res == 2) cout << ":)\nS";
    if (res == 3) cout << ":)\nW";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}