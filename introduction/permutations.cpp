#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
    } else if (n < 4) {
        cout << "NO SOLUTION";
    } else {
        for (int i = 2; i <= n; i += 2) {
            cout << i << ' ';
        }
        for (int i = 1; i <= n; i += 2) {
            cout << i;
            if (i <= n-2) {
                cout << ' ';
            }
        }
    }
    cout << '\n';

    return 0;
}