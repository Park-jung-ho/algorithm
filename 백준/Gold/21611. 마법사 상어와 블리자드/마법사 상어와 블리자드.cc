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
    int dx[] = { 0, 1, 0,-1};
    int dy[] = {-1, 0, 1, 0};
    int atk[] = {0,3,1,0,2};
    int n, m, d, s;
    int popcnt = 0;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(n));
    for (auto& ar : arr) for (auto& a : ar) cin >> a;

    auto pp = [&]()
    {
        cout << "===================\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == -1) cout << "x";
                else cout << arr[i][j];
                cout << " ";
            }
            cout << "\n";
        }
    };

    auto move = [&]()
    {
        int x = n/2;
        int y = n/2;
        int k = 1;
        int cnt = 0;
        int mv = -1;
        deque<int> q;
        while (1)
        {
            if (x < 0 || y < 0) break;
            if (cnt == 2) cnt = 0, k++;
            mv = (mv+1)%4;
            cnt++;
            for (int i = 0; i < k; i++)
            {
                x += dx[mv];
                y += dy[mv];
                if (x < 0 || y < 0) break;
                if (arr[x][y] > 0) q.push_back(arr[x][y]);
            }
        }
        x = n/2;
        y = n/2;
        k = 1;
        cnt = 0;
        mv = -1;
        while (1)
        {
            if (x < 0 || y < 0) break;
            if (cnt == 2) cnt = 0, k++;
            mv = (mv+1)%4;
            cnt++;
            for (int i = 0; i < k; i++)
            {
                x += dx[mv];
                y += dy[mv];
                if (x < 0 || y < 0) break;
                if (q.empty())
                {
                    arr[x][y] = 0;
                    continue;
                }
                arr[x][y] = q.front();
                q.pop_front();
            }
        }
        
    };
    auto pop = [&]()
    {
        int x = n/2;
        int y = n/2;
        int k = 1;
        int cnt = 0;
        int mv = -1;
        int pops = 0;
        deque<ip> q;
        while (1)
        {
            if (x < 0 || y < 0) break;
            if (cnt == 2) cnt = 0, k++;
            mv = (mv+1)%4;
            cnt++;
            for (int i = 0; i < k; i++)
            {
                x += dx[mv];
                y += dy[mv];
                if (x < 0 || y < 0) break;
                if (arr[x][y] < 1) continue;
                if (q.empty() || arr[q.front().first][q.front().second] == arr[x][y])
                {
                    q.push_back({x,y});
                }
                else
                {
                    if (q.size() > 3)
                    {
                        popcnt += arr[q.front().first][q.front().second] * q.size();
                        pops++;
                        while (!q.empty())
                        {
                            arr[q.front().first][q.front().second] = -1;
                            q.pop_front();
                        }
                    }
                    q = {{x,y}};
                }
            }
        }
        if (q.size() > 3)
        {
            pops++;
            popcnt += arr[q.front().first][q.front().second] * q.size();
            while (!q.empty())
            {
                arr[q.front().first][q.front().second] = -1;
                q.pop_front();
            }
        }
        return pops;
    };
    auto ab = [&]()
    {
        int x = n/2;
        int y = n/2;
        int k = 1;
        int cnt = 0;
        int mv = -1;
        deque<int> q;
        int v = 0;
        int vcnt = 0;
        while (1)
        {
            if (x < 0 || y < 0) break;
            if (cnt == 2) cnt = 0, k++;
            mv = (mv+1)%4;
            cnt++;
            for (int i = 0; i < k; i++)
            {
                x += dx[mv];
                y += dy[mv];
                if (x < 0 || y < 0) break;
                if (arr[x][y] < 1) continue;
                if (arr[x][y] == v)
                {
                    vcnt++;
                }
                else
                {
                    if (v != 0)
                    {
                        q.push_back(vcnt);
                        q.push_back(v);
                    }
                    vcnt = 1;
                    v = arr[x][y];
                }
            }
        }
        if (v != 0)
        {
            q.push_back(vcnt);
            q.push_back(v);
        }
        x = n/2;
        y = n/2;
        k = 1;
        cnt = 0;
        mv = -1;
        while (1)
        {
            if (x < 0 || y < 0) break;
            if (cnt == 2) cnt = 0, k++;
            mv = (mv+1)%4;
            cnt++;
            for (int i = 0; i < k; i++)
            {
                x += dx[mv];
                y += dy[mv];
                if (x < 0 || y < 0) break;
                if (q.empty())
                {
                    arr[x][y] = 0;
                    continue;
                }
                arr[x][y] = q.front();
                q.pop_front();
            }
        }
    };

    while (m--)
    {
        cin >> d >> s;
        d = atk[d];
        int x = n/2;
        int y = n/2;
        while (s--)
        {
            x += dx[d];
            y += dy[d];
            arr[x][y] = -1;
        }
        move();
        while (1)
        {
            if (pop() == 0) break;
            move();
        }
        ab();
    }
    cout << popcnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}