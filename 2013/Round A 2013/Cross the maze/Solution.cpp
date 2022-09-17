#include<bits/stdc++.h>
using namespace std;

map<char, pair<int, int> > mp;

char getNextDirection(char d) {
    if(d == 'N') return 'E';
    if(d == 'E') return 'S';
    if(d == 'S') return 'W';
    return 'N';
}

char getLeft(char d) {
    if(d == 'N') return 'W';
    if(d == 'E') return 'N';
    if(d == 'S') return 'E';
    return 'S';
}

char getRight(char d) {
    if(d == 'N') return 'E';
    if(d == 'E') return 'S';
    if(d == 'S') return 'W';
    return 'N';
}

char getBack(char d) {
    if(d == 'N') return 'S';
    if(d == 'E') return 'W';
    if(d == 'S') return 'N';
    return 'E';
}

int getIncoming(char d) {
    if(d == 'N') return 0;
    if(d == 'E') return 1;
    if(d == 'S') return 2;
    return 3;
}

bool checkBoundary(int x, int y, int N, char c) {
    if((x + mp[c].first) < 0) return true;
    if((y + mp[c].second) < 0) return true;
    if((x + mp[c].first) == N) return true;
    if((y + mp[c].second) == N) return true;

    return false;
}

int main() {
    int T;
    cin >> T;

    mp['E'] = make_pair(0, 1);
    mp['W'] = make_pair(0, -1);
    mp['N'] = make_pair(-1, 0);
    mp['S'] = make_pair(1, 0);

    for(int x = 1; x <= T; x++) {
        int N;
        cin >> N;

        vector<string> Sq(N);
        for(int i = 0; i < N; i++) cin >> Sq[i];
        int sx, sy, ex, ey;

        cin >> sx >> sy >> ex >> ey;

        char c;

        vector<vector<vector<int> > > V(N, vector<vector<int> >(N, vector<int>(4, 0)));

        
        if((sx == N) && (sy == 1)) c = 'N';
        else if((sx == 1) && (sy == 1)) c = 'E';
        else if((sx == N) && (sy == N)) c = 'W';
        else if((sx == 1) && (sy == N)) c = 'S';
        
        string path = "";
        int ans = 0;
        sx--;
        sy--;
        ex--;
        ey--;

        while(ans != -1){
            char l = getLeft(c);
            if((!checkBoundary(sx, sy, N, l)) && (Sq[sx + mp[l].first][sy + mp[l].second] == '.')) {
                if(V[sx + mp[l].first][sy + mp[l].second][getIncoming(l)] == 0) {
                    sx += mp[l].first;
                    sy += mp[l].second;
                    V[sx][sy][getIncoming(l)] = 1;
                    ans++;
                    c = l;
                    path += c;
                } else {
                    ans = -1;
                    path = "Edison ran out of energy.";
                }
            } else {
                l = c;
                if((!checkBoundary(sx, sy, N, l)) && (Sq[sx + mp[l].first][sy + mp[l].second] == '.')) {
                    if(V[sx + mp[l].first][sy + mp[l].second][getIncoming(l)] == 0) {
                        sx += mp[l].first;
                        sy += mp[l].second;
                        V[sx][sy][getIncoming(l)] = 1;
                        ans++;
                        c = l;
                        path += c;
                    } else {
                        ans = -1;
                        path = "Edison ran out of energy.";
                    }
                } else {
                    l = getRight(c);
                    if((!checkBoundary(sx, sy, N, l)) && (Sq[sx + mp[l].first][sy + mp[l].second] == '.')) {
                        if(V[sx + mp[l].first][sy + mp[l].second][getIncoming(l)] == 0) {
                            sx += mp[l].first;
                            sy += mp[l].second;
                            V[sx][sy][getIncoming(l)] = 1;
                            ans++;
                            c = l;
                            path += c;
                        } else {
                            ans = -1;
                            path = "Edison ran out of energy.";
                        }
                    } else {
                        l = getBack(c);
                        if((!checkBoundary(sx, sy, N, l)) && (Sq[sx + mp[l].first][sy + mp[l].second] == '.')) {
                            if(V[sx + mp[l].first][sy + mp[l].second][getIncoming(l)] == 0) {
                                sx += mp[l].first;
                                sy += mp[l].second;
                                V[sx][sy][getIncoming(l)] = 1;
                                ans++;
                                c = l;
                                path += c;
                            } else {
                                ans = -1;
                                path = "Edison ran out of energy.";
                            }
                        } else {
                            ans = -1;
                            path = "Edison ran out of energy.";
                        }
                    }
                }
            }
            if((sx == ex) && (sy == ey)) break;
        }

        cout << "Case #" << x << ": ";
        if(ans == -1)
            cout << path << endl;
        else cout << ans << endl << path << endl;
    }
}