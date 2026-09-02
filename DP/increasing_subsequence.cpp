#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f first
#define s second
typedef pair <int, int> ii;

const int N = 2e5;
const int MX = 1e9;
const int MOD = 1e9 + 7;

int n, ans;
int a[N + 5], b[N + 5];

signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n + 1; ++i) b[i] = MX + 1;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        int k = lower_bound(b + 1, b + n + 1, a[i]) - b;
        ans = max(ans, k);
        b[k] = a[i];
    }

    cout << ans;
}
