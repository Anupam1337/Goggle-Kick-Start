#include<bits/stdc++.h>
using namespace std;
#define MOD (int)1e9+7
#define ll long long

int mod(long A) {
    return ((A % MOD) + MOD) % MOD;
}

int solve(int N, int M) {
    if (N == 0 || M == 0) return 0;
    
    vector<vector<ll> > DP(N + 1, vector<ll>(M + 1, 0));	//@warning: int shoule be ll???
    DP[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= M; j++) {
            DP[i][j] = ((N - i + 1) * DP[i - 1][j - 1] % MOD + i * DP[i][j - 1] % MOD + MOD) % MOD;
        }
    }
    return DP[N][M];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long T, N, M;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        cin >> M >> N;
        cout << "Case #" << x << ": " << solve(N, M) << endl;
    }
    
    return 0;
}