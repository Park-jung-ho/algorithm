#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <utility>
using namespace std;

#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int n, m;
vector<vector<int>> v;
int ans = 0;

void sooff_xve()
{
    cin >> n >> m;
    v.resize(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            cin >> v[i][j];
            v[i][j] += v[i][j-1];
        }
    }
    debug(v);

    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 우측 아래 탐색
            debug(i, j);

            // row++
            for (int off_x = 0; off_x <= m - j; off_x++)
            {
                int sumv = 0;
                for (int off_y = 0; off_y <= n - i; off_y++)
                {
                    debug(off_x,off_y);
                    sumv += v[i+off_y][j+off_x] - v[i+off_y][j -1];  // row sum
                    debug(sumv);
                    if(sumv < 10)
                    {
                        continue;
                    }
                    else if(sumv > 10)
                    {
                        break;
                    }
                    else if(sumv == 10) // success
                    {
                        debug("ans!!!!!!!!!");
                        ans++;
                        break;
                    }
                }
            }
            
                debug("=============");
        }
        
    }
    cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    sooff_xve();
} 
