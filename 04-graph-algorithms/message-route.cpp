#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>

#define LIM 1000000007

using namespace std;

vector<int> bfs_path(vector<vector<int>> &G, int s, int t, int n) {
    vector<bool> visited(n+1, false);
    vector<int> prev(n+1);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    bool ended = false;
    while (!q.empty() && !ended) {
        int v = q.front();
        q.pop();
        for (int u: G[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                prev[u] = v;
                if (u == t) {
                    ended = true;
                }
            }
        }
    }

    if (!ended)
        return vector<int>();

    deque<int> path;
    int current = t;
    while (current != s) {
        path.push_front(current);
        current = prev[current];
    }
    path.push_front(s);
    return vector<int>(path.begin(), path.end());
}

int main() {_
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> path = bfs_path(G, 1, n, n);
    if (path.size() == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << path.size() << '\n';
        for (int v: path) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    return 0;
}