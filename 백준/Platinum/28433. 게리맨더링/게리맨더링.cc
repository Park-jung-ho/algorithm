#include <vector>
#include <deque>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int T;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<long long> arr;
        long long a;
        cin >> a;
        arr.push_back(a);
        long long sumarr = a;
        for (int i = 1; i < N; i++)
        {
            int last = arr.size()-1;
            cin >> a;
            sumarr += a;
            if (arr[last] > 0 && a > 0)
            {
                arr.push_back(a);
            }
            else if (arr[last] < 0 && a < 0)
            {
                arr[last] += a;
            }
            else if (arr[last] + a > 0)
            {
                arr[last] += a;
            }
            else if (a != 0)
            {
                arr.push_back(a);
            }
        }
        int p = 0;
        int m = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            // cout << arr[i] << ' ';
            if (arr[i] > 0)
            {
                p++;
            }
            else if (arr[i] < 0)
            {
                m++;
            }
        }
        // cout << '\n';
        if (sumarr > 0 || p - m > 0)
        {
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";

        }
        
        
    }
    
   

}
