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
#include "C:\DEBUG.h"
#else
#define debug(x...)
#endif

struct trie
{
	map<char,trie*> nxt;
	bool rm = true;
	bool ep = false;
	void insert(string& a, int idx)
	{
		if (idx == a.size())
		{
			ep = true;
			return;
		}
		if (nxt.find(a[idx]) == nxt.end())
		{
			nxt[a[idx]] = new trie;
		}
		nxt[a[idx]]->insert(a,idx+1);
	}

	void noRM(string& a, int idx)
	{
        rm = false;
		if (idx == a.size())
		{
            ep = false;
			return;
		}
		if (nxt.find(a[idx]) != nxt.end())
		{
			nxt[a[idx]]->noRM(a,idx+1);
		}
	}

	void del(int S,int& cnt)
	{
		if (rm)
		{
            // debug(rm);
			cnt++;
			return;
		}
        if (ep)
        {
            // debug(ep);
            cnt++;
        }
		for (auto iter = nxt.begin(); iter != nxt.end(); iter++)
		{
			// for (int i = 0; i < S; i++) cout << " ";
			// cout << iter->first << "\n";

			if (iter->second != nullptr)
			{
                nxt[iter->first]->del(S+1,cnt);
				
			}
		}
	}
};


void solve()
{
	int N, M;
	cin >> N;
	string a;
	trie T;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		T.insert(a,0);		
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		T.noRM(a,0);
	}
	int cnt = 0;
	if (!T.rm)
	{
		T.del(0,cnt);
	}
    else
    {
        cnt = 1;
    }
	
	cout << cnt << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}