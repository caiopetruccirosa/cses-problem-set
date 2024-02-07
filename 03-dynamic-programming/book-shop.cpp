#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>

const ll MOD = 1e9+7;

using namespace std;

int main() {_
    int n, x; cin >> n >> x;

    vector<int> h(n+1), s(n+1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    // simple knapsack
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for (int i = 1; i <= n; i++)
        for (int w = 1; w <= x; w++)
            if (h[i] <= w)
                dp[i][w] = max(dp[i-1][w-h[i]]+s[i], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];

    cout << dp[n][x] << '\n';

    return 0;
}