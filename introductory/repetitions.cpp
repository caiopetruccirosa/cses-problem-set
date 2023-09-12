#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    string s;
    cin >> s;

    int current_len = 0, best_len = 0;
    char last_char = ' ';
    for (char c: s) {
        if (last_char != ' ' && last_char != c) {
            current_len = 0;
        }
        last_char = c;
        current_len++;
        best_len = max(best_len, current_len);
    }

    cout << best_len << '\n';

    return 0;
}