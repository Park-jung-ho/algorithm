#include <vector>
#include <iostream>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

pair <int,int> pi;

int N, M;
int res = 0;

vector<vector<int>> MAP;
vector<pair<int,int>> H;
vector<pair<int,int>> CK;
vector<pair<int,int>> B;

void back(int idx){
    if (B.size() == M){
        int cnt = 0;
        for (int i = 0; i < H.size(); i++)
        {
            int a = 0;
            for (int j = 0; j < B.size(); j++)
            {
                if (a == 0){
                    a = abs(H[i].first-B[j].first) + abs(H[i].second -B[j].second);
                }
                else{
                    a = min(a,abs(H[i].first-B[j].first) + abs(H[i].second -B[j].second));
                }
            }
            cnt += a;
            if (res != 0 && cnt > res){
                return;
            }
        }
        if (res == 0){
            res = cnt;
        }
        else{
            res = min(res,cnt);
        }
    }

    for (int i = idx; i < CK.size(); i++)
    {
        B.emplace_back(CK[i].first,CK[i].second);
        back(i+1);
        B.pop_back();
    }
    
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    MAP.resize(N+1,vector<int>(N+1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1){
                H.emplace_back(i,j);
            }
            else if (MAP[i][j] == 2){
                CK.emplace_back(i,j);
            }
        }
    }
    back(0);
    cout << res;
}