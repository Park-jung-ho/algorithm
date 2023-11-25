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
	~trie() {
		if (next[0]) delete next[0];
		if (next[1]) delete next[1];
	}
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
	void del(string& a, int idx, int c)
	{
		if (a.size() == idx)
		{
			return;
		}
        next[a[idx]-'0']->cnt -= c;
		if (next[a[idx]-'0']->cnt == 0)
		{
			next[a[idx]-'0'] = nullptr;
            return;
		}
		next[a[idx]-'0']->del(a,idx+1,c);
	}

	void find(int mm, string& a, int idx, int& v)
	{
		// debug(v);
		if (a.size() == idx)
		{
			return;
		}
		int x = a[idx]-'0';
		if (mm == 1)
		{
			x = a[idx]-'0' == 1 ? 0 : 1;
		}
		int y = x == 1 ? 0 : 1;
		
		if (next[x] != nullptr)
		{
			if (mm == 1) v += pow(2,29-idx);
			next[x]->find(mm, a,idx+1,v);
		}
		else{
			if (mm == 0) v += pow(2,29-idx);
			next[y]->find(mm, a,idx+1,v);
		}
	}
};

void solve()
{
	int N, q;
	cin >> N >> q;
	trie t;
	map<int,int> s0;
	while (N--)
	{
		int a;
		cin >> a;
		if (s0.find(a) == s0.end())
		{
			s0[a] = 0;
		}
		s0[a]++;
		string b = bitset<30>(a).to_string();
		t.insert(b,0);
	}
	
    while (q--)
	{
	    int res = 0;
		int n, v;
		cin >> n;
        if (n == 1)
        {
			cin >> v;
			string b = bitset<30>(v).to_string();
			t.find(0,b,0,res);
			cout << res << "\n";
        }
        if (n == 2)
        {
			cin >> v;
			string b = bitset<30>(v).to_string();
			t.find(1,b,0,res);
			cout << res << "\n";
        }
        if (n == 3)
        {
			cin >> v;
			string b = bitset<30>(v).to_string();
			t.insert(b,0);
			if (s0.find(v) == s0.end())
			{
				s0[v] = 0;
			}
			s0[v]++;
			cout << s0.size() << "\n";
        }
		if (n == 4)
		{
			v = s0.begin()->first;
			cout << v << "\n";
			string b = bitset<30>(v).to_string();
			t.del(b,0,s0[v]);
			s0.erase(v);
		}
		if (n == 5)
		{
			v = s0.rbegin()->first;
			cout << v << "\n";
			string b = bitset<30>(v).to_string();
			t.del(b,0,s0[v]);
			s0.erase(v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	
}