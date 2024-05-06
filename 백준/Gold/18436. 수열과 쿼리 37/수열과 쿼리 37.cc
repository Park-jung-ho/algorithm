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
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        if (c%2==0)
        {
            a[i] = 1;
            b[i] = 0;
        }
        else
        {
            a[i] = 0;
            b[i] = 1;
        }
    }

    int h = (int)ceil(log2(n));
    h = (1 << (h+1));
    vector<ll> tree(h);
    vector<ll> tree2(h);
    init(a,tree,1,0,n-1);
    init(b,tree2,1,0,n-1);
    cin >> q;
    int x, y, k;
    while (q--)
    {
        cin >> k >> x >> y; 
        if (k == 1)
        {
            if (y%2==0)
            {
                update(a,tree,1,0,n-1,x-1,1);
                update(b,tree2,1,0,n-1,x-1,0);
            }
            else
            {
                update(b,tree2,1,0,n-1,x-1,1);
                update(a,tree,1,0,n-1,x-1,0);
            }
        }
        if (k == 2)
        {
            cout << query(tree,1,0,n-1,x-1,y-1) << "\n";
        }
        if (k == 3)
        {
            cout << query(tree2,1,0,n-1,x-1,y-1) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}