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
#include "DEBUG.h"
#else
#define debug(x...)
#endif


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    map<int,set<int>*> S;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        S[i+1] = new set<int>;
        for (int j = 0; j < a; j++)
        {
            int b;
            cin >> b;
            S[i+1]->insert(b);
        }
        
    }
    while (m--)
    {
        int q, a, b;
        cin >> q;
        if (q == 1)
        {
            cin >> b >> a;
            if (S[b]->size() >= S[a]->size())
            {
                S[b]->insert(S[a]->begin(),S[a]->end());
                S[a] = new set<int>;
            }
            else{
                S[a]->insert(S[b]->begin(),S[b]->end());
                S[b] = S[a]; 
                S[a] = new set<int>;
            }
        }
        else
        {
            cin >> a;
            cout << S[a]->size() << '\n';
        }
    }
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}