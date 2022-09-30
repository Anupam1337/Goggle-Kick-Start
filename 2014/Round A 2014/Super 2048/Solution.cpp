#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T, N;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        string DIR;
        cin >> N >> DIR;
        vector<vector<int> > board(N, vector<int>(N));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }

        vector<vector<int> > y(N, vector<int>(N, 0));

        if(DIR == "left") {
            for(int i = 0; i < N; i++) {
                int s = 0, k = 0;
                for(int j = 0; j < N; j++) {
                    if(board[i][j] == 0) continue;
                    if(s == 0) {
                        y[i][k++] = board[i][j];
                        s = 1;
                    } else {
                        if(y[i][k - 1] == board[i][j]) {
                            y[i][k - 1] += board[i][j];
                            s = 0;
                        } else {
                            y[i][k++] = board[i][j];
                        }
                    }
                }
            }
        } else if(DIR == "right") {
            for(int i = 0; i < N; i++) {
                int s = 0, k = N - 1;
                for(int j = N - 1; j >= 0; j--) {
                    if(board[i][j] == 0) continue;
                    if(s == 0) {
                        y[i][k--] = board[i][j];
                        s = 1;
                    } else {
                        if(y[i][k + 1] == board[i][j]) {
                            y[i][k + 1] += board[i][j];
                            s = 0;
                        } else {
                            y[i][k--] = board[i][j];
                        }
                    }
                }
            }
        } else if(DIR == "up") {
            for(int i = 0; i < N; i++) {
                int s = 0, k = 0;
                for(int j = 0; j < N; j++) {
                    if(board[j][i] == 0) continue;
                    if(s == 0) {
                        y[k++][i] = board[j][i];
                        s = 1;
                    } else {
                        if(y[k - 1][i] == board[j][i]) {
                            y[k - 1][i] += board[j][i];
                            s = 0;
                        } else {
                            y[k++][i] = board[j][i];
                        }
                    }
                }
            }
        } else if(DIR == "down") {
            for(int i = 0; i < N; i++) {
                int s = 0, k = N - 1;
                for(int j = N - 1; j >= 0; j--) {
                    if(board[j][i] == 0) continue;
                    if(s == 0) {
                        y[k--][i] = board[j][i];
                        s = 1;
                    } else {
                        if(y[k + 1][i] == board[j][i]) {
                            y[k + 1][i] += board[j][i];
                            s = 0;
                        } else {
                            y[k--][i] = board[j][i];
                        }
                    }
                }
            }
        }
        cout << "Case #" << x << ":" << endl;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << y[i][j];
                if(j < (N - 1)) cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}