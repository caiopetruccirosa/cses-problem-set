#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int main() {_
    int n;
    cin >> n;

    while (n--) {
        int x, divs = 0;
        cin >> x;
        for (int i = 1; i*i <= x; i++) {
            if (i*i == x) {
                divs++;
            } else if (x % i == 0) {
                divs += 2;
            }
        }
        cout << divs << '\n';
    }

    return 0;
}