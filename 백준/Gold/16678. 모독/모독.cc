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

vector<int> arr;
int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	arr.resize(N);
	long long s = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int c = 1;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > c)
		{
			s += arr[i] - c;
			arr[i] -= c;
			c++;
		}
		else{
			c = arr[i] + 1;
		}
	}
	cout << s;
	

	
}
