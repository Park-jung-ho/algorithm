#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()
#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x...)
#endif

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
double per[] = {0.01,0.07,0.1};
int mv[] = {1,2,1};
vector<int> lr = {1,3};
int res = 0;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int x = n/2;
    int y = n/2;
    int way = 0;
    int speed = 1;
    int hz = 0;
    while (1)
    {
        if (hz == 2)
        {
            hz = 0;
            speed++;
        }
        hz++;
        for (int i = 0; i < speed; i++)
        {
            int mx = x + dx[way];
            int my = y + dy[way];

            if (x == 0 && y == 0) break;

            int nx = x;
            int ny = y;
            int cnt = 0;
            // debug(x,y);
            for (int k = 0; k < 3; k++)
            {
                nx = x + (dx[way] * k);
                ny = y + (dy[way] * k);
                for (auto l : lr)
                {
                    for (int m = 0; m < mv[k]; m++)
                    {
                        double pk = per[k];
                        if (m == 1) pk = 0.02;
                        nx += dx[(way+l)%4];
                        ny += dy[(way+l)%4];

                        cnt += arr[mx][my] * pk;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                        {
                            arr[nx][ny] += arr[mx][my] * pk;
                        }
                        else
                        {
                            res += arr[mx][my] * pk;
                        }  
                        // debug(nx,ny,cnt,res);  
                    }
                    nx -= dx[(way+l)%4] * mv[k];
                    ny -= dy[(way+l)%4] * mv[k];
                }
            }
            nx = x + (dx[way] * 3);
            ny = y + (dy[way] * 3);
            cnt += arr[mx][my] * 0.05;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                arr[nx][ny] += arr[mx][my] * 0.05;
            }    
            else
            {
                res += arr[mx][my] * 0.05;
            }  
            nx -= dx[way];
            ny -= dy[way];
            arr[mx][my] -= cnt;
            cnt = arr[mx][my];
            arr[mx][my] = 0;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                arr[nx][ny] += cnt;
            }    
            else
            {
                res += cnt;
            }  
            // debug(res);
            // for (int ii = 0; ii < n; ii++)
            // {
            //     for (int jj = 0; jj < n; jj++)
            //     {
            //         cout << arr[ii][jj] << " ";
            //     }
            //     cout << "\n";
            // }
            x = mx;
            y = my;
        }
        way = (way+1)%4;

        if (x == 0 && y == 0) break;
    }
    cout << res << "\n";
    

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}