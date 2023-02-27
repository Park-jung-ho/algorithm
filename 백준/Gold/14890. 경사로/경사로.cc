#include <vector>
#include <iostream>
using namespace std;

int N, L;
int res = 0;


vector<vector<int>> MAP;

//맵출력
void printmap(){
    cout << "---------" << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n"; 
    }
}

int move(int x, int y, int m){
    vector<int> line;
    line.resize(N);
    if (m == 0){
        for (int i = 0; i < N-1; i++){
            if (MAP[x+i][y] == MAP[x+i+1][y]){
                continue;
            }
            else
            {
                if (MAP[x+i][y] + 1 == MAP[x+i+1][y]){
                    int h = MAP[x+i][y];
                    for (int j = 0; j < L; j++)
                    {
                        if (x+i-j >= 0 && MAP[x+i-j][y] == h && line[x+i-j] == 0){
                            line[x+i-j] = 1;
                        }
                        else{
                            return 0;
                        }
                    }
                }
                else if (MAP[x+i][y] == 1 + MAP[x+i+1][y])
                {
                    int h = MAP[x+i+1][y];
                    for (int j = 0; j < L; j++)
                    {
                        if (x+i+1+j < N && MAP[x+i+1+j][y] == h && line[x+i+1+j] == 0){
                            line[x+i+1+j] = 1;
                        }
                        else{
                            return 0;
                        }
                    }
                }
                else{
                    return 0;
                }
            }
        }
        // cout << "---------" << "\n";
        // for (int j = 0; j < N; j++){
        //     cout << MAP[j][y] << " ";
        // }
        // cout << "\n";
    }
    else if (m == 1){
        for (int i = 0; i < N-1; i++){
            if (MAP[x][y+i] == MAP[x][y+i+1]){
                continue;
            }
            else
            {
                if (MAP[x][y+i] + 1 == MAP[x][y+i+1]){
                    int h = MAP[x][y+i];
                    for (int j = 0; j < L; j++)
                    {
                        if (MAP[x][y+i-j] == h && line[y+i-j] == 0){
                            line[y+i-j] = 1;
                        }
                        else{
                            return 0;
                        }
                    }
                }
                else if (MAP[x][y+i] == 1 + MAP[x][y+i+1]){
                    int h = MAP[x][y+i+1];
                    for (int j = 0; j < L; j++)
                    {
                        if (MAP[x][y+i+1+j] == h && line[y+i+1+j] == 0){
                            line[y+i+1+j] = 1;
                        }
                        else{
                            return 0;
                        }
                    }
                }
                else{
                    return 0;
                }
                  
            }
        }
        // cout << "---------" << "\n";
        // for (int j = 0; j < N; j++){
        //     cout << MAP[x][j] << " ";
        // }
        // cout << "\n";
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> L;

    MAP.resize(N+1,vector<int>(N+1));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int a;
            cin >> a;
            MAP[i][j] = a;

        }
    }
    for (int i = 0; i < N; i++){
        res += move(0,i,0);
    }
    for (int i = 0; i < N; i++){
        res += move(i,0,1);
    }
    cout << res;
}