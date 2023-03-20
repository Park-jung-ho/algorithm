#include <vector>
#include <iostream>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	arr.resize(N+1);
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		for (int i = a; i < b+1; i++)
		{
			arr[i] = c;
		}
	}
	for (int i = 1; i < N+1; i++)
	{
		cout << arr[i] << " ";
	}
	
	
		
}