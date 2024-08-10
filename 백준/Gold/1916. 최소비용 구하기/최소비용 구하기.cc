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


typedef pair<int,int> pii;
const int INF = 1e9;

vector<pii> v[1010];
int visited[1010];
int dist[1010];
int n , m;
int s, e;

void solve(){
    fill(&dist[0],&dist[n+1],INF);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push({0,s});
    
    while(pq.size() > 0)
    {
        pii frt = pq.top();
        pq.pop();

        int currentCost = frt.first;
        int currentNode = frt.second;
        if(currentNode == e)
        {
            return;
        }

        if(visited[currentNode])
        {
            continue;
        }
        visited[currentNode] = true;

        for(int i = 0 ; i < v[currentNode].size(); i++)
        {
            int targetCost = v[currentNode][i].first;
            int targetNode = v[currentNode][i].second;

            
            int nextCost = currentCost + targetCost;

            if(dist[targetNode] < nextCost)
            {
                continue;
            }
            dist[targetNode] = nextCost;
            pii route = {nextCost, targetNode};
            pq.push(route);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int x, y, z;

    for(int i =0 ; i< m; i++){
        cin >> x >> y >> z;

        v[x].push_back(make_pair(z,y));    
    }    

    cin >> s >> e;

    solve();
    cout << dist[e] << '\n';
    
    
}