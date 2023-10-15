#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD (int)1e9+7

int mod(long A) {
    return ((A % MOD) + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE // not part of code, used to beutify input output
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll T, N, M;
    cin >> T;
    for(int test_cases = 1; test_cases <= T; test_cases++) {
        ll ans = 0;
        cout << "Case #" << test_cases << ": " << ans << endl;
    }
    
    return 0;
}
