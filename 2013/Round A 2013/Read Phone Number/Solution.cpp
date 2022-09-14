#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    string number[] = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
    string count[] = {"", "", "double ", "triple ", "quadruple ", "quintuple ", "sextuple ", "septuple ", "octuple ", "nonuple ", "decuple "};

    for(int x = 1; x<= T; x++) {
        string y = "", N, F;
        cin >> N >> F;
        int d = 0, i = 0, j = 0, c = 0;
        while(i < N.size()) {
            if(d == 0) {
                while(j < F.size()) {
                    if(F[j] == '-') {
                        j++;
                        break;
                    } else {
                        d = ((d * 10) + (F[j] - '0'));
                    }

                    j++;
                }
            }
            int k = N[i] - '0';
            c++;

            if((d == 1) || (i == (N.size() - 1)) || (((i + 1) < N.size())) && (N[i] != N[i + 1])) {
                if((c == 1) || (c > 10)) {
                    while(c--) y += number[k];
                } else y += count[c] + number[k];
                c = 0;
            }
            d--;
            i++;
        }
        y.pop_back();

        cout << "Case #" << x << ": " << y << endl;
    }
    return 0;
}