#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define pic pair<int,char>

#define LIM 1000000007

using namespace std;

int main() {_
    int n;
    cin >> n;

    int pairs = 0;
    vector<bool> matched(n+1, false);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        if (!matched[a] && !matched[b]) {
            cout << "Combinou " << a << " e " << b << '\n';
            pairs++;
            matched[a] = true;
            matched[b] = true;
        }
    }
    cout << pairs << '\n';

    return 0;
}