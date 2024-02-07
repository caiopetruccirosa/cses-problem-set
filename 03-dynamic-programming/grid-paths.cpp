#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>

const ll MOD = 1e9+7;

using namespace std;

int main() {_
    int n; cin >> n;

    vector<vector<char>> grid(n+1, vector<char>(n+1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];
    
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (grid[i][j] != '*')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;

    cout << dp[n][n] << '\n';

    return 0;
}