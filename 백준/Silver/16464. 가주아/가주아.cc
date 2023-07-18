#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int cnt = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T; 
	cin >> T;
	while (T--)
	{
		int n; 
		cin >> n;
		if ((n & (n-1)) == 0){
			cout << "GoHanGang" << "\n";
		}
		else
		{
			cout << "Gazua" << "\n";
		}
		

	}
	

}