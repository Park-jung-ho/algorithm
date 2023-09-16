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

int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = N-2; i >= 0; i--)
    {
        if (arr[i] >= arr[i+1])
        {
            cnt += arr[i] - arr[i+1] + 1;
            arr[i] = arr[i+1] - 1;
        }
    }
    cout << cnt;
    
}
