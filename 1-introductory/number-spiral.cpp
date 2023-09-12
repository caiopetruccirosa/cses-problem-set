#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int t;
    cin >> t;

    while (t--) {
        ll y, x;
        cin >> y >> x;

        if (x == y) {
            cout << (x*x) - x + 1;
        } else {
            ll m = max(x, y)-1;
            if (m % 2 == 0) {
                if (x > y) {
                    cout << ((m+1)*(m+1)) - y + 1;
                } else {
                    cout << (m*m) + x;
                }
            } else {
                if (x > y) {
                    cout << (m*m) + y;
                } else {
                    cout << ((m+1)*(m+1)) - x + 1;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}