#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int main() {_
    ll n, x;
    cin >> n >> x;

    vector<ll> coins(n), amount(x+1, 0);
    for (int c = 0; c < n; c++) {
        cin >> coins[c];
    }

    amount[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int c = 0; c < n; c++) {
            if (coins[c] <= i) {
                amount[i] = (amount[i] + amount[i-coins[c]]) % LIM;
            }
        }
    }
    cout << amount[x] << '\n';

    return 0;
}