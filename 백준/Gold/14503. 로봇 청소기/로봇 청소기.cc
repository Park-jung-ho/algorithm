#include <vector>
#include <iostream>
using namespace std;


int N, M, cnt;
//0123북동남서
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

//로보트 정보
struct ROBO
{
    int r, c, m;
};

ROBO robo;
//맵 선언
vector<vector<int>> MAP;
//맵출력
void printmap(){
    cout << "---------" << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n"; 
    }
}
//로봇 동작
void move(){
    int x, y, m;

    while (true){
        x = robo.r;
        y = robo.c;
        m = robo.m;

        // 현재 칸 청소
        if (MAP[x][y] == 0){
            cnt++;
            MAP[x][y] = -1;
        }
        // printmap();
        //청소되지 않은 칸 확인
        int go = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx, ny;
            nx = dx[i] + x;
            ny = dy[i] + y;
            if (nx >=0 && nx < N && ny >= 0 && ny < M && MAP[nx][ny] == 0){
                go = 1;
                break;     
            }
        }
        // 청소되지 않은 칸이 없을 경우
        if (go == 0){
            int nx, ny, nm;
            nm = m-2;
            if(nm < 0){
                nm = 4+nm;
            }
            nx = dx[nm] + x;
            ny = dy[nm] + y;
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || MAP[nx][ny] == 1){
                break;
            }
            else{
                robo.r = nx;
                robo.c = ny;
            }
        }
        else{// 청소되지 않은 칸이 있을 경우
            for (int i = 1; i < 5; i++)
            {
                int nx, ny, nm;
                nm = m-i;
                if(nm < 0)
                    nm = 4+nm;
                nx = dx[nm] + x;
                ny = dy[nm] + y;
                if (nx >=0 && nx < N && ny >= 0 && ny < M && MAP[nx][ny] == 0){
                    robo.r = nx;
                    robo.c = ny;
                    robo.m = nm;
                    break;
                }
            }
        }
    }
    

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // 입력받기
    cin >> N >> M;
    cin >> robo.r >> robo.c >> robo.m;

    MAP.resize(N+1,vector<int>(M+1));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            int a;
            cin >> a;
            MAP[i][j] = a;
        }
    }
    
    move();
    cout << cnt;
    

}