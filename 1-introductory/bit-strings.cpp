#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int main() {_
    ll n;
    cin >> n;

    ll val = 1;
    for (ll i = 0; i < n; i++) {
        val = (val * 2) % LIM;
    }
    cout << val << '\n';

    return 0;
}