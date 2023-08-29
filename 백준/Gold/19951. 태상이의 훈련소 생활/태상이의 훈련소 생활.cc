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

int N, M;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	vector<int> arr(N);
	vector<int> add(N+1);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, k;
		cin >> a >> b >> k;
		add[a-1] += k;
		add[b] += -k;
	}
	arr[0] += add[0];
	cout << arr[0] << " ";
	for (int i = 1; i < N; i++)
	{
		add[i] += add[i-1];
		arr[i] += add[i];
		cout << arr[i] << " ";
	}
	
	
}
