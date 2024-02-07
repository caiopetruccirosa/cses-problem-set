// proof explanation: https://www.quora.com/Why-does-the-median-minimize-the-sum-of-absolute-deviations/answer/Michal-Fori%C5%A1ek?ch=10&oid=4386483&share=04ba8843&srid=3E2oy&target_type=answer

#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {_
    int n;
    cin >> n;

    vector<ll> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p.begin(), p.end());

    if (n % 2 == 0) {
        ull cost1 = 0, cost2 = 0;
        for (int i = 0; i < n; i++) {
            cost1 += abs(p[i]-p[n/2-1]);
            cost2 += abs(p[i]-p[n/2]);
        }
        cout << min(cost1, cost2) << '\n';
    } else {
        ull cost = 0;
        for (int i = 0; i < n; i++) {
            cost += abs(p[i]-p[n/2]);
        }
        cout << cost << '\n';
    }

    return 0;
}