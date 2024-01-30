#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007
#define INF (1ll << 60)

using namespace std;

vector<ll> dijkstra(vector<vector<pair<ll,int>>> &G, int n, int s) {
    vector<ll> distances(n+1, INF);
    vector<bool> visited(n+1, false);
    priority_queue<pair<ll,int>> q;

    q.push(make_pair(0, s));
    distances[s] = 0;

    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();
        
        if (visited[v])
            continue;

        visited[v] = true;
        for (auto [w, u]: G[v]) {
            if (distances[u] > distances[v] + w) {
                distances[u] = distances[v] + w;
                q.push(make_pair(-distances[u], u));
            }
        }
    }

    return distances;
}

int main() {_
    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll,int>>> G(n+1);
    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(c, b));
    }

    vector<ll> distances = dijkstra(G, n, 1);
    for (int i = 1; i <= n; i++) {
        cout << distances[i] << ' ';
    }
    cout << '\n';
}