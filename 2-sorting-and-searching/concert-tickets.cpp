#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n, m;
    cin >> n >> m;

    multiset<ll> tickets;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        tickets.insert(t);
    }

    for (int i = 0; i < m; i++) {
        ll p;
        cin >> p;
        auto ti = tickets.upper_bound(p);
        if (ti == tickets.begin()) {
            cout << -1;
        } else {
            cout << *(--ti);
            tickets.erase(ti);
        }
        cout << '\n';
    }

    return 0;
}