#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define pic pair<int,char>

#define LIM 1000000007

using namespace std;

int get_idx(int i, int j, int n, int m) {
    return i*m + j;
}

string bfs(vector<vector<pic>> &G, int n, int m, int s, int t) {
    vector<pic> prev(n*m, pic(-1, '-'));
    vector<bool> visited(n*m, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (pic adj: G[v]) {
            if (!visited[adj.first]) {
                visited[adj.first] = true;
                prev[adj.first] = pic(v, adj.second);
                q.push(adj.first);
            }
        }
    }

    if (prev[t].first == -1)
        return "";

    string reversed = "", path = "";
    int current = t;
    while (current != s) {
        reversed += prev[current].second;
        current = prev[current].first;
    }
    for (int i = (int)reversed.length()-1; i >= 0; i--)
        path += reversed[i];
    return path;
}

int main() {_
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    int s, t;
    vector<vector<pic>> G(n*m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && grid[i-1][j] != '#')
                G[get_idx(i, j, n, m)].push_back(pic(get_idx(i-1, j, n, m),'U'));
            if (i < n-1 && grid[i+1][j] != '#')
                G[get_idx(i, j, n, m)].push_back(pic(get_idx(i+1, j, n, m),'D'));
            if (j > 0 && grid[i][j-1] != '#')
                G[get_idx(i, j, n, m)].push_back(pic(get_idx(i, j-1, n, m),'L'));
            if (j < m-1 && grid[i][j+1] != '#')
                G[get_idx(i, j, n, m)].push_back(pic(get_idx(i, j+1, n, m),'R'));

            if (grid[i][j] == 'A')
                s = get_idx(i, j, n, m);
            else if (grid[i][j] == 'B')
                t = get_idx(i, j, n, m);
        }
    }

    string path = bfs(G, n, m, s, t);
    if (path != "") {
        cout << "YES" << '\n';
        cout << path.size() << '\n';
        cout << path << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}