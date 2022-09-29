#include <bits/stdc++.h>
using namespace std;

int getBlue(int i, int N, vector<string> S) {
    if(i == N) return 0;
    if(S[i][0] != 'B') return getBlue(i + 1, N, S);
    int j, k;
    stack<pair<int, int> > st;
    st.push(make_pair(i, 0));
    while(!st.empty()) {
        pair<int, int> p = st.top();
        st.pop();
        j = p.first;
        k = p.second;
        S[j][k] = '.';
        if(k == (N - 1)) return 1 + getBlue(i + 1, N, S);

        if((k > 0) && (S[j][k - 1] == 'B')) st.push(make_pair(j, k - 1));
        if((j < (N - 1)) && (k > 0) && (S[j + 1][k - 1] == 'B')) st.push(make_pair(j + 1, k - 1));
        if((j < (N - 1)) && (S[j + 1][k] == 'B')) st.push(make_pair(j + 1, k));
        if((k < (N - 1)) && (S[j][k + 1] == 'B')) st.push(make_pair(j, k + 1));
        if((j > 0) && (S[j - 1][k] == 'B')) st.push(make_pair(j - 1, k));
        if((j > 0) && (k < (N - 1)) && (S[j - 1][k + 1] == 'B')) st.push(make_pair(j - 1, k + 1));
    }
    return getBlue(i + 1, N, S);
}

int getRed(int j, int N, vector<string> S) {
    if(j == N) return 0;
    if(S[0][j] != 'R') return getRed(j + 1, N, S);
    int i = 0, k = j;
    stack<pair<int, int> > st;
    st.push(make_pair(i, k));
    while(!st.empty()) {
        pair<int, int> p = st.top();
        st.pop();
        i = p.first;
        k = p.second;
        S[i][k] = '.';
        if(i == (N - 1)) return 1 + getRed(j + 1, N, S);

        if((i > 0) && (k < (N - 1)) && (S[i - 1][k + 1] == 'R')) st.push(make_pair(i - 1, k + 1));
        if((i > 0) && (S[i - 1][k] == 'R')) st.push(make_pair(i - 1, k));
        if((k < (N - 1)) && (S[i][k + 1] == 'R')) st.push(make_pair(i, k + 1));
        if((k > 0) && (S[i][k - 1] == 'R')) st.push(make_pair(i, k - 1));
        if((i < (N - 1)) && (S[i + 1][k] == 'R')) st.push(make_pair(i + 1, k));
        if((i < (N - 1)) && (k > 0) && (S[i + 1][k - 1] == 'R')) st.push(make_pair(i + 1, k - 1));
    }
    return getRed(i + 1, N, S);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T, N;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        cin >> N;
        vector<string> board(N);
        for(int i = 0; i < N; i++) cin >> board[i];
        int B = 0, R = 0, Bl = 0, Rl = 0;
        string y = "Nobody wins";

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == 'B') B++;
                if(board[i][j] == 'R') R++;
            }
        }

        Bl = getBlue(0, N, board);
        Rl = getRed(0, N, board);

        if(abs(R - B) > 1) y = "Impossible";
        else if((Bl + Rl) > 1) y = "Impossible";
        else if((Bl == 1) && (B < R)) y = "Impossible";
        else if((Rl == 1) && (R < B)) y = "Impossible";
        else if(Bl == 1) y = "Blue wins";
        else if(Rl == 1) y = "Red wins";
        // cout << "Case #" << x << ": " << y << " " << B << " " << R << " " << Bl << " " << Rl << endl;
        cout << "Case #" << x << ": " << y << endl;
    }

    return 0;
}