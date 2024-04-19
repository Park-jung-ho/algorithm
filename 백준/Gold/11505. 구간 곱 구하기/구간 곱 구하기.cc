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

int mod = 1000000007;

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
        tree[node] = ((tree[node*2]%mod)*(tree[node*2+1]%mod))%mod;
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
    tree[node] = ((tree[node*2]%mod)*(tree[node*2+1]%mod))%mod;
}
ll query(vector<ll>& tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];
    ll l = query(tree,node*2,start,(start+end)/2,left,right);
    ll r = query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return ((l%mod)*(r%mod))%mod;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    for (auto& a : arr) cin >> a;

    int h = (int)ceil(log2(n));
    h = (1 << (h+1));
    vector<ll> tree(h);
    init(arr,tree,1,0,n-1);

    int q = m+k;
    int a, b, c;
    while (q--)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(arr,tree,1,0,n-1,b-1,c);
        }
        else
        {
            cout << query(tree,1,0,n-1,b-1,c-1) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}