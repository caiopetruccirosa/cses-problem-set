#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

#define LIM 1000000007

using namespace std;

int solve(vector<string> &board, vector<bool> &cols, vector<bool> &diagright, vector<bool> &diagleft, int r) {
    if (r >= 8)
        return 1;

    int s = 0;
    for (int c = 0; c < 8; c++) {
        if (!cols[c] && !diagleft[r+c] && !diagright[r-c+7] && board[r][c] == '.') {
            cols[c] = true;
            diagleft[r+c] = true;
            diagright[r-c+7] = true;
            s += solve(board, cols, diagright, diagleft, r+1);
            cols[c] = false;
            diagleft[r+c] = false;
            diagright[r-c+7] = false;
        }
    }
    return s;
}

int main() {_
    vector<bool> cols(8, false), diagright(15, false), diagleft(15, false);
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    cout << solve(board, cols, diagright, diagleft, 0) << '\n';

    return 0;
}