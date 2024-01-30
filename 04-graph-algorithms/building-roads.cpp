#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>

#define LIM 1000000007

using namespace std;

void process_component(vector<vector<int>> &G, vector<bool> &visited, int v) {
    visited[v] = true;

    for (int u: G[v])
        if (!visited[u])
            process_component(G, visited, u);

    return;
}

int main() {_
    int n, m;
    cin >> n >> m;

    vector<bool> visited(n+1, false);
    vector<vector<int>> G(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int last_v = -1;
    vector<pii> roads;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            process_component(G, visited, i);
            if (last_v != -1)
                roads.push_back(pii(last_v, i));
            last_v = i;            
        }
    }

    cout << roads.size() << '\n';
    for (pii r: roads)
        cout << r.first << ' ' << r.second << '\n';

    return 0;
}