#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

void print_code(string s, int n) {
    for (int i = 0; i < (n-s.size()); i++)
        cout << '0';
    cout << s << '\n';
}

int main() {_
    int n;
    cin >> n;

    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    for (int i = 0; i < n; i++) {
        int k = v.size();
        for (int j = k-1; j >= 0; j--) {
            v.push_back('1' + v[j]);
        }
        for (int j = 0; j < k; j++) {
            v[j] = '0' + v[j];
        }
    }

    for (int i = 0; i < v.size(); i++) {
        print_code(v[i], n);
    }

    return 0;
}