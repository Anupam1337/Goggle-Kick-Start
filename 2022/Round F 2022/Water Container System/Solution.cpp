#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    #ifndef ONLINE_JUDGE // not part of code, used to beutify input output
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    cout << T << endl;

    for(int x = 1; x <= T; x++) {
        int N, Q;
        int y = 0;

        cin >> N >> Q;

        int u, v;
        vector<vector<int> > G(N, vector<int>(N, 0));
        stack<int> s, t;

        for(int i = 1; i < N; i++) {
            cin >> u >> v;
            G[u - 1][v - 1] = 1;
            G[v - 1][u - 1] = 1;
        }

        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < N; j++) {
        //         cout << G[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        s.push(0);
        map<int, int> mp, mp2;
        int mx = 1;
        mp[0] = 1;
        mp2[1] = 1;
        while(!s.empty()) {
            int k = s.top();
            s.pop();
            for(int j = 0; j < N; j++) {
                if((G[k][j] == 1) and mp[j] == 0) {
                    t.push(j);
                    mp[j] = 1;
                }
            }
            if(s.empty() and !t.empty()) {
                s = t;
                mx++;
                mp2[mx] = s.size();
                // cout << mx << " " << mp2[mx] << endl;
                // stack<int> temp = s;
                // while(!temp.empty()) {
                //     cout << temp.top() << " ";
                //     cout << endl;
                //     temp.pop();
                // }
                // cout << endl;
                t = stack<int>();
            }
        }

        int w;
        for(int i = 0; i < Q; i++) cin >> w;
        for(int i = 1; i <= mx and (y + mp2[i] <= Q); i++) y  += mp2[i];
        cout << "Case #" << x << ": " << y << endl;
    }
}