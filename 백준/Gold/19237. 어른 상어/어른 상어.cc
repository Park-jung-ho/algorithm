#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

struct Shark
{
    // (r,c) | 방향 | 우선순위
    int r, c, m;
    bool out = false;
    vector<int> go[5];
};

struct smell
{
    // 위치/남은시간/상어번호
    int s, t, n;
};

smell MAP[21][21];
Shark Sharks[405];

int n, m, k;
int dx[5] = {0,-1, 1, 0, 0};
int dy[5] = {0,0, 0, -1, 1};


// 맵 출력
void print_arr(int t){
    cout << "=====" << t << "=======" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << MAP[i][j].s << ' ';
        cout << '\n';
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << MAP[i][j].t << ' ';
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    // 맵 입력받기
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            MAP[i][j].s = a;
            // 상어일때 정보 저장
            if (MAP[i][j].s != 0){
                Sharks[a].r = i;
                Sharks[a].c = j;
                MAP[i][j].t = k;
                MAP[i][j].n = a;
            }
            else{
                MAP[i][j].t = 0;
                MAP[i][j].n = 0;
            }
        }
    }
    
    //상어 처음 보는 방향
    for (int i = 1; i < m+1; i++){
        int a;
        cin >> a;
        Sharks[i].m = a;
    }
    //상어 이동 우선순위
    
    for (int i = 1; i < m+1; i++){
        for (int j = 1; j < 5; j++){
            Sharks[i].go[j].push_back(0);
            for (int k = 1; k < 5; k++){
                int a;
                cin >> a;
                Sharks[i].go[j].push_back(a);
                }
        }
    }

    int time = 0;
    int can = 0;

    while (time < 1000){
        time++;
        
        // 상어이동
        for (int i = 1; i < m+1; i++)
        {
            if (Sharks[i].out == true)
                continue;
            int x, y, g, cg; 
            int cx = -1;
            int cy = -1;
            
            x = Sharks[i].r;
            y = Sharks[i].c;
            g = Sharks[i].m;
            // 우선순위에 맞게 빈자리 찾기
            for (int k = 1; k < 5; k++)
            {
                int nx, ny;
                nx = dx[Sharks[i].go[g][k]] + x;
                ny = dy[Sharks[i].go[g][k]] + y;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n){
                    if (MAP[nx][ny].n == 0){
                        cx = nx;
                        cy = ny;
                        cg = Sharks[i].go[g][k];
                        break;
                    }  
                }
            }
            if (cx == -1 && cy == -1){
                // 빈자리 없다면 우선순위에 맞게 다음자리 찾기
                for (int k = 1; k < 5; k++)
                {
                    int nx, ny;
                    nx = dx[Sharks[i].go[g][k]] + x;
                    ny = dy[Sharks[i].go[g][k]] + y;

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n){
                        if (MAP[nx][ny].n == i){
                            cx = nx;
                            cy = ny;
                            cg = Sharks[i].go[g][k];
                            break;
                        }  
                    }
                }
            }
            // 이동한 위치 상어정보에 업데이트
            MAP[x][y].s = 0;
            Sharks[i].r = cx;
            Sharks[i].c = cy;
            Sharks[i].m = cg;
        }
        // 기존 냄새 시간 줄이기
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (MAP[i][j].t > 0){
                    MAP[i][j].t--;
                    if (MAP[i][j].t == 0){
                        MAP[i][j].n = 0;
                    }
                }
            }
        }
        // 냄새 뿌리기
        for (int i = 1; i < m+1; i++){
            if (Sharks[i].out == true)
                continue;
            int x, y;
            x = Sharks[i].r;
            y = Sharks[i].c;
            // 빈자리 or 자기번호
            if (MAP[x][y].n == 0 || MAP[x][y].n == i) {
                MAP[x][y].n = i;
                MAP[x][y].s = i;
                MAP[x][y].t = k;
            }
            else if (MAP[x][y].n > i)
            {// 더 큰번호랑 만날 때
                if (MAP[x][y].s == MAP[x][y].n)
                    Sharks[MAP[x][y].n].out = true;
                MAP[x][y].n = i;
                MAP[x][y].s = i;
                MAP[x][y].t = k;
            }
            else
            {
                Sharks[i].out = true;
            }
              
        }

        // print_arr(time);

        int one = 0;

        for (int i = 2; i < m+1; i++){
            if (Sharks[i].out == false){
                one = 1;
                break;
            }
        }
        
        if (one == 0){
            cout << time;
            can = 1;
            break;
        }
    }
    if (time >= 1000 && can == 0)
        cout << -1;
}
// 5 6 7
// 0 0 0 0 3
// 0 2 0 0 0
// 1 0 0 0 4
// 0 6 0 0 0
// 0 0 5 0 0
// 4 4 3 1 4 2
// 2 3 1 4
// 4 1 2 3
// 3 4 2 1
// 4 3 1 2
// 2 4 3 1
// 2 1 3 4
// 3 4 1 2
// 4 1 2 3
// 4 3 2 1
// 1 4 3 2
// 1 3 2 4
// 3 2 1 4
// 3 4 1 2
// 3 2 4 1
// 1 4 2 3
// 1 4 2 3
// 3 4 1 2
// 3 2 4 1
// 1 4 2 3
// 1 4 2 3
// 3 4 1 2
// 4 1 2 3
// 4 3 2 1
// 1 4 3 2