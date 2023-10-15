#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll nCr(int N, int r) {
    if(r == 0) return 1;
    if(r > (N - r)) r = N - r;
    ll num = N, den = r;
    N--;
    r--;
    num /= __gcd(num, den);
    den /= __gcd(num, den);
    while(r >= 1) {
        num *= N--;
        den *= r--;
        num /= __gcd(num, den);
        den /= __gcd(num, den);
    }
    return num;
}

ll solve(int M, int N, int r = 0) {
    if(M == 1) return N;
    ll ans = 0;
    ll C = nCr(N, r);
    ans = pow(M, N);
    ans *= C;
    return (ans - solve(M - 1, N, r + 1));
}

int map() {
    int T;
    cin >> T;
    while(T--) {
        int M, N;
        cin >> M >> N;
        cout << solve(M, N);
    }
    return 0;
}