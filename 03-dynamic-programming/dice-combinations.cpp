#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int main() {_
    int n;
    cin >> n;

    vector<ll> comb(n+1, 0);
    comb[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int d = 1; d <= 6; d++)
            if (d <= i)
                comb[i] = (comb[i] + comb[i-d]) % LIM;

    cout << comb[n] << '\n';

    return 0;
}