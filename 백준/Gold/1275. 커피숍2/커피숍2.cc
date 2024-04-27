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

void init(vector<ll>& a, vector<ll>& tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        init(a,tree,node*2,start,(start+end)/2);
        init(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node] = tree[node*2] + tree[node*2+1];
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
ll query(vector<ll>& tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    ll l = query(tree,node*2,start,(start+end)/2,left,right);
    ll r = query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return l + r;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (auto& a : arr) cin >> a;

    int h = (int)ceil(log2(n));
    h = (1 << (h+1));
    vector<ll> tree(h);
    init(arr,tree,1,0,n-1);

    int x, y, a, b;
    while (q--)
    {
        cin >> x >> y >> a >> b; 
        cout << query(tree,1,0,n-1,min(x,y)-1,max(x,y)-1) << "\n";
        update(arr,tree,1,0,n-1,a-1,b);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}