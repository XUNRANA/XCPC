#include<bits/stdc++.h>
#define N 100100
using namespace std;
int t, n, m, x;
vector<int> to[N], va[N];
long long dis[N];
int vis[N]; 
struct Node{
    int p, step;
    long long v;
};
bool operator <(Node a, Node b) {
    return a.v > b.v;
}
priority_queue<Node> q;
queue<int> q2;
long long shortest_path(long long mid){
    memset(dis, -1, sizeof(dis));
    while(!q.empty()) q.pop();
    q.push((Node){1,0,0});
    dis[1] = 0;
    while(!q.empty()) {
        Node st = q.top(); q.pop();
        if(st.p == n) break;
        if(st.v > dis[st.p]) continue;
        for(int i = 0; i < to[st.p].size(); i++) {
            int next = to[st.p][i];
            if(dis[next] > st.v + va[st.p][i] + mid || dis[next] == -1) {
                if(st.step == x-2 && next != n) continue;
                dis[next] = st.v + va[st.p][i] + mid;
                q.push((Node){next, st.step + 1, dis[next]});
            }
        }
    }
    while(!q2.empty()) q2.pop();
    q2.push(1);
    memset(vis, -1, sizeof(vis));
    vis[1] = 0;
    while(!q2.empty()) {
        int st = q2.front(); q2.pop();
        if(st == n){
            return vis[st];
        }
        for(int i = 0; i < to[st].size(); i++) {
            int next = to[st][i];
            if(vis[next] == -1 && dis[st] + va[st][i] + mid == dis[next]) {
                vis[next] = vis[st] + 1;
                q2.push(next);
            }
        }
    }
    return 100000;
}
int main(){
    cin >> t;
    while(t--) {
        cin >> n >> m >> x;
        for(int i = 1; i <= n; i++) {
            to[i].clear();
            va[i].clear();
        }
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            to[a].push_back(b);
            va[a].push_back(c);
        }
        long long l = 0, r = 1e13, mid;
        long long ans = 1e18;
        int sav =0;
        while(l <= r) {
            mid = l + r >> 1;
            int bs = shortest_path(mid);
            if(bs < x) {
                if(dis[n] - mid * bs < ans) sav = bs;
                ans = min(ans, dis[n] - mid * bs);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}