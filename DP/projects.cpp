#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f first
#define s second
typedef pair <int, int> ii;

const int N = 2e5;
const int MX = 4e5;

int n;
int p[N + 5];
ll dp[2 * N + 5];
ii a[N + 5];
vector <ii> st[2 * N + 5];
map <int, int> m;
ll ans;

ll get(int x){
    ll res = 0;
    for (x; x >= 1; x -= x & -x){
        res = max(res, dp[x]);
    }
    return res;
}

void update(int x, ll val){
    for (x; x <= MX; x += x & -x) dp[x] = max(dp[x], val);
}

signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector <int> norm;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].f >> a[i].s >> p[i];
        norm.push_back(a[i].f);
        norm.push_back(a[i].s);
    }
    sort(norm.begin(), norm.end());
    int cnt = 1;
    m[norm[0]] = cnt++;
    for (int i = 1; i < norm.size(); ++i){
        if (norm[i] != norm[i - 1]){
            m[norm[i]] = cnt++;
        }
    }

    for (int i = 1; i <= n; ++i){
        a[i].f = m[a[i].f];
        a[i].s = m[a[i].s];
        st[a[i].s].push_back({a[i].f, p[i]});
    }

    for (int i = 1; i <= 2 * N; ++i){
        dp[i] = dp[i - 1];
        for (auto [j, aw]: st[i]){
            dp[i] = max(dp[i], get(j - 1) + aw);
        }
        update(i, dp[i]);
    }

    cout << dp[2 * N];
}