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

long long a,b,c;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b;
	c = 0;
	// long long idx = 0;
	// for (long long i = a; i < b+1; i++)
	// {
	// 	c = c^i;
	// 	cout << i <<" " << c << "\n";
	// }
	// c = 0;
	if (b-a+1 < 10)
	{
		for (long long i = a; i < b+1; i++)
		{
			c = c^i;
		}
	}
	else{
		long long n = (b-a+1)/4;
		n--;
		n *= 4;
		long long s;
		if (a%2==0)
		{
			c = 0;
			s = a+n;
		}
		else{
			c = a;
			s = a+n+1;
		}
		// cout << "----------" << "\n";
		for (long long i = s; i < b+1; i++)
		{
			c = c^i;
			// cout << i <<" " << c << "\n";
		}
	}
	cout << c;
	
}