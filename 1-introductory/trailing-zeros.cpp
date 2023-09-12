#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {_
    ull n;
    cin >> n;

    int count = 0;
    for (ull i = 5; n/i >= 1; i *= 5)
        count += n/i;

    cout << count << '\n';

    return 0;
}