#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef pair <int, int> ii;

const int N = 1e3;

int n, m;
int a[N + 5], b[N + 5], dp[N + 5][N + 5];
ii trace[N + 5][N + 5];

signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i] == b[j]){
                if (dp[i - 1][j - 1] + 1 > dp[i][j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    trace[i][j] = {i - 1, j - 1};
                }
            }
            else{
                if (dp[i - 1][j] >= dp[i][j]){
                    dp[i][j] = dp[i - 1][j];
                    trace[i][j] = {i - 1, j};
                }
                if (dp[i][j - 1] >= dp[i][j]){
                    dp[i][j] = dp[i][j - 1];
                    trace[i][j] = {i, j - 1};
                }
            }
        }
    }

    cout << dp[n][m] << "\n";
    ii t = {n, m};
    vector <int> seq;

    while (1){
        if (a[t.first] == b[t.second]){
            seq.push_back({a[t.first]});
        }
        t = trace[t.first][t.second];
        if (t.first == t.second && t.first == 0) break;
    }
    reverse(seq.begin(), seq.end());
    for (auto x: seq) cout << x << " ";
}
