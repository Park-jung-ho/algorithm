#include <vector>
#include <deque>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void printmap(vector<vector<int>> arr, int N, int M){
    cout << "===============\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N,vector<int>(M));
    deque<pair<pair<int,int>,int>> ice;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] > 0)
            {
                ice.push_back({{i,j},arr[i][j]});
            }
        }
    }
    int year = 0;
    // int t = 3;
    while (1)
    {
        year++;
        for (int i = 0; i < ice.size(); i++) // 녹는중 - ice에 값 따로 저장
        {
            for (int j = 0; j < 4; j++)
            {
                int nx = ice[i].first.first + dx[j];
                int ny = ice[i].first.second + dy[j];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                {
                    continue;
                }
                if (arr[nx][ny] == 0)
                {
                    ice[i].second--;
                }
            }
        }
        int sz = ice.size();
        for (int i = 0; i < sz; i++) // 따로 저장한 값 맵에 업데이트
        {
            int x = ice.front().first.first;
            int y = ice.front().first.second;
            int v = max(ice.front().second,0);
            ice.pop_front();
            
            arr[x][y] = v;
            if (v > 0)
            {
                ice.push_back({{x,y},v});
            }
        }
        if (ice.empty())
        {
            break;
        }
        
        int nsz = ice.size();
        // printmap(arr,N,M);
        if (sz == nsz)
        {
            continue;
        }
        deque<pair<int,int>> q;
        vector<vector<int>> visit(N,vector<int>(M));
        q.push_back({ice[0].first.first,ice[0].first.second});
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                {
                    continue;
                }
                if (visit[nx][ny] == 1)
                {
                    continue;
                }
                if (arr[nx][ny] > 0)
                {
                    visit[nx][ny] = 1;
                    q.push_back({nx,ny});
                }
            }
        }
        // printmap(visit,N,M);
        bool bp = false;
        for (int i = 0; i < nsz; i++)
        {
            if (visit[ice[i].first.first][ice[i].first.second] == 0)
            {
                bp = true;
                break;
            }
        }
        if (bp)
        {
            break;
        }
    }

    if (!ice.empty())
    {
        cout << year;
    }
    else{
        cout << 0;
    }
    
    
    
    
   

}
