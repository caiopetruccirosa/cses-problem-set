#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define pic pair<int,char>

#define LIM 1000000007

using namespace std;

void topsort(vector<vector<int>> &T, vector<int> &ts, int root) {
    for (int u: T[root])
        topsort(T, ts, u);
    ts.push_back(root);
}

int main() {_
    int n;
    cin >> n;

    vector<int> ts, pi(n+1), su(n+1, 0);
    vector<vector<int>> T(n+1);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        T[p].push_back(i);
        pi[i] = p;
    }

    topsort(T, ts, 1);

    for (int u: ts)
        su[pi[u]] += su[u] + 1;

    for (int i = 1; i <= n; i++)
        cout << su[i] << ' ';
    cout << '\n';

    return 0;
}