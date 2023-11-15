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
    int N;
    string a;
    cin >> N >> a;
    vector<int> kmp(N);
    int k = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[k])
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
    }
    cout << N - kmp[N-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}