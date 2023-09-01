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

long long N, M, K;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
    long long a, b;
	a = (double)(N*M)/K;
	b = ((double)N/M)*K;
	
	
	cout << max(a,b);
	
}
