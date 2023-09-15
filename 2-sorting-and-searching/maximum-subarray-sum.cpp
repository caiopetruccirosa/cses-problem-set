#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long, long long>

using namespace std;

int main() {_
    int n;
    cin >> n;

    ll current = 0, best = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        current += a;
        if (best < current)
            best = current;
        if (current < 0)
            current = 0;
    }
    cout << best << '\n';

    return 0;
}