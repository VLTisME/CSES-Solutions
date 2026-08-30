#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 5e2;
 
int a, b;
int dp[SZ + 5][SZ + 5];
 
signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> a >> b;
 
    for (int i = 0; i <= SZ; ++i){
        for (int j = 0; j <= SZ; ++j){
            dp[i][j] = 1e9;
        }
    }
 
    for (int i = 0; i <= SZ; ++i){
        dp[i][i] = 0;
    }
 
    for (int i = 1; i <= SZ; ++i){
        for (int j = 1; j <= SZ; ++j){
            for (int k = 1; k <= SZ; ++k){
                // same width - i
                if (j + k <= SZ) dp[i][j + k] = min(dp[i][j + k], dp[i][j] + dp[i][k] + 1);
                // same height - j
                if (i + k <= SZ) dp[i + k][j] = min(dp[i + k][j], dp[i][j] + dp[k][j] + 1);
            }
        }
    }
 
    cout << dp[a][b];
}