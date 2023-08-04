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
int n,m,x,y;
vector<int> arr;
vector<int> r;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	m = -1;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cin >> n;
			if (n > m)
			{
				m = n;
				x = i;
				y = j;
			}
		}	
	}
	cout << m << "\n" << x << " " << y;
	
	
	

}