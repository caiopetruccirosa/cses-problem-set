#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void get_anagrams(vector<string> &v, string &base, string &s, int i, int n) {
    if (i == n) {
        v.push_back(s);
        return;
    }
    for (int k = 0; k < n; k++) {
        if ((k > 0 && base[k] == base[k-1]) || (base[k] == '-'))
            continue;
        s[i] = base[k];
        base[k] = '-';
        get_anagrams(v, base, s, i+1, n);
        base[k] = s[i];
    }
}

int main() {_
    string base, s;
    cin >> base;

    for (int k = 0; k < (int)base.length(); k++)
        s += '-';

    sort(base.begin(), base.end());
    vector<string> v;
    get_anagrams(v, base, s, 0, base.length());

    cout << v.size() << '\n';
    for (string a: v)
        cout << a << '\n';

    return 0;
}