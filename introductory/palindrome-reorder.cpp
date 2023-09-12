#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

int main() {_
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c: s)
        freq[c-'A']++;

    int odd_index = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            if (odd_index != -1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            odd_index = i;
        }
    }

    int j = 0;
    vector<char> palin(s.length(), ' ');
    for (int i = 0; i < 26; i++) {
        if (i == odd_index) {
            palin[s.length()/2] = 'A'+i;
            freq[i]--;
        }
        while (freq[i] > 0) {
            palin[j] = 'A'+i;
            palin[s.length()-j-1] = 'A'+i;
            freq[i] -= 2;
            j++;
        }
    }

    for (char c: palin)
        cout << c;
    cout << '\n';

    return 0;
}