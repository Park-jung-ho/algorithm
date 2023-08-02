#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
using namespace std;

int n;
bool v[61][61][61];
vector<vector<int>> dmg3 = {{9,3,1},
                            {9,1,3},
                            {3,9,1},
                            {3,1,9},
                            {1,9,3},
                            {1,3,9}};
vector<vector<int>> dmg2 = {{9,3},
                            {3,9}};
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
    vector<int> scv = {0,0,0};
	for (int i = 0; i < n; i++)
    {
        cin >> scv[i];
    }
    deque<pair<int,vector<int>>> queue;
    sort(scv.begin(),scv.end());
    queue.push_back(make_pair(0,scv));
    int res = 61;
    while (!queue.empty())
    {
        int cnt = queue.front().first;
        vector<int> scv = queue.front().second;
        queue.pop_front();
        vector<int> ns;

        if (scv[0] == 0 && scv[1] == 0 && scv[2] == 0){
            res = min(res,cnt);
            break;
        }

        
        if (scv[0] > 0 && scv[1] > 0 && scv[2] > 0)
        {
            for (int i = 0; i < 6; i++)
            {
                ns = {max(0,scv[0]-dmg3[i][0]),
                      max(0,scv[1]-dmg3[i][1]),
                      max(0,scv[2]-dmg3[i][2])};

                sort(ns.begin(),ns.end());

                if (!v[ns[0]][ns[1]][ns[2]])
                {
                    v[ns[0]][ns[1]][ns[2]] = true;
                    queue.push_back(make_pair(cnt+1,ns));
                }
            } 
        }
        else if (scv[0] == 0 && scv[1] > 0 && scv[2] > 0)
        {
            for (int i = 0; i < 2; i++)
            {
                ns = {0,
                      max(0,scv[1]-dmg2[i][0]),
                      max(0,scv[2]-dmg2[i][1])};

                sort(ns.begin(),ns.end());

                if (!v[ns[0]][ns[1]][ns[2]])
                {
                    v[ns[0]][ns[1]][ns[2]] = true;
                    queue.push_back(make_pair(cnt+1,ns));
                }
            } 
        }
        else{
            int a = scv[2] / 9;
            if (scv[2] % 9 == 0)
            {
                res = min(res,cnt+a);
            }
            else{
                res = min(res,cnt+a+1);
            }
        }
    }
    cout << res;
}