#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll n;
    cin >> n;

    ll sum = (n*(n+1))/2;

    if (sum % 2 == 0) {
        ll goal = sum/2;
        set<ll> s1, s2;
        for (int i = n; i >= 1; i--) {
            if (i > goal) {
                s2.insert(i);
            } else {
                goal -= i;
                s1.insert(i);
            }
        }

        if (goal == 0) {
            cout << "YES\n";
            cout << s1.size() << '\n';
            for (int e: s1) {
                cout << e << ' ';
            }
            cout << '\n' << s2.size() << '\n';
            for (int e: s2) {
                cout << e << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}