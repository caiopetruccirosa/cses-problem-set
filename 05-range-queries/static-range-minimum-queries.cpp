#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int msb(int x) {
    int b = -1;
    while (x != 0) {
        x = x >> 1;
        b++;
    }
    return b;
}

int main() {_
    int n, q;
    cin >> n >> q;

    int b = msb(n);

    vector<vector<ll>> min_dp(n+1, vector<ll>(b+1));
    for (int i = 1; i <= n; i++)
        cin >> min_dp[i][0];

    for (int i = 1; i <= b; i++) {
        for (int j = 1; j+(1<<i)-1 <= n; j++) {
            min_dp[j][i] = min(min_dp[j][i-1], min_dp[j+(1<<(i-1))][i-1]);
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int c = msb(b-a+1);
        cout << min(min_dp[a][c], min_dp[b-(1<<c)+1][c]) << '\n';
    }

    return 0;
}