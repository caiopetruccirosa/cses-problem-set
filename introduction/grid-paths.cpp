#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>

using namespace std;

//vector<pii> directions = {pii(0, 1), pii(0, -1), pii(1, 0), pii(-1, 0)};
vector<char> directions = {'U','D','L','R'};

pii can_move(vector<vector<bool>> &used, char d, pii pos) {
    if (d == 'D' && pos.second < 48 && !used[pos.first][pos.second+1])
        return pii(pos.first,pos.second+1);
    else if (d == 'U' && pos.second > 1 && !used[pos.first][pos.second-1])
        return pii(pos.first,pos.second-1);
    else if (d == 'L' && pos.first > 1 && !used[pos.first-1][pos.second])
        return pii(pos.first-1,pos.second);
    else if (d == 'R' && pos.first < 48 && !used[pos.first+1][pos.second])
        return pii(pos.first+1,pos.second);
    return pii(-1,-1);
}

int solve(vector<vector<int>> &paths, vector<vector<bool>> &used, string &s, int i, pii pos) {
    if (paths[pos.first][pos.second] != -1)
        return paths[pos.first][pos.second];

    if (i == s.length()) {
        if (pos.first == 1 && pos.second == 7)
            return 1;
        else
            return 0;
    }

    int amount = 0;
    if (s[i] != '?') {
        pii next = can_move(used, s[i], pos);
        if (next.first != -1 && next.second != -1) {
            cout << "Próxima posição: (" << next.first << "," << next.second << ")" << endl;
            used[next.first][next.second] = true;
            amount = solve(paths, used, s, i+1, next);
            used[next.first][next.second] = false;
        }
    } else {
        for (char d: directions) {
            pii next = can_move(used, d, pos);
            if (next.first != -1 && next.second != -1) {
                cout << "Próxima posição: (" << next.first << "," << next.second << ")" << endl;
                used[next.first][next.second] = true;
                amount += solve(paths, used, s, i+1, next);
                used[next.first][next.second] = false;
            } 
        }
    }

    paths[pos.first][pos.second] = amount;

    return amount;
}

int main() {_
    string s;
    cin >> s;

    vector<vector<bool>> used(49, vector<bool>(49, false));
    vector<vector<int>> paths(49, vector<int>(49, -1));
    
    int amount = 0;
    for (int x = 1; x <= 48; x++) {
        for (int y = 1; y <= 48; y++) {
            used[x][y] = true;
            amount += solve(paths, used, s, 0, pii(x,y));
            used[x][y] = false;
        }
    }
    cout << amount << '\n';

    return 0;
}