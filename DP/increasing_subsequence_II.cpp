#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5;
const int MX = 1e9;
const int MOD = 1e9 + 7;

int n, ans;
int a[N + 5];
vector <int> no;
map <int, int> m;
ll dp[N + 5];

void update(int x, int val){
    for (x; x <= N; x += x & -x){
        dp[x] = (dp[x] + val) % MOD;
    }
}

ll get(int x){
    ll sum = 0;
    for (x; x >= 1; x -= x & -x) sum = (sum + dp[x]) % MOD;
    return sum;
}

signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        no.push_back(a[i]);
    }

    sort(no.begin(), no.end());
    int cnt = 0;
    m[no[0]] = ++cnt;
    for (int i = 1; i < no.size(); ++i){
        if (no[i] != no[i - 1]){
            m[no[i]] = ++cnt;
        }
    }
    for (int i = 1; i <= n; ++i) a[i] = m[a[i]];

    for (int i = 1; i <= n; ++i){
        int num = (get(a[i] - 1) + 1) % MOD;
        ans = (ans + num) % MOD;
        // cout << a[i] << " and " << dp[a[i]] << " ?\n";
        update(a[i], num);
    }
    
    cout << ans;
    
}