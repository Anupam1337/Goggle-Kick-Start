#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cout << "Case #1:\n";
    string S;
    int c = 0;
    while(getline(cin, S)) {
        int N = S.size();
        for(int i = 0; i < N; i++) {
            if(S[i] == '*') {
                if((i < (N - 1)) && (S[i + 1] == '/')) {
                    if(c > 0) {
                        i++;
                        c--;
                    } else cout << S[i];
                }
                else if(c == 0) cout << S[i];
            } else if(S[i] == '/') {
                if((i < (N - 1)) && (S[i + 1] == '*')) i++, c++;
                else if(c == 0) cout << S[i];
            } else if(c == 0) cout << S[i];
        }
        if(c == 0) cout << endl;
    }
    return 0;
}