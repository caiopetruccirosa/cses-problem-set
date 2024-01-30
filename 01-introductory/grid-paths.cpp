#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii pair<int,int>

using namespace std;

int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int path[48];
bool visited[9][9];

int solve(int idx, int r, int c) {
    // CHECK IF PATH HAS ENDED
    if (idx >= 48)
        return 1*(r == 7 && c == 1);

    // CHECK IF HAS REACHED END BEFORE COMPLETE PATH
    if (r == 7 && c == 1)
        return 0;

    // CHECK IF POSITION SPLIT THE BOARD
    if ((
            visited[r+drow[0]][c+dcol[0]] &&  // cant move U
            visited[r+drow[1]][c+dcol[1]] &&  // cant move D
            !visited[r+drow[2]][c+dcol[2]] && // can move L
            !visited[r+drow[3]][c+dcol[3]]    // can move R
        )
        ||
        (
            visited[r+drow[2]][c+dcol[2]] &&  // cant move L
            visited[r+drow[3]][c+dcol[3]] &&  // cant move R
            !visited[r+drow[0]][c+dcol[0]] && // can move U
            !visited[r+drow[1]][c+dcol[1]]    // can move D
        ))
        return 0;

    // MARK CURRENT POSITION AS VISITED
    visited[r][c] = true;
    
    int amount = 0;
    if (path[idx] < 4) { // FOLLOWS PATH
        if (!visited[r+drow[path[idx]]][c+dcol[path[idx]]]) {
            amount += solve(idx+1, r+drow[path[idx]], c+dcol[path[idx]]);
        }
    } else { // TRIES DIFFERENTS PATHS
        for (int i = 0; i < 4; i++) {
            // CHECK IF PATH IS VISITED
            if (visited[r+drow[i]][c+dcol[i]]) {
                continue;
            }

            // CHECK IF PATH WILL LEAD TO DEADEND
            // ...
            
            amount += solve(idx+1, r+drow[i], c+dcol[i]);
        }
    }

    visited[r][c] = false;
    
    return amount;
}

int main() {_
    string s;
    cin >> s;

    for (int i = 0; i < 48; i++) {
        if (s[i] == 'U')
            path[i] = 0;
        else if (s[i] == 'D')
            path[i] = 1;
        else if (s[i] == 'L')
            path[i] = 2;
        else if (s[i] == 'R')
            path[i] = 3;
        else
            path[i] = 4; 
    }
    for (int i = 0; i < 9; i++) {
        visited[0][i] = true;
        visited[8][i] = true;
        visited[i][0] = true;
        visited[i][8] = true;
    }
    for (int i = 1; i < 8; i++)
        for (int j = 1; j < 8; j++)
            visited[i][j] = false;

    cout << solve(0, 1, 1) << '\n';

    return 0;
}