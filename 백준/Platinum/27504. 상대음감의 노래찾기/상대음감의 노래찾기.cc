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
    int N, S, L;
    
    cin >> N;
    vector<vector<int>> arr(N);
    vector<vector<int>> kmp(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S;
        arr[i].resize(S,0);
        kmp[i].resize(S,0);
        for (int j = 0; j < S; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> L;
    vector<int> m(L);
    for (int i = 0; i < L; i++)
    {
        cin >> m[i];
    }
    debug(arr);
    vector<int> res;
    for (int c = 0; c < N; c++)
    {
        int k = 0;
        for (int i = 0; i < arr[c].size()-1; i++)
        {
            if (arr[c][i+1] - arr[c][i] == m[k+1]-m[k])
            {
                kmp[c][i+1] = k+1;
                k++;
            }
            else if(k != 0)
            {   
                k = kmp[c][k-1];
                i--;
            }
            if (k == L-1)
            {
                res.push_back(c+1);
                break;
            }
        }
    }
    // debug(kmp);
    for (auto c : res){
        cout << c << " ";
    }
    if (res.empty())
    {
        cout << -1;
    }
    
    
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}