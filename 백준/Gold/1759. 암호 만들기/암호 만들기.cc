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

int n, m;
string a;
vector<char> arr;
char chk[] = {'a','e','i','o','u'};

int cnt = 0;
int cnt2 = 0;

void print(int c)
{
    if (a.size() == n && cnt > 0 && cnt2 > 1)
    {
        cout << a << "\n";
        return;        
    }
    for (int i = c; i < m; i++)
    {
        a.push_back(arr[i]);
        bool can = false;
        for (auto k : chk)
        {
            if (k == arr[i])
            {
                can = true;
                break;
            }
        }
        if (can) cnt++;
        else cnt2++;
        print(i+1);
        if (can) cnt--;
        else cnt2--;
        a.pop_back();
    }
}
void solve()
{
    a = "";
    cin >> n >> m;
    arr.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    print(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}