#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll n;
    cin >> n;

    ll sum = 0;
    for (int i = 0; i < n-1; i++) {
        ll a;
        cin >> a;
        sum += a;
    }

    ll missing = (((n+1)*n)/2) - sum;
    cout << missing << '\n';

    return 0;
}