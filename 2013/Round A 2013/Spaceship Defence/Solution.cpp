#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    #ifndef ONLINE_JUDGE // not part of code, used to beutify input output
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T, N, M, S;
    cin >> T;
    
    for(int x = 1; x <= T; x++) {
        cin >> N;
        string rooms[N];

        for(int i = 0; i < N; i++) cin >> rooms[i];

        cin >> M;
        vector<int> ans;
        int a, b, t, p, q;
        for(int i = 0; i < M; i++) {
            cin >> a >> b >> t;
        }

        cin >> S;
        for(int i = 0; i < S; i++) {
            cin >> p >> q;
        }

        cout << "Case #" << x << ":" << endl;
        for(int y: ans) cout << y << endl;
    }
    return 0;
}