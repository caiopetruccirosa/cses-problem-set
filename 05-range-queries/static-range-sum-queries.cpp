#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int main() {_
    int n, q;
    cin >> n >> q;

    vector<ll> prefix_sum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        prefix_sum[i] = prefix_sum[i-1] + x;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix_sum[b]-prefix_sum[a-1] << '\n';
    }

    return 0;
}