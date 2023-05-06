#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n;
    cin >> n;

    if (n % 2 == 0 || n < 5) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    bool end = true;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        if (end) {
            v[n-1-i] = i+1;
        } else {
            v[i] = i+1;
        }
        end = !end;
    }

    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i < n-1) {
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}