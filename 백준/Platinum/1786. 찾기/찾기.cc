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
    string a, b;
    getline(cin,a);
    getline(cin,b);
    int cnt = 0;
    vector<int> res;
    vector<int> kmp(b.size());
    int k = 0;
    for (int i = 1; i < b.size(); i++)
    {
        if (b[i] == b[k])
        {
            kmp[i] = k+1;
            k++;
        }
        else if(k != 0)
        {   
            if (kmp[k-1] != 0)
            {
                k = kmp[k-1];
            }
            else{
                k = 0;
            }
            i--;
        }
        
        
        // debug(kmp,k);
    }
    k = 0;
    
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[k])
        {
            // debug(i,k,a[i],b[k]);
            k++;
        }
        else if(k!=0)
        {
            i--;
            k = kmp[k-1];
        }
        if (k == b.size())
        {
            cnt++;
            res.push_back(i-k+2);
            k = kmp[k-1];
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}