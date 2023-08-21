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

vector<int> p;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	p.resize(N);
	int a = 0;
	int b = 0;
	
	for (int i = 0; i < N; i++)
	{
		cin >> p[i];
		if (i%2==0)
		{
			a += p[i];
		}
		else{
			b += p[i];
		}
	}
	int res = a;
	int na = 0;
	int nb = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (i%2==0)
		{
			res = max(res,na+b-nb);
			na += p[i];
		}
		else{
			res = max(res,na+b-nb-p[N-1]);
			nb += p[i];
		}
	}
	cout << res;
	
	
	
	
}
