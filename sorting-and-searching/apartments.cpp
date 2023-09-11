#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int main() {_
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> applicants(n), apartments(m);
    for (int i = 0 ; i < n; i++)
        cin >> applicants[i];
    for (int i = 0 ; i < m; i++)
        cin >> apartments[i];

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int ans = 0, i = 0, j = 0;
    while (i < n && j < m) {
        if (apartments[j] <= applicants[i]+k && apartments[j] >= applicants[i]-k) {
            ans++;
            i++;
            j++;
        } else if (apartments[j] > applicants[i]+k) {
            i++;
        } else if (apartments[j] < applicants[i]-k) {
            j++;
        }
    }

    cout << ans << '\n';

    return 0;
}