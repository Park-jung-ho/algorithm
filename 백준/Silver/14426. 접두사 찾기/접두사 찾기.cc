#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int root = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
bool chk[MX];
int nxt[MX][26];

int c2i (char c){
    return c - 'a';
}
 
void insert(string& s){
    int cur = root;
    for (auto c : s){
        if (nxt[cur][c2i(c)] == -1)
        {
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find(string& s){
    int cur = root;
    for (auto c : s){
        if (nxt[cur][c2i(c)] == -1){
            return false;
        }
        cur = nxt[cur][c2i(c)];
    }
    return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
    int cnt = 0;    
	cin >> n >> m;
	for (int i = 0; i < MX; i++)
    {
        fill(nxt[i], nxt[i] + 26, -1);
    }
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        string a;
        cin >> a;
        
        cnt += find(a);
    }
    
    cout << cnt;
    
    

	
}