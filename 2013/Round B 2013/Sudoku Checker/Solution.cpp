#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    cin >> T;

    for(int x = 1; x <= T; x++) {
        cin >> N;

        string y = "Yes";
        int A[N * N][N * N];
        for(int i = 0; i < N * N; i++) {
            for(int j = 0; j < N * N; j++) {
                cin >> A[i][j];
            }
        }

        int f = 1;
        for(int i = 0; (f == 1) && (i < N * N); i++) {
            map<int, int> mp1, mp2;
            for(int j = 0; (f == 1) && (j < N * N); j++) {
                if((A[i][j] < 1) || (A[i][j] > (N * N)) || (A[j][i] < 1) || (A[j][i] > (N * N)) || (mp1[A[i][j]] == 1) || (mp2[A[j][i]] == 1)) {
                    y = "No";
                    f = 0;
                }
                mp1[A[i][j]] = 1;
                mp2[A[j][i]] = 1;
            }
        }
        for(int i = 0; (f == 1) && (i < N); i++) {
            for(int j = 0; (f == 1) && (j < N); j++) {
                map<int, int> mp;
                for(int i = 0; (f == 1) && (i < N); i++) {
                    for(int j = 0; (f == 1) && (j < N); j++) {
                        if((A[i][j] < 1) || (A[i][j] > (N * N)) || (mp[A[i][j]] == 1)) {
                            y = "No";
                            f = 0;
                        }
                        mp[A[i][j]] = 1;
                    }
                }
            }
        }
        cout << "Case #" << x << ": " << y << endl;
    }
    return 0;
}
