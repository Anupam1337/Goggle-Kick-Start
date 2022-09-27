#include <bits/stdc++.h>
using namespace std;

int N, M, enx, eny, exx, exy;
vector<vector<int> > maze;

bool isValid(int x, int y) {
    return ((x >= 0) && (x < N) && (y >= 0) && (y < M));
}

int BFS() {
    queue<pair<int, int> > qu;
    qu.push(make_pair(enx, eny));
    vector<vector<int> > R = maze;

    vector<vector<bool> > V(N, vector<bool>(M, false));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(maze[i][j] == -1) V[i][j] = true;
            else V[i][j] = false;

    V[enx][eny] = true;
    while(!qu.empty()) {
        queue<pair<int, int> > temp;
        while(!qu.empty()) {
            pair<int, int> q = qu.front();
            qu.pop();
            int x = q.first;
            int y = q.second;
            int val = R[x][y];
            if((x == exx) && (y == exy)) {
                return val;
            }
            if(isValid(x - 1, y)) {
                if(maze[x - 1][y] != -1)
                    R[x - 1][y] = max(R[x - 1][y], val + maze[x - 1][y]);
                if(V[x - 1][y] == false) {
                    V[x - 1][y] = true;
                    temp.push(make_pair(x - 1, y));
                }
            }
            if(isValid(x, y - 1)) {
                if(maze[x][y - 1] != -1)
                    R[x][y - 1] = max(R[x][y - 1], val + maze[x][y - 1]);
                 if(V[x][y - 1] == false) {
                    V[x][y - 1] = true;
                    temp.push(make_pair(x, y - 1));
                }
            }
            if(isValid(x + 1, y)) {
                if(maze[x + 1][y] != -1)
                    R[x + 1][y] = max(R[x + 1][y], val + maze[x + 1][y]);
                if(V[x + 1][y] == false) {
                    V[x + 1][y] = true;
                    temp.push(make_pair(x + 1, y));
               }
            }
            if(isValid(x, y + 1)) {
                if(maze[x][y + 1] != -1)
                    R[x][y + 1] = max(R[x][y + 1], val + maze[x][y + 1]);
                if(V[x][y + 1] == false) {
                    V[x][y + 1] = true;
                    temp.push(make_pair(x, y + 1));
                }
            }
        }
        qu = temp;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        maze.clear();
        cin >> N >> M >> enx >> eny >> exx >> exy;
        for(int i = 0; i < N; i++) {
            vector<int> row(M);
            for(int j = 0; j < M; j++) cin >> row[j];
            maze.push_back(row);
        }

        int ans = BFS();
        if(ans == -1) cout << "Case #" << x << ": Mission Impossible.\n";
        else cout << "Case #" << x << ": " << ans << endl;
    }

    return 0;
}