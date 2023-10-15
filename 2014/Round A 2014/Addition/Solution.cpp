#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE // not part of code, used to beutify input output
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T, N, M;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        cout << "Case #" << x << ":" << endl;
        cin >> N;
        map<pair<string, string>, int> mp, inp;
        set<string> st;
        string a, b, s;
        int v;
        for(int i = 0; i < N; i++) {
            cin >> s;
            a = "";
            b = "";
            v = 0;
            int j = 0;
            while(s[j] != '+') {
                a += s[j++];
            }
            j++;
            while(s[j] != '=') {
                b += s[j++];
            }
            j++;
            int m = 1;
            while(j < s.size()) {
                if(s[j] == '-') {
                    j++;
                    m = -1;
                }
                v = (v * 10) + (m * (s[j] - '0'));
                j++;
            }

            st.insert(a);
            st.insert(b);
            inp[make_pair(a, b)] = v;
            // inp[make_pair(b, a)] = v;
            mp[make_pair(a, b)] = v;
            mp[make_pair(b, a)] = v;
            for(auto vl: inp) {
                for(auto vl2: inp) {
                    if((vl.first.first == a) && (vl2.first.first == b)) {
                        if(mp.find(make_pair(vl.first.second, vl2.first.second)) == mp.end()) {
                            mp[make_pair(vl.first.second, vl2.first.second)] = vl.second + vl2.second - v;
                            mp[make_pair(vl2.first.second, vl.first.second)] = vl.second + vl2.second - v;
                        }
                    }
                    if((vl.first.second == a) && (vl2.first.first == b)) {
                        if(mp.find(make_pair(vl.first.first, vl2.first.second)) == mp.end()) {
                            mp[make_pair(vl.first.first, vl2.first.second)] = vl.second + vl2.second - v;
                            mp[make_pair(vl2.first.first, vl.first.second)] = vl.second + vl2.second - v;
                        }
                    }
                    if((vl.first.first == a) && (vl2.first.second == b)) {
                        if(mp.find(make_pair(vl.first.second, vl2.first.first)) == mp.end()) {
                            mp[make_pair(vl.first.second, vl2.first.first)] = vl.second + vl2.second - v;
                            mp[make_pair(vl2.first.second, vl.first.first)] = vl.second + vl2.second - v;
                        }
                    }
                    if((vl.first.second == a) && (vl2.first.second == b)) {
                        if(mp.find(make_pair(vl.first.first, vl2.first.first)) == mp.end()) {
                            mp[make_pair(vl.first.first, vl2.first.first)] = vl.second + vl2.second - v;
                            mp[make_pair(vl2.first.first, vl.first.first)] = vl.second + vl2.second - v;
                        }
                    }
                }
            }
            // for(auto p: mp) {
            //     for(auto p2: mp) {
            //         if((p2.first.first == p.first.first) || (p2.first.first == p.first.second) || (p2.first.second == p.first.first) || (p2.first.second == p.first.second)) {
            //             if((mp.find(make_pair(a, p.first.first)) != mp.end()) && (mp.find(make_pair(b, p.first.second)) == mp.end())) {

            //             }
            //             if((mp.find(make_pair(b, p.first.first)) != mp.end()) && (mp.find(make_pair(a, p.first.second)) == mp.end())) {

            //             }
            //             if((mp.find(make_pair(a, p.first.second)) != mp.end()) && (mp.find(make_pair(b, p.first.first)) == mp.end())) {

            //             }
            //             if((mp.find(make_pair(b, p.first.second)) != mp.end()) && (mp.find(make_pair(a, p.first.first)) == mp.end())) {

            //             }
            //         }
            //     }
            // }

        }

        // for(auto p:mp) {
        //     cout << p.first.first << " + " << p.first.second << " = " << p.second << endl;
        // }
        cin >> M;
        while(M--) {
            cin >> s;
            a = "";
            b = "";
            v = 0;
            int j = 0;
            while(s[j] != '+') {
                a += s[j++];
            }
            j++;
            while(j < s.size()) {
                b += s[j++];
            }
            if(mp.find(make_pair(a, b)) != mp.end()) {
                cout << s << "=" << mp[make_pair(a, b)] << endl;
            }
        }
    }
    return 0;
}