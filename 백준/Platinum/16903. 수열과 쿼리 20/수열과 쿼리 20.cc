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
	trie* next[2];
    int cnt;
	trie() : next(), cnt(0) {}

	void insert(string& a, int idx)
	{
		if (a.size() == idx)
		{
			return;
		}
		if (next[a[idx]-'0'] == nullptr)
		{
			next[a[idx]-'0'] = new trie;
		}
        next[a[idx]-'0']->cnt++;
		next[a[idx]-'0']->insert(a,idx+1);
	}
	void del(string& a, int idx)
	{
		if (a.size() == idx)
		{
			return;
		}
        next[a[idx]-'0']->cnt--;
		if (next[a[idx]-'0']->cnt == 0)
		{
			next[a[idx]-'0'] = nullptr;
            return;
		}
		next[a[idx]-'0']->del(a,idx+1);
	}

	void find(string& a, int idx, int& v)
	{
		if (a.size() == idx)
		{
			return;
		}
		int e = a[idx]-'0' == 1 ? 0 : 1;
		if (next[e] != nullptr)
		{
			v += pow(2,29-idx);
			next[e]->find(a,idx+1,v);
		}
		else{
			next[a[idx]-'0']->find(a,idx+1,v);
		}
	}
};


void solve()
{
	int N;
	cin >> N;
	trie t;
    string b = bitset<30>(0).to_string();
    t.insert(b,0);
	
    while (N--)
	{
	    int res = 0;
		int q, a;
		cin >> q >> a;
		b = bitset<30>(a).to_string();
        if (q == 1)
        {
		    t.insert(b,0);
        }
        if (q == 2)
        {
            t.del(b,0);
        }
        if (q == 3)
        {
			int v = 0;
			t.find(b,0,v);
			res = max(res,v);
            cout << res << "\n";    
        }
        
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}