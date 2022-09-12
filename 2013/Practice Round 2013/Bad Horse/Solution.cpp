#include <bits/stdc++.h>
using namespace std;

string dfs(int i, vector<vector<int> > &adj, vector<bool> &V, vector<int> &color) {
    V[i] = true;

    for(int j = 0; j < adj[i].size(); j++) {
        if(V[adj[i][j]] == false) {
            color[adj[i][j]] = 1 - color[i];
            string s =dfs(adj[i][j], adj, V, color);
            if(s == "No") return s;
        } else if(color[i] == color[adj[i][j]]) return "No";
    }

    return "Yes";
}

int main() {
    int T, M;
    string S, y;
    cin >> T;

    for(int x = 1; x <= T; x++) {
        cin >> M;
        y = "Yes";

        vector<pair<string, string> > names(M);
        unordered_map<string, int> mp;
        int K = 1;

        for(int i = 0; i < M; i++) {
            cin >> names[i].first >> names[i].second;
            if(mp[names[i].first] == 0) mp[names[i].first] = K++;
            if(mp.find(names[i].second) == mp.end()) mp[names[i].second] = K++;
        }

        vector<vector<int> > adj(K);

        for(int i = 0; i < M; i++) {
            adj[mp[names[i].first]].push_back(mp[names[i].second]);
            adj[mp[names[i].second]].push_back(mp[names[i].first]);
        }

        vector<bool> V(K, false);
        vector<int> color(K, -1);
        for(int i = 1; i < K; i++) {
            if(!V[i]) {
                color[i] = 0;
                y = dfs(i, adj, V, color);
                if(y == "No") break;
            }
        }

        cout << "Case #" << x << ": " << y << endl;
    }
    return 0;
}
