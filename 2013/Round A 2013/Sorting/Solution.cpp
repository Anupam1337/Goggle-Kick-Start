#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    cin >> T;

    for(int x = 1; x <= T; x++) {
        cin >> N;
        vector<int> s(N, 0);
        vector<int> e;
        vector<int> o;

        for(int i = 0; i < N; i++) {
            cin >> s[i];
            if((s[i]%2) == 0) e.push_back(s[i]);
            else o.push_back(s[i]);
        }

        sort(e.begin(), e.end(), greater<int>());
        sort(o.begin(), o.end());

        for(int i = 0, j = 0, k = 0; i < N; i++) {
            if(s[i] % 2 == 0) s[i] = e[j++];
            else s[i] = o[k++];
        }

        cout << "Case #" << x << ": ";
        for(int y:s)
            cout << y << " ";

        cout << endl;
    }
    return 0;
}
