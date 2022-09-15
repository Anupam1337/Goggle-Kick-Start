#include<bits/stdc++.h>
using namespace std;

string add(string a, string b) {
    while(a.size() > b.size()) b = '0' + b;
    while(b.size() > a.size()) a = '0' + a;
    int n = a.size() - 1;
    string ans = "";

    int c = 0;
    while(n >= 0) {
        int s = c;
        s +=  (a[n] - '0') + (b[n] - '0');

        ans = (char)((s%10) + '0') + ans;
        c = s/10;
        n--;
    }

    if(c != 0) ans = '1' + ans;

    return ans;
}

string subtract(string a, string b) {
    while(a.size() > b.size()) b = '0' + b;
    while(b.size() > a.size()) a = '0' + a;

    int n = a.size() - 1;
    string ans = "";

    int c = 0;
    while(n >= 0) {
        int s1 = (a[n] - '0');
        int s2 = (b[n] - '0');

        if((s1 >= c) && ((s1 - c) >= s2)) {
            ans = char((s1 - s2 - c) + '0') + ans;
            c = 0;
        } else {
            s1 += 10;
            ans = char((s1 - s2 - c) + '0') + ans;
            c = 1;
        }
        n--;
    }
    while((ans.size() > 0) && (ans[0] == '0')) {
        ans = ans.substr(1, ans.size());
    }

    if(ans == "0") return "";
    return ans;
}

string divide_by_2(string S) {
    string ans = "";
    int c = 0, i = 0;
    if(S[0] == '1') {
        c = 10;
        i = 1;
    }
    for(; i < S.size(); i++) {
        int n = (S[i] - '0');
        if(c > 0) n += c;
        if((n % 2) == 1) c = 10;
        else c = 0;

        n /= 2;
        ans += (n + '0');
    }
    return ans;
}

string multiply_by_2(string S) {
    string ans = "";
    if(S[0] > '4') ans = "1";
    for(int i = 0; i < S.size(); i++) {
        int n = ((S[i] - '0') * 2) % 10;
        if(i != (S.size() - 1))
            if(S[i + 1] > '4') n++; 
        ans += (n + '0');
    }
    return ans;
}

string to_bitset(string S) {
    string ans = "";
    while(S.size()) {
        int n = S.size();
        if((S.back() - '0') % 2) ans = '1' + ans;
        else ans = '0' + ans;
        S = divide_by_2(S);
    }

    return ans;
}

bool isGreater(string p, string q) {
    int n1 = p.length(), n2 = q.length();
    if(n1 == n2) {
        for(int i = 0; i < n1; i++) {
            if(p[i] == q[i]) continue;
            else return (p[i] > q[i]);
        }
    }

    return (n1 > n2);
}

int main() {
    int T;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        int id;
        string n, p = "1", q = "1";
        cin >> id;
        if(id == 1) {
            cin >> n;
            n = to_bitset(n);
            for(int i = 1; i < n.size(); i++) {
                if(n[i] == '1') p = add(p, q);
                else q = add(q, p);
            }
            cout << "Case #" << x << ": " << p << " " << q << endl;
        } else {
            cin >> p >> q;

            n = "0";
            string i = "1";

            while((p.size() > 0) && (q.size() > 0)) {
                if(isGreater(q, p)) {
                    q = subtract(q, p);
                } else {
                    p = subtract(p, q);
                    n = add(n, i);
                }

                i = multiply_by_2(i);
            }

            cout << "Case #" << x << ": " << n << endl;
        }
    }
    return 0;
}
