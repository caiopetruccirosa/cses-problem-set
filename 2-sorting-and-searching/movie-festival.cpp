#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long, long long>

using namespace std;

int main() {_
    int n;
    cin >> n;

    // [ (end, begin) ]
    vector<pll> movies(n);
    for (int i = 0 ; i < n; i++)
        cin >> movies[i].second >> movies[i].first;

    sort(movies.begin(), movies.end());
    
    ll m = 0, last_end = 0;
    for (int i = 0 ; i < n; i++) {
        if (movies[i].second >= last_end) {
            last_end = movies[i].first;
            m++;
        }
    }
    cout << m << '\n';

    return 0;
}