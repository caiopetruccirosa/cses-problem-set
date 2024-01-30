#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair<long long, long long>

using namespace std;

int main() {_
    int n, k;
    cin >> n >> k;

    vector<ll> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    for (int i = (k-1)/2; i < n-(k/2); i++)
        cout << numbers[i] << ' ';
    cout << '\n';

    return 0;
}