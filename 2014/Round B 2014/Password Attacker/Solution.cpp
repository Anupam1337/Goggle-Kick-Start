#include<bits/stdc++.h>
using namespace std;
#define MOD (int)1e9+7

int mod(long A) {
    return ((A % MOD) + MOD) % MOD;
}

int power(int A, int B) {
    if(B == 0) return 1;
    if(A == 1) return 1;
    A %= MOD;
    if(B == 1) return A;
    long m = power((A * A) % MOD, B / 2);
    cout << A << " " << B << " ";
    if(B%2 == 1) cout << (A * m) % MOD << endl;
    else cout << m << endl;
    if(B%2 == 1) return (A * m) % MOD;
    return m;
}

int invmod(int A) {
    return power(A, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE // not part of code, used to beutify input output
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    long T, N, M;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        cin >> M >> N;
        cout << "Case #" << x << ":\n";

        long sum = power(M, N);
        long fact[M + 1] = {0};
        fact[0] = fact[1] = 1;
        for(int i = 2; i < M; i++) fact[i] = fact[i - 1] * i;
        for(int i = 1; i < M; i++) {
            cout << (M - i) << " " << N << " " << power(M - i, N) << " ";
            long r = power(M - i, N);
            long cr = fact[M - i];
            cr /= invmod(fact[i]);
            cr /= invmod(fact[M - i]);
            // cr /= fact[M - i]; // (fact[i] * fact[M - i]));
            if(i % 2 == 0) sum = mod(sum + mod(r  * cr));
            else sum = mod(sum - mod(r  * cr));
            cout << i << " " << power(M, N) << " " << r << " " << cr << " " << mod(r  * cr) << endl;
        }

        // for(int i = 0; i <= M; i++) {
        //     long m = pow(-1, i);
        //     long r = pow(M - m, N);
            
        //     sum += mod((m * r) * mod(fact[M] / (fact[m] * fact[M - m])));
        //     sum = mod(sum);
        // }
        cout << sum << endl;
    }
    
    return 0;
}
