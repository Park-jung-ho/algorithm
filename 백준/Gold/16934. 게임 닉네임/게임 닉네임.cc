#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <cmath>
using namespace std;

const int root = 1;
int unused = 2;
const int MX = 100000 * 10 + 5;
int nxt[MX][26];
int chks[MX] = {0, };

int c2i (char c){
	return c - 'a';
}

string insert(string& s){
	int cur = root;
	string res;
	bool adds = true;
	for (auto c : s){
		if (adds)
		{
			res += c;
		}
        if (nxt[cur][c2i(c)] == -1)
        {
            nxt[cur][c2i(c)] = unused++;
			adds = false;
        }
        cur = nxt[cur][c2i(c)];
    }
    chks[cur]++;
	if (chks[cur] > 1)
	{
		res += to_string(chks[cur]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < MX; i++)
	{
		fill(nxt[i],nxt[i] + 26, -1);
	}
	
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		
		cout << insert(a) << "\n";
	}
	
	
	
}
