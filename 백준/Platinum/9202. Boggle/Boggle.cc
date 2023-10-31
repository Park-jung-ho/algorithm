#include <bits/stdc++.h>
#include <sstream>
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

const int MAX_NODE = 26;
vector<string> arr;
vector<string> board(4);
vector<vector<bool>> visited(4,vector<bool>(4));
bool book[300000];
int endnum = 0;
int dx[] = {-1,1,0,0,-1,1,-1,1};
int dy[] = {0,0,-1,1,-1,1,1,-1};

int point[] = {0,0,0,1,1,2,3,5,11};
int MAXPOINT, FINDS;
string LONGEST;

void visitclear(){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            visited[i][j] = false;
        }
    }
    
}
void printv(){
    cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (visited[i][j])
            {
                cout << board[i][j] << " ";
            }
            else{
                cout << visited[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
struct trie
{
    trie* node[MAX_NODE];
    int finish;
    
    trie()
    {
        finish = -1;
        for (int i = 0; i < MAX_NODE; i++)
        {
            node[i] = NULL;
        }
    }

    void Insert(int idx, string& a)
    {
        if (idx == a.size())
        {
            finish = endnum;
            endnum++;
        }
        else{
            if (node[a[idx]-'A'] == nullptr)
            {
                node[a[idx]-'A'] = new trie;        
            }
            node[a[idx]-'A']->Insert(idx+1,a);
        }
    }
};

void bt(int x, int y, trie* tr){
    if (tr->finish > -1 && !book[tr->finish])
    {
        // printv();
        // debug(arr[tr->finish]);
        book[tr->finish] = true;
        MAXPOINT += point[arr[tr->finish].size()];
        FINDS++;
        if (LONGEST.size() == arr[tr->finish].size() && arr[tr->finish] < LONGEST)
        {
            LONGEST = arr[tr->finish];
        }
        else if (LONGEST.size() < arr[tr->finish].size())
        {
            LONGEST = arr[tr->finish];
        }
        // debug(MAXPOINT,LONGEST,FINDS);
    }
    for (int i = 0; i < 8; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || visited[nx][ny])
        {
            continue;
        }
        if (tr->node[board[nx][ny]-'A'] != nullptr)
        {
            visited[nx][ny] = true;
            bt(nx,ny,tr->node[board[nx][ny]-'A']);
            visited[nx][ny] = false;
        }
    }
    
}

void solve()
{
    trie t;
    int w;
    cin >> w;

    arr.resize(w);
    for (int i = 0; i < w; i++)
    {
        cin >> arr[i];
        t.Insert(0,arr[i]);
    }

    int b;
    cin >> b;

    while (b--)
    {
        MAXPOINT = 0;
        FINDS = 0;
        LONGEST = "";
        for (int i = 0; i < w; i++)
        {
            book[i] = false;
        }
        for (int j = 0; j < 4; j++)
        {
            cin >> board[j];
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (t.node[board[i][j]-'A'] != nullptr){
                    // cout << "start = " << board[i][j] << "\n";
                    visitclear();
                    visited[i][j] = true;
                    bt(i,j,t.node[board[i][j]-'A']);
                }
            }
        }
        cout << MAXPOINT << " " << LONGEST << " " << FINDS << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}