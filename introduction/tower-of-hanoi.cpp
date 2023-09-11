#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void solve(int a, int r_from, int r_to, int r_mid) {
    if (a == 1) {
        cout << r_from << ' ' << r_to << '\n';
        return;
    }
    solve(a-1, r_from, r_mid, r_to);
    solve(1, r_from, r_to, r_mid);
    solve(a-1, r_mid, r_to, r_from);
}

int main() {_
    int n;
    cin >> n;
    cout << ((1 << n) - 1) << '\n';
    solve(n, 1, 3, 2);
    return 0;
}