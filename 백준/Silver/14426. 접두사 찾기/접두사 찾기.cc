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


struct trie
{
    trie* next[26];
    bool endpoint;

    trie() {
        endpoint = false;
        for (int i = 0; i < 26; i++)
        {
            next[i] = nullptr;
        }
    }
    ~trie() {
        for (int i = 0; i < 26; i++)
        {
            if (next[i] != nullptr)
            {
                delete next[i];
            }
        }
    }
    void insert(string& a, int idx)
    {
        if (idx == a.size())
        {
            endpoint = true;
            return;
        }
        if (next[a[idx]-'a'] == nullptr)
        {
            next[a[idx]-'a'] = new trie;
        }
        next[a[idx]-'a']->insert(a,idx+1);
    }
    int search(string& a, int idx)
    {
        if (idx == a.size())
        {
            return 1;
        }
        if (next[a[idx]-'a'] == nullptr)
        {
            return 0;
        }
        return next[a[idx]-'a']->search(a,idx+1);
    }
};

void solve()
{
    int N, M;
    cin >> N >> M;
    trie T;
    string a;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        T.insert(a,0);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> a;
        cnt += T.search(a,0);
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}