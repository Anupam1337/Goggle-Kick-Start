#include<bits/stdc++.h>
using namespace std;

struct node{
    char st[10];
}a[80010];

struct edge{
    int e,w;
}dui[3010];

struct query{
    int lo,de;
    int index;
}b[200];

int res[200],dist[80010];

map<string,int> co; 

int n,nn,m,S,fir[80010],lst[80010],nxt[3010];

bool cmp(query a1,query a2){
    return a1.lo<a2.lo;
}

queue<int> q;
bool vis[80010];

void SPFA(int sta){
    while(!q.empty()) q.pop();

    memset(vis, 0, sizeof(vis));

    for(int i = 1; i <= nn; i++) dist[i]=-1;
    dist[sta] = 0; q.push(sta);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        vis[tmp] = false;
        
        for(int i = fir[tmp]; i != -1; i = nxt[i]){
            int e = dui[i].e, w = dui[i].w;
            if((dist[e] == -1) || ((dist[tmp] + w) < dist[e])){
                dist[e] = dist[tmp] + w;
                if(!vis[e]) {
                    vis[e] = true;
                    q.push(e);
                }
            }
        }
    }
}

int main() {
    int i, j, T, x;
    cin >> T;
    for(int x = 1; x <= T; x++) {
        cin >> n;
        co.clear();
        nn=0;
        
        for(int i = 1; i <= n; i++) {
            cin >> a[i].st;
            if(co[a[i].st] == 0) co[a[i].st] = ++nn;
        }

        cin >> m;

        memset(fir, -1, sizeof(fir));
        memset(lst, -1, sizeof(fir));
        memset(nxt, -1, sizeof(fir));
        
        for(int i = 1; i <= m; i++) {
            int s,e,w;
            cin >> s >> e >> w;
            
            s = co[a[s].st];
            e = co[a[e].st];
            
            dui[i].e = e;
            dui[i].w = w;
            
            if(fir[s] == -1){
                fir[s] = i;
                lst[s] = i;
            } else {
                nxt[lst[s]] = i;
                lst[s] = i;
            }
        }
        
        cin >> S;
        for(int i = 1; i <= S; i++) {
            cin >> b[i].lo >> b[i].de;

            b[i].lo = co[a[b[i].lo].st];
            b[i].de = co[a[b[i].de].st];
            b[i].index = i;
        }

        sort(b + 1, b + S + 1, cmp);

        for(int i = 1; i <= S; i++) {
            int lo = b[i].lo, de = b[i].de, index = b[i].index;
            if((i == 1) || (lo != b[i-1].lo)){
                SPFA(lo);
            }
            res[index] = dist[de];
        }

        cout << "Case #" << x << ":\n";
        for(int y: res) cout << y << endl;
    }
    return 0;
}