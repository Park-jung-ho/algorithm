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

	int N,M;
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	N = a+b+c+d;
	cin >> a >> b >> c >> d;
	M = a+b+c+d;
	cout << max(N,M);
	
	
}
