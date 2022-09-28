#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T, N;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        cin >> N;
        vector<string> board(N);
        for(int i = 0; i < N; i++) cin >> board[i];
        string y = "Impossible";
        cout << "Case #" << x << ": " << y << endl;
    }

    return 0;
}