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
const int MX = 10000 * 10 + 5;
bool chk[MX];
int nxt[MX][10];

int c2i (char c){
    return c - '0';
}
 
bool insert(string& s){
    int cur = root;
    for (auto c : s){
        if (nxt[cur][c2i(c)] == -1)
        {
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
        if (chk[cur] == true){
            return false;
        }
    }
    chk[cur] = true;
    if (cur == unused - 1)
    {
        return true;
    }
    else{
        return false;
    }
    
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int T;
      
	cin >> T;
    while (T--)
    {
        int n;
        
        cin >> n;
        fill(chk,chk+MX,false);
        unused = 2;
        for (int i = 0; i < MX; i++)
        {
            fill(nxt[i], nxt[i] + 10, -1);
        }
        bool can = true;
        for (int i = 0; i < n; i++)
        {
            string a;
            cin >> a;
            if(!insert(a)){
                can = false;
            }
        }
        
        
        if (can)
        {
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
        
    }
}