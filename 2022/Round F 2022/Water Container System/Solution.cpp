#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T;
    cin >> T;

    for(int x = 1; x <= T; x++) {
        long long M, N, P;

        cin >> M >> N >> P;
        vector<vector<int> > St(N, vector<int>(M));
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) cin >> St[j][i];
        }
        long long y = 0;
        for(int i = 0; i < N; i++) {
            y += (*max_element(St[i].begin(), St[i].end()) - St[i][P - 1]);
        }
        cout << "Case #" << x << ": " << y << endl;
    }
}