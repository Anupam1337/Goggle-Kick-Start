#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T, N;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        cin >> N;
        string states[N];
        string led = "2222222";
        for(int i = 0; i < N; i++) {
            cin >> states[i];
            for(int j = 0; j < 7; j++) {
                if(states[i][j] == '1') led[j] = '1';
            }
        }

        string digits[] = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};

        string y = "";
        map<int, string> mp;
        for(int i = 0; i < 10; i++) mp[i] = led;
        
        for(int i = 0; i < N; i++) {
            map<int, string> pr;
            for(auto p: mp) {
                int f = 1;
                int n = p.first;
                string leds = p.second;
                for(int k = 0; k < 7; k++) {
                    if(states[i][k] == '1') {
                        if(digits[n][k] == '0' || leds[k] == '0') {
                            f = 0;
                            break;
                        }
                        leds[k] = '1';
                    } else if(digits[n][k] == '1') {
                        if(leds[k] == '1') {
                            f = 0;
                            break;
                        }
                        leds[k] = '0';
                    }
                }
                if(f == 1) pr[((n + 9) % 10)] = leds;
            }
            mp = pr;
        }

        for(auto p: mp) {
            string ans = digits[p.first];
            led = p.second;
            for(int k = 0; k < 7; k++) {
                if(ans[k] == '1' && led[k] == '2') {
                    ans = "ERROR!";
                    break;
                }
                if(led[k] == '0') ans[k] = '0';
            }

            if(y == "")
                y = ans;
            
            if(y != ans) y = "ERROR!";
        }
        if(y == "") y = "ERROR!";
        cout << "Case #" << x << ": " << y << endl;
    }

	return 0;
}
