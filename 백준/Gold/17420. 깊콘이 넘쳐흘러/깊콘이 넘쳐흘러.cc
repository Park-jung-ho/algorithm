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

int N;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
    vector<pair<int,int>> arr(N);
    long long cnt = 0;
    long long day = 0;
    long long md = 0;
    long long tmpmd = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].second;
    }
    sort(arr.begin(),arr.end(),cmp);
    for (int i = 0; i < N; i++)
    {
        // cout << arr[i].first << " " << arr[i].second << " | ";
        if (arr[i].second != day)
        {
            md = tmpmd;
            if (arr[i].second > md)
            {
                md = arr[i].second;
            }
            
            day = arr[i].second;
            if (arr[i].first < md)
            {
                int r = ceil((double)(md-arr[i].first)/30);
                cnt += r;
                tmpmd = arr[i].first + r*30;
            }
            else
            {
                tmpmd = arr[i].first;
            }
        }
        else
        {
            if (arr[i].second > md)
            {
                md = arr[i].second;
            }
            if (arr[i].first < md)
            {
                int r = ceil((double)(md-arr[i].first)/30);
                cnt += r;
                long long t = arr[i].first + r*30;
                if (t > tmpmd)
                {
                    tmpmd = t;
                }
            }
            else
            {
                if (arr[i].first > tmpmd)
                {
                    tmpmd = arr[i].first;
                }
            }
            
        }
        // cout << md << " " << tmpmd << " " << cnt << "\n";
        
    }
    cout << cnt;
}
