#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T, B, x1, y1, x2, y2;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> B;
        vector<pair<int, int> > V;
        for(int i = 0; i < B; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            for(int j = x1; j <= x2; j++) {
                for(int k = y1; k <= y2; k++) {
                    V.push_back(make_pair(j, k));
                }
            }
        }
        int N = V.size();
        int x, y, d = INT_MAX;
        for(int i = 0; i < N; i++) {
            long dis = 0;
            for(int j = 0; j < N; j++) {
                dis += abs(V[j].first - V[i].first) + abs(V[j].second - V[i].second);
            }
            if(dis == d) {
                if(V[i].first == x) y = min(y, V[i].second);
                else if(V[i].first < x) {
                    x = V[i].first;
                    y = V[i].second;
                }
            } else if(dis < d) {
                d = dis;
                x = V[i].first;
                y = V[i].second;
            }
        }

        cout << "Case #" << t << ": " << x << " " << y << " " << d << endl;
    }

    return 0;
}