#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    int q;
    cin >> q;

    while (q--) {
        ll k, n = 0, pow10 = 1, digits = 0;
        cin >> k;
        while (digits < k) {
            n++;
            pow10 *= 10;
            digits += n*(9*(pow10/10));
        }
        // index of the digit in the group (0-based)
        ll j = k - 1 - (digits - (n*9*(pow10/10)));
        // index of the number in the group (0-based)
        ll i = j / n;
        // index of the digit inside the number (0-based and left->right)
        ll d = j % n;
        // number with digit
        ll number = (pow10/10) + i;
        // removes digits to get dth digit
        for (int i = 0; i < (n-d-1); i++)
            number /= 10;
        cout << number % 10 << '\n';
    }

    return 0;
}