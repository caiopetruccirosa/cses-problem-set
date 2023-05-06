#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll sum = 0;
    for (int i = 0; i < n-1; i++) {
        sum += max(v[i]-v[i+1], 0);
        if (v[i] > v[i+1]) {
            v[i+1] = v[i];
        }
    }
    
    cout << sum << '\n';

    return 0;
}