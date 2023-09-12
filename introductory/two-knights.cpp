#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll n;
    cin >> n;

    cout << 0 << '\n';
    for (ll k = 2; k <= n; k++) {
        cout << (((k*k)*((k*k)-1))/2) - (4*(k-1)*(k-2)) << '\n';
    }

    return 0;
}