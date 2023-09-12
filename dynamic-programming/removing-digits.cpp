#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int main() {_
    ll n;
    cin >> n;

    vector<ll> dp(n+1, -1);
    for (ll i = 0; i <= 9; i++)
        dp[i] = 1;

    for (ll i = 10; i <= n; i++) {
        ll number = i, digit;
        while (number > 0) {
            digit = number % 10;
            number /= 10;
            if (dp[i-digit] != -1) {
                if (dp[i] != -1) {
                    dp[i] = min(dp[i-digit]+1, dp[i]);
                } else {
                    dp[i] = dp[i-digit]+1;
                }
            }

        }
    }

    cout << dp[n] << '\n';

    return 0;
}