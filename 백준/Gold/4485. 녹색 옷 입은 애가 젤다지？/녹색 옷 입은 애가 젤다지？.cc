#include <bits/stdc++.h>
#include <queue>
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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int cnt = 0;
void solve(int N)
{
    vector<vector<int>> arr(N,vector<int>(N));
    vector<vector<int>> visit(N,vector<int>(N));
    priority_queue<vector<int>> pq;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    pq.push({-arr[0][0],0,0});
    while (!pq.empty())
    {
        int v = -pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();
        
        if (x == N-1 && y == N-1)
        {
            cout << "Problem " << cnt << ": " << v << "\n";
            break;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            {
                continue;
            }
            if (visit[nx][ny] == 0)
            {
                visit[nx][ny] = 1;
                pq.push({-(v+arr[nx][ny]),nx,ny});
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (1){
        cnt++;
        int N;
        cin >> N;
        if (N==0)
        {
            break;
        }
        solve(N);

    }
}