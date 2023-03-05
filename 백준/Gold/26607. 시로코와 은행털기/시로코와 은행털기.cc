#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, K, x, t;
int arr[81];
vector<vector<int>> dp;
void print_dp(){
    for (int i = 1; i < K+1; i++){
        for (int j = 0; j < K*x+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> N >> K >> x;

    dp.resize(K+1,vector<int>(K * x + 1));
    int a, b;
    // 배열 입력 디피 깊이 1 일때 입력
    for (int i = 1; i < N+1; i++)
    {
        cin >> a >> b;
        arr[i] = a;
    }
    
    dp[1][arr[1]] = 1;
    for (int j = 2; j < N+1; j++)
    {
        // i명까지 
        for (int i = min(K,j); i > 1 ; i--)
        {
            
            for (int k = 0; k <  K * x + 1; k++)
            {
                if (dp[i-1][k] == 1){
                    
                    dp[i][k + arr[j]] = 1;
                    
                }
            }
        }
        // print_dp();
        
        dp[1][arr[j]] = 1;
    }   
    // print_dp();
    int cnt = 0;
    for (int i = 0; i <  K * x + 1; i++)
    {
        if (dp[K][i] == 1){
            
            cnt = max(cnt,i * (K * x - i));
            
        }
    }
    cout << cnt;

}