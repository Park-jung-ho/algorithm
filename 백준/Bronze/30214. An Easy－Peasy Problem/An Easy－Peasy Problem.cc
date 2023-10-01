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
    if (N < (double)M/2)
    {
        cout << "H";
    }
    else
    {
        cout << "E";
    }
    
}