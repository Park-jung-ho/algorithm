#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()



void solve()
{
    string s;
    cin >> s;

    istringstream ss1(s);
    string buffer;
    int res = 0;
    while(getline(ss1,buffer,',')){
        res++;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}