#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, y;
    string mx, S;
    getline(cin, S);
    T = stoi(S);
    
    for(int x = 1; x <= T; x++) {
        getline(cin, S);
        N = stoi(S);
        y = 0;

        for(int i = 0; i < N; i++) {
            getline(cin, S);
            if((i == 0) || (S >= mx)) mx = S;
            else y++;
        }

        cout << "Case #" << x << ": " << y << endl;
    }
    return 0;
}