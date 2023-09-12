#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (((2*a - b) >= 0 && (2*a - b) % 3 == 0) && ((2*b - a) >= 0 && (2*b - a) % 3 == 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}