#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

void mark_room(vector<vector<bool>> &visited, int n, int m, int i, int j) {
    if (visited[i][j])
        return;
    
    visited[i][j] = true;

    if (i > 0)
        mark_room(visited, n, m, i-1, j);
    if (i < n-1)
        mark_room(visited, n, m, i+1, j);
    if (j > 0)
        mark_room(visited, n, m, i, j-1);
    if (j < m-1)
        mark_room(visited, n, m, i, j+1);

    return;
}

int main() {_
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            visited[i][j] = (c == '#');
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                rooms++;
                mark_room(visited, n, m, i, j);
            }
        }
    }
    cout << rooms << '\n';

    return 0;
}