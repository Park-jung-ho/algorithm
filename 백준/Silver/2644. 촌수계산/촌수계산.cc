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


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	
	int n, a, b, m;
	cin >> n >> a >> b >> m;
	vector<int> arr(101,-1);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		arr[y] = x;
	}
	vector<int> ap;
	vector<int> bp;
	while (1)
	{
		ap.push_back(a);
		a = arr[a];
		if (a == -1)
		{
			break;
		}
	}
	while (1)
	{
		bp.push_back(b);
		b = arr[b];
		if (b == -1)
		{
			break;
		}
	}
	// reverse(ap.begin(),ap.end());
	// reverse(bp.begin(),bp.end());
	// for (int i = 0; i < ap.size(); i++)
	// {
	// 	cout << ap[i] << " ";
	// }
	// cout << "\n";
	// for (int i = 0; i < bp.size(); i++)
	// {
	// 	cout << bp[i] << " ";
	// }
	// cout << "\n";
	
	bool stop = false;
	int res = -1;
	for (int i = 0; i < ap.size(); i++)
	{
		for (int j = 0; j < bp.size(); j++)
		{
			if (ap[i] == bp[j])
			{
				res = i+j;
				stop = true;
				break;
			}
			
		}
		if (stop)
		{
			break;
		}
	}
	cout << res << "\n";
	
	
	
		
	
}
