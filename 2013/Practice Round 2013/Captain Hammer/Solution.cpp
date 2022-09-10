#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int x = 1; x < T; x++) {
        long double y = 0, V, D, pi = 3.14159265359, g = 9.8;
        cin >> V >> D;

        long double d = ((g * D) / (V * V));
        if(d > 1) d = 1;
        else if(d < -1) d = -1;
        y = (90 * asin(d)) / pi;

        cout << "Case #" << x << ": " << fixed << setprecision(9) << y << endl;
    }
}