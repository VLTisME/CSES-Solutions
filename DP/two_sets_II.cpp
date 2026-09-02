#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f first
#define s second
typedef pair <int, int> ii;

const int N = 5e2;
const ll MOD = 1e9 + 7;

int n;
ll dp[N * N + 5];

ll bp(ll x, ll y){
    ll res = 1;
    while (y > 0){
        if (y & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if ((n * (n + 1) / 2) % 2 != 0){
        cout << 0;
        return 0;
    }

    dp[0] = 1;

    for (int i = 1; i <= n; ++i){
        for (int sum = n * (n + 1) / 2; sum >= 1; --sum){
            if (sum >= i) dp[sum] = (dp[sum] + dp[sum - i]) % MOD;
        }
    }
    cout << dp[n * (n + 1) / 4] * bp(2, MOD - 2) % MOD;
}
