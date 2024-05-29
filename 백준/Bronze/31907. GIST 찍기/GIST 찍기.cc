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
    int a;
    cin >> a;
    vector<vector<char>> pr(a*3,vector<char>(a*4,'.'));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            pr[i][j] = 'G';
        }
    }
    for (int i = a; i < a*2; i++)
    {
        for (int j = a; j < a*2; j++)
        {
            pr[i][j] = 'I';
        }
    }
    for (int i = a; i < a*2; i++)
    {
        for (int j = a*3; j < a*4; j++)
        {
            pr[i][j] = 'T';
        }
    }
    for (int i = a*2; i < a*3; i++)
    {
        for (int j = a*2; j < a*3; j++)
        {
            pr[i][j] = 'S';
        }
    }
    for (int i = 0; i < a*3; i++)
    {
        for (int j = 0; j < a*4; j++)
        {
            cout << pr[i][j];
        }
        cout << "\n";
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}