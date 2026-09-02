#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f first
#define s second
typedef pair <int, int> ii;

const int N = 1e2;
const int MX = 1e5;
const int MOD = 1e9 + 7;

int n, ans;
int a[N + 5];
bool dp[MX + 5];

signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int sum = MX; sum >= a[i]; --sum){
            dp[sum] = max(dp[sum], dp[sum - a[i]]);
        }
    }
    for (int i = 1; i <= MX; ++i) ans += dp[i];
    cout << ans << '\n';
    for (int i = 1; i <= MX; ++i){
        if (dp[i]){
            cout << i << " ";
        }
    }
}
