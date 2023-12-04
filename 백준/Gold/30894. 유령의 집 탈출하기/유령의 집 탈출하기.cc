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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

struct info
{
    char b;
    int gs[4] = {0,0,0,0};
    int v[5] = {0,0,0,0,0};
};

void solve()
{
    int n, m, x1, x2, y1, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	x1--;
	x2--;
	y1--;
	y2--;
    vector<vector<info>> arr(n,vector<info>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j].b;    
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j].b != '.' && arr[i][j].b != '#')
            {
                int st = arr[i][j].b - '0';
                for (int k = 0; k < 4; k++)
                {
                    int nx = i;
                    int ny = j;
                    int nk = (st+k)%4;
                    while (1)
                    {
                        nx += dx[nk];
                        ny += dy[nk];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny].b == '.')
                        {
                        	arr[nx][ny].gs[k] = 1;
                        }
                        else
						{
							break;
						}
                    }
                }
                arr[i][j].b = '#';
            }
        }
    }

    deque<vector<int>> q;
	q.push_back({0,x1,y1});
	
    while (!q.empty())
    {
        
        int t = q.front()[0];
        int x = q.front()[1];
        int y = q.front()[2];

        q.pop_front();
		
		if (arr[x][y].gs[(t+1)%4] == 0 && arr[x][y].v[4] < 3)
		{
			arr[x][y].v[4]++;
			q.push_back({t+1,x,y});
		}
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny].b == '#')
            {
                continue;
            }
            
			if (arr[nx][ny].gs[(t+1)%4] == 0 && arr[nx][ny].v[(t+1)%4] == 0)
			{
                if (nx == x2 && ny == y2)
                {
                    cout << t+1;
			        return;
                }
                
				arr[nx][ny].v[(t+1)%4] = 1;
				q.push_back({t+1,nx,ny});
			}
        }   
    }
    cout << "GG";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}