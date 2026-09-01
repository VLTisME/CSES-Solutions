#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef pair <int, int> ii;

const int N = 2e5;

int n, ans, idx;
int L[N + 5], R[N + 5], seg[4 * N + 5], dp[N + 5];
ii a[N + 5];


void update(int lo, int hi, int qlo, int pos){
    if (lo > qlo || hi < qlo) return;
    if (lo == hi && lo == qlo){
        seg[pos] = dp[qlo];
        return;
    }
    int mid = (lo + hi) / 2;
    update(lo, mid, qlo, pos * 2);
    update(mid + 1, hi, qlo, pos * 2 + 1);

    seg[pos] = max(seg[pos * 2], seg[pos * 2 + 1]);
}

int get(int lo, int hi, int l, int r, int pos){
    if (lo > r || hi < l) return 0;
    if (lo >= l && hi <= r){
        return seg[pos];
    }

    int mid = (lo + hi) / 2;
    return max(
        get(lo, mid, l, r, pos * 2),
        get(mid + 1, hi, l , r, pos * 2 + 1)
    );
}


signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }

    stack <int> s;
    s.push(0);

    for (int i = 1; i <= n; ++i){
        while (!s.empty() && a[i].first > a[s.top()].first) s.pop();
        if (!s.empty()) L[i] = s.top();
        else L[i] = 0;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    s.push(n + 1);
    for (int i = n; i >= 1; --i){
        while (!s.empty() && a[i].first > a[s.top()].first) s.pop();
        if (!s.empty()) R[i] = s.top();
        else R[i] = n + 1;
        s.push(i);
    }

    sort(a + 1, a + n + 1);


    for (int i = 1; i <= n; ++i){
        ++idx;
        dp[a[i].second] = get(1, n, L[a[i].second] + 1, R[a[i].second] - 1, 1) + 1;
        update(1, n, a[i].second, 1);
        ans = max(ans, dp[a[i].second]);
    }

    cout << ans;
}
// 6
// 4 8 5 7 2 8