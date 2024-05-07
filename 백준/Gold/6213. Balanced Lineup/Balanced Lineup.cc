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

void init(vector<ll>& a, vector<ip>& tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node].first = a[start];
        tree[node].second = a[start];
    }
    else
    {
        init(a,tree,node*2,start,(start+end)/2);
        init(a,tree,node*2+1,(start+end)/2+1,end);
        int f = min(tree[node*2].first,tree[node*2+1].first);
        int s = max(tree[node*2].second,tree[node*2+1].second);
        tree[node].first = f;
        tree[node].second = s;
    }
}
void update(vector<ll>& a, vector<ll>& tree, int node, int start, int end, int idx, ll val)
{
    if (idx < start || idx > end) return;
    if (start == end)
    {
        a[idx] = val;
        tree[node] = val;
        return;
    }
    update(a,tree,node*2,start,(start+end)/2,idx,val);
    update(a,tree,node*2+1,(start+end)/2+1,end,idx,val);
    tree[node] = tree[node*2] + tree[node*2+1];
}
ip query(vector<ip>& tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return {1000000,0};
    if (left <= start && end <= right) return tree[node];
    ip l = query(tree,node*2,start,(start+end)/2,left,right);
    ip r = query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return {min(l.first,r.first),max(l.second,r.second)};
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto&c : a) cin >> c;

    int h = (int)ceil(log2(n));
    h = (1 << (h+1));
    vector<ip> tree(h);
    init(a,tree,1,0,n-1);
    int x, y, k;
    while (q--)
    {
        cin >> x >> y; 
        ip r = query(tree,1,0,n-1,x-1,y-1);
        cout << r.second - r.first << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}