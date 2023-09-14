#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int n;
    cin >> n;

    vector<ll> be(n), en(n);
    for (int i = 0; i < n; i++)
        cin >> be[i] >> en[i];

    sort(be.begin(), be.end());
    sort(en.begin(), en.end());

    int i = 0, j = 0, k = 0, maxk = 0;
    while (i < n && j < n) {
        if (be[i] <= en[j]) {
            k++;
            i++;
            maxk = max(maxk, k);
        } else {
            k--;
            j++;
        }
    }

    cout << maxk << '\n';

    return 0;
}