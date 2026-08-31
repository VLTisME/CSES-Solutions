#include <bits/stdc++.h>

using namespace std;

const int N = 3e3;
typedef pair <int, int> ii;

int n;
char grid[N + 5][N + 5];
bool trace[N + 5][N + 5], visited[N + 5][N + 5];

signed main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> grid[i][j];
        }
    }

    int nxt_lim = min(grid[1][2] - 'A', grid[2][1] - 'A');
    queue <ii> q;
    q.push({1, 1});
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            trace[i][j] = 0;
        }
    }
    while(1){
        queue <ii> g;
        while (!q.empty()){
            ii cur = q.front();
            q.pop();
            if (cur.first + 1 <= n && grid[cur.first + 1][cur.second] - 'A' == nxt_lim && !visited[cur.first + 1][cur.second]){
                g.push({cur.first + 1, cur.second});
                trace[cur.first + 1][cur.second] = 1;
                visited[cur.first + 1][cur.second] = 1;
            }
            if (cur.second + 1 <= n && grid[cur.first][cur.second + 1] - 'A' == nxt_lim && !visited[cur.first][cur.second + 1]){
                g.push({cur.first, cur.second + 1});
                visited[cur.first][cur.second + 1] = 1;
            }
        }
        nxt_lim = 26;
        while (!g.empty()){
            ii cur = g.front();
            g.pop();
            q.push(cur);
            if (cur.first + 1 <= n) nxt_lim = min(nxt_lim, grid[cur.first + 1][cur.second] - 'A');
            if (cur.second + 1 <= n) nxt_lim = min(nxt_lim, grid[cur.first][cur.second + 1] - 'A');
        }
        if (nxt_lim == 26) break;
    }
    
    // for (int i = 1; i <= n; ++i){
    //     for (int j = 1; j <= n; ++j){
    //         cout << trace[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    string ans = "";
    ii cur = {n, n};
    while (1){
        ans += grid[cur.first][cur.second];
        if (cur.first == 1 && cur.second == 1) break;
        if (trace[cur.first][cur.second]) cur.first--;
        else cur.second--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}