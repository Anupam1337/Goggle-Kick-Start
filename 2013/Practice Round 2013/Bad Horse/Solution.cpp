#include <bits/stdc++.h>
using namespace std;

bool check(vector<pair<string, string> > names, int ind, set<string> G1, set<string> G2) {
    for(int i = ind; i < names.size(); i++) {
        if((find(G1.begin(), G1.end(), names[i].first) != G1.end()) && (find(G1.begin(), G1.end(), names[i].second) != G1.end())) return false;
        else if((find(G2.begin(), G2.end(), names[i].first) != G2.end()) && (find(G2.begin(), G2.end(), names[i].second) != G2.end())) return false;
        else if((find(G1.begin(), G1.end(), names[i].first) != G1.end()) && (find(G2.begin(), G2.end(), names[i].second) != G2.end())) continue;
        else if((find(G1.begin(), G1.end(), names[i].second) != G1.end()) && (find(G2.begin(), G2.end(), names[i].first) != G2.end())) continue;
        else if(find(G1.begin(), G1.end(), names[i].first) != G1.end()) G2.insert(names[i].second);
        else if(find(G1.begin(), G1.end(), names[i].second) != G1.end()) G2.insert(names[i].first);
        else if(find(G2.begin(), G2.end(), names[i].first) != G2.end()) G1.insert(names[i].second);
        else if(find(G2.begin(), G2.end(), names[i].second) != G2.end()) G1.insert(names[i].first);
        else {
            set<string> G3 = G1;
            set<string> G4 = G2;
            G1.insert(names[i].first);
            G2.insert(names[i].second);
            G3.insert(names[i].second);
            G4.insert(names[i].first);
            
            return (check(names, i + 1, G1, G2) || check(names, i + 1, G3, G4));
        }
    }
    
    return true;
}

int main() {
    int T, M;
    string S, y;
    cin >> T;
    
    for(int x = 1; x <= T; x++) {
        cin >> M;
        y = "Yes";
        
        vector<pair<string, string> > names(M);
    
        for(int i = 0; i < M; i++) cin >> names[i].first >> names[i].second;
        sort(names.begin(), names.end());
        
        if(check(names, 0, set<string>(), set<string>()) == false) y = "No";

        cout << "Case #" << x << ": " << y << endl;
    }
    return 0;
}