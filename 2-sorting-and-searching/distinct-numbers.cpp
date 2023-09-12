#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int main() {_
    int n;
    cin >> n;

    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        s.insert(a);
    }

    cout << s.size() << '\n';

    return 0;
}