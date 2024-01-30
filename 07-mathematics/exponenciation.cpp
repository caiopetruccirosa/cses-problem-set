#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

ll expo(ll a, ll b) {
    if (b == 0)
        return 1;
    ll c = expo(a, b/2);
    ll c2 = (c*c) % LIM;
    if (b % 2 == 0)
        return c2;
    return (a*c2) % LIM;
}

int main() {_
    ll n;
    cin >> n;

    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << expo(a, b) << '\n';
    }

    return 0;
}