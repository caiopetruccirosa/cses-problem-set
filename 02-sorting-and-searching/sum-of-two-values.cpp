#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long, long long>

using namespace std;

int main() {_
    int n;
    ll x;
    cin >> n >> x;

    vector<pair<ll, int>> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i].first;
        numbers[i].second = i+1;
    }

    sort(numbers.begin(), numbers.end());

    int i = 0, j = n-1;
    while (i < j && numbers[i].first + numbers[j].first != x) {
        if (numbers[i].first + numbers[j].first < x) {
            i++;
        } else {
            j--;
        }
    }

    if (i < j)
        cout << numbers[i].second << ' ' << numbers[j].second << '\n';
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}