#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

deque<int> a;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        a.push_back(n);
    }
    sort(a.begin(),a.end());
    int cnt = 0;
    int l,r;
    while (true){
        if (a.front() > 0){
            break;
        }
        l = a.front();
        a.pop_front();
        if (a.size() == 0 || a.front() > 0){
            cnt += l;
            break;
        }
        r = a.front();
        a.pop_front();
        if (r !=0){
            cnt += l*r;
        }
        if (a.size() == 0){
            break;
        }
    }
    while (true){
        if (a.back() <= 0){
            break;
        }
        l = a.back();
        a.pop_back();
        if (a.size() == 0 || a.back() <= 0){
            cnt += l;
            break;
        }
        r = a.back();
        a.pop_back();
        if (r == 1){
            cnt += l+r;
        }
        else{
            cnt += l*r;
        }
        if (a.size() == 0){
            break;
        }
    }
    cout << cnt;
    
}