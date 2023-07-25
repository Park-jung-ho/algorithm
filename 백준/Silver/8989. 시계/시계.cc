#include <vector>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct T
{
	float d;
	int t;
	pair<int,int> times;
	string time;

};
bool compare(const T& t1, const T& t2){
	if (t1.d == t2.d)	
	{
		return t1.t < t2.t;
	}
	else{
		return t1.d < t2.d;
	}
	
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N; 
	cin >> N;
	for (int i = 0; i<N; i++)
	{
		vector<T> arr(5);
		for (int j = 0; j < 5; j++)
		{
			string a;
			cin >> a;
			arr[j].time = a;
			arr[j].times = {stoi(a.substr(0,2)),stoi(a.substr(3,2))};
			arr[j].t = arr[j].times.first*60 + arr[j].times.second;
			
			if (arr[j].times.first >= 12)
			{
				arr[j].times.first -= 12;
			}
			
			float tf = arr[j].times.first*30 + arr[j].times.second * 0.5;
			float ts = arr[j].times.second * 6;
			if (tf >= ts)
			{

				arr[j].d = min(tf - ts, 360 - (tf-ts));
			}
			else{
				arr[j].d = min(ts - tf, 360 - (ts - tf));
			}
		}
		sort(arr.begin(),arr.end(),compare);
		// for (int j = 0; j < 5; j++)
		// {
		// 	cout << arr[j].time << " " << arr[j].d << "\n";
		// }

		cout << arr[2].time << "\n";
	}
}