#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ip = pair<int, int>;
using ld = long double;
using lp = pair<ll, ll>;

#define all(v) (v).begin(), (v).end()

#ifndef ONLINE_JUDGE
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

int N, M, K;

struct cmp
{
    bool operator()(ip&a, ip&b){
        return a.first < b.first;
    }
};
bool compare(ip&a, ip&b)
{
    return a.second < b.second;
}

void solve()
{
    cin >> N;
    // vector<ip> Atop(N);
    vector<ip> Btop(N);
    priority_queue<ip,vector<ip>,cmp> pq;
    set<ip> used;
    
    for (int i = 0; i < N; i++)
    {
        cin >> Btop[i].first;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> Btop[i].second;
        // pq.push(Btop[i]);
    }
    // sort(all(Atop),greater<>());
    sort(all(Btop),compare);
    debug(Btop);
    // while (!pq.empty())
    // {
    //     debug(pq.top());
    //     pq.pop();
    // }
    ll cnt = Btop[0].first;
    int draw = 2;
    debug(Btop[0]);
    for (int i = 1; i < N-1; i++)
    {
        if (draw > 0)
        {
            draw--;
            pq.push(Btop[i]);
        }
        if (draw == 0)
        {
            draw = 2;
            cnt += pq.top().first;
            debug(pq.top());
            pq.pop();
        }
    }
    
    

    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}