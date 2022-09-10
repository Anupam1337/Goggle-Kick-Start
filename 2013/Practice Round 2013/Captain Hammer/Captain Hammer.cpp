#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, t;
    cin >> T;
    t = T;

    while(T--) {
        long double ans = 0, V, D, pi = 3.14159265359, g = 9.8;
        cin >> V >> D;

        long double d = ((g * D) / (V * V));
        if(d > 1) d = 1;
        else if(d < -1) d = -1;
        ans = (90 * asin(d)) / pi;

        cout << "Case #" << (t - T) << ": " << fixed << setprecision(9) << ans << endl;
    }
}