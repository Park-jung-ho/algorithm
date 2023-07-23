#include <vector>
#include <deque>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int T, N;
vector<int> target = {202021,20202021,202002021,202012021,202022021,202032021,202042021,202052021,202062021,202072021,202082021,202092021};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--)
    {
        long long cnt = 0;
        cin >> N;
        vector<int> arr(N);
        map<int,int> m;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            arr[i] = a;
            map<int,int>::iterator it = m.find(a);
            if (it != m.end())
            {
                it->second++;
            }
            else
            {
                m.insert(pair<int,int>(a,1));
            }
            
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                int a = target[j] - arr[i];
                if (a < arr[i]) continue;
                map<int,int>::iterator it = m.find(a);
                if (it != m.end())
                {
                    cnt += it->second; 
                }
            }
        }
        cout << cnt << "\n";
    }
}
