#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        int id;
        uint64_t n, p = 1, q = 1;
        cin >> id;
        if(id == 1) {
            cin >> n;
            int d = 64 - ((int)log2(n)) - 1;
            string s = bitset<64>(n).to_string().substr(d);
            for(int i = 1; i < s.size(); i++) {
                if(s[i] == '1') p += q;
                else q += p;
            }
            cout << "Case #" << x << ": " << p << " " << q << endl;
        } else {
            cin >> p >> q;
            n = 0;
            uint64_t i = 1;
            while((p >= 1) && (q >= 1)) {
                if(p < q) {
                    q -= p;
                } else {
                    p -= q;
                    n += i;
                }
                i <<= 1;
            }

            cout << "Case #" << x << ": " << n << endl;
        }
    }
    return 0;
}