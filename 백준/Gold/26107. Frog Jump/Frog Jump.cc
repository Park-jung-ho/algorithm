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
#include <unordered_map>
using namespace std;

int N, k;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> k;
    vector<pair<int,int>> arr(N);
    vector<pair<int,int>> leaves;
    vector<int> going(k);
    vector<int> join(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> going[i];
    }
    sort(arr.begin(),arr.end());
    leaves.push_back(arr[0]);
    for (int i = 1; i < N; i++)
    {
        // cout << arr[i].first << " " << arr[i].second << "\n";
        if (arr[i].first <= leaves[leaves.size()-1].second)
        {
            leaves[leaves.size()-1].second = max(leaves[leaves.size()-1].second,arr[i].second);
            join[i] = leaves.size()-1;
        }
        else
        {
            leaves.push_back(arr[i]);
            join[i] = leaves.size()-1;
        }
    }
    vector<long long> jump(leaves.size());
    for (int i = 1; i < jump.size(); i++)
    {
        jump[i] = jump[i-1] + leaves[i].first - leaves[i-1].second;
    }
    
    int start = 0;
    long long res = 0;
    for (int i = 0; i < k; i++)
    {
        int go = join[going[i]-1];
        // cout << start << " " << go << "\n";
        if (start == go)
        {
            continue;
        }
        else if (start < go)
        {
            res += jump[go] - jump[start];
            
        }
        else
        {
            res += jump[start] - jump[go];
        }
        start = go;
    }
    cout << res;
            
}
