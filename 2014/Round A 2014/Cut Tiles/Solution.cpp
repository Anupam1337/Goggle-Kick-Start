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
        ll M;
        cin >> N >> M;
        int y = 0;
        vector<ll> required(N);
        for(int i = 0; i < N; i++) {
            cin >> required[i];
            required[i] = 1LL << required[i];
        }
        sort(required.begin(), required.end());

        vector<pair<ll, ll> > st;
        while(required.size() > 0) {
            if(st.empty()) {
                st.push_back(make_pair(M, M));
                y++;
            }

            N = required.size();
            for(int i = N - 1; i >= 0; i--) {
                for(int j = 0; j < st.size(); j++) {
                    if(st[j].first < required[i]) continue;
                    pair<ll, ll> p = st[j];
                    st.erase(st.begin() + j);
                    j--;
                    if(p.first == required[i]) {
                        if(p.second > required[i]) {
                            st.push_back(make_pair(min(p.second - p.first, p.first), max(p.second - p.first, p.first)));
                        }
                    } else {
                        ll m1 = p.first - required[i];
                        ll m2 = p.second - required[i];
                        st.push_back(make_pair(min(m1, m2), max(m1, m2)));
                        st.push_back(make_pair(min(m1, required[i]), max(m1, required[i])));
                        st.push_back(make_pair(min(m2, required[i]), max(m2, required[i])));
                    }
                    required.erase(required.begin() + i);
                    sort(st.begin(), st.end());
                    break;
                }
                // for(int j = 0; j < st.size(); j++) cout << st[j].first << " " << st[j].second << endl;
            }
            st = vector<pair<ll, ll> >();
        }
        cout << "Case #" << x << ": " << y << endl;
    }
	return 0;
}
