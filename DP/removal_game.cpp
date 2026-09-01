#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 5e3;

int n;
int a[N + 5];
ll dp[N + 5][N + 5], pre[N + 5];

signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    memset(dp, -0x3f3f3f, sizeof(dp));

    for (int i = 1; i <= n; ++i){
        dp[i][i] = a[i];
        if (i != n) dp[i][i + 1] = max(a[i], a[i + 1]);
    }

    for (int i = n - 2; i >= 1; --i){
        for (int j = i + 2; j <= n; ++j){
            dp[i][j] = max({dp[i][j], pre[j] - pre[i] - dp[i + 1][j] + a[i], pre[j - 1] - pre[i - 1] - dp[i][j - 1] + a[j]});
        }
    }
    cout << dp[1][n];
}