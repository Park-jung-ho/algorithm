#include <bits/stdc++.h>

using namespace std;

int n;
long long kk = 0;
queue<int> q;

void Eat(vector<int>& food_times,long long c, long long t)
{
    for (int i = 0; i < c; i++)
    {
        if (q.size() == 0) break;

        int idx = q.front();
        q.pop();
        if (t - food_times[idx] >= 0)
        {
            kk += t - food_times[idx];
            food_times[idx] = 0;
        }
        else
        {
            food_times[idx] -= t;
            q.push(idx);
        }
    }
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    n = food_times.size();
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }
    
    while (1)
    {
        long long a = k / q.size();
        long long b = k % q.size();
        k = b;
        if (a > 0)
        {
            Eat(food_times,q.size(),a);
        }
        else
        {
            k -= b;
            Eat(food_times,b,1);
        }
        
        k += kk;
        kk = 0;
        if (q.size() == 0 || k == 0) break;
    }
    if (q.size() > 0) answer = q.front() + 1;
    else answer = -1; 
    
    return answer;
}