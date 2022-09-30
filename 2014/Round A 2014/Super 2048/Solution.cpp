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