#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    ll n, x;
    cin >> n >> x;

    vector<ll> children(n);
    for (int i = 0 ; i < n; i++)
        cin >> children[i];

    sort(children.begin(), children.end());
    
    int ans = 0, i = 0, j = n-1;
    while (j >= i) {
        if (children[j]+children[i] <= x) {
            i++;
        }
        j--;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}