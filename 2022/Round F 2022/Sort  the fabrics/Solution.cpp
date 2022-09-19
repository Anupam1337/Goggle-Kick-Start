#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> P1, pair<int, int> P2) {
    if(P1.first == P2.first) return P1.second < P2.second;
    return P1.first < P2.first;
}

bool cmp2(pair<string, int> P1, pair<string, int> P2) {
    if(P1.first == P2.first) return P1.second < P2.second;
    return P1.first < P2.first;
}

int main() {
    int T;
    cin >> T;

    for(int x = 1; x <= T; x++) {
        int N;
        cin >> N;
        vector<pair<string, int> > F1(N);
        vector<pair<int, int> > F2(N);
        vector<pair<pair<string, int>, int> > O(N);
        for(int i = 0; i < N; i++) {
            cin >> O[i].first.first >> O[i].first.second >> O[i].second;
            F1[i].first = O[i].first.first;
            F2[i].first = O[i].first.second;
            F1[i].second = F2[i].second = O[i].second;
        }

        int ans = 0;
        sort(F1.begin(), F1.end(), cmp2);
        sort(F2.begin(), F2.end(), cmp);

        int y = 0;
        for(int i = 0; i < N; i++) {
            if((F1[i].first == O[i].first.first) && (F1[i].second == O[i].second) && (F2[i].first == O[i].first.second) && (F2[i].second == O[i].second)) y++;
        }


        cout << "Case #" << x << ": " << y << endl;;
    }
}