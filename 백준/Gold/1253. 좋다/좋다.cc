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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        bool find = false;
        for (int j = 0; j < n-1; j++)
        {
            int start = j+1;
            int end = n-1;
            while (start <= end)
            {
                int mid = (start+end)/2;
                // debug(arr[j],arr[mid],arr[i]);
                if (j != i && mid != i && arr[j] + arr[mid] == arr[i])
                {
                    // debug(arr[j],arr[mid],arr[i]);
                    find = true;
                    break;
                }
                if (arr[j] + arr[mid] > arr[i])
                {
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            if (find)
            {
                break;
            }
            start++;
        }
        if (find)
        {
            cnt++;
        }
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}