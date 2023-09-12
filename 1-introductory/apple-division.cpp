#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long

#define LIM 1000000007

using namespace std;

ull solve(vector<ll> &p, int i, int n, ll csum, ll tsum) {
    if (i == n)
        return abs(tsum - 2*csum);

    return min(solve(p, i+1, n, csum+p[i], tsum), solve(p, i+1, n, csum, tsum));
}

int main() {_
    int n;
    cin >> n;

    ll sum = 0;
    vector<ll> p(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }

    cout << solve(p, 0, n, 0, sum) << '\n';

    return 0;
}
