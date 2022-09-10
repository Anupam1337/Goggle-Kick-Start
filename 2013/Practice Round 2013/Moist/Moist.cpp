#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, ans;
    string mx, S;
    getline(cin, S);
    T = stoi(S);
    
    for(int t = 1; t <= T; t++) {
        getline(cin, S);
        N = stoi(S);
        ans = 0;

        for(int i = 0; i < N; i++) {
            getline(cin, S);
            if((i == 0) || (S >= mx)) mx = S;
            else ans++;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}