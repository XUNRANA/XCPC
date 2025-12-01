#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const long long INF = 0x3f3f3f3f3f3f3f3f;

const int maxn = 510000;
const int maxlog = 20;
vector<int> G[maxn];
int anc[maxn][maxlog], dep[maxn];
void dfs(int x, int fa, int d) {
    anc[x][0] = fa;
    dep[x] = d;
    for (auto y : G[x]) if (y != fa)
    dfs(y, x, d + 1);
}
void preprocess(int n) { //点的编号从 1 开始
    for (int j = 1; j < maxlog; ++j)
        for (int i = 0; i <= n; ++i)
            anc[i][j] = 0;
    dfs(1, 0, 0);
    for (int j = 1; j < maxlog; ++j)
        for (int i = 1; i <= n; ++i)
            anc[i][j] = anc[anc[i][j- 1]][j- 1];
}
//返回结点 x 向上走 d 步到达的结点
int moveup(int x, int d) {
    for (int i = 0; d >> i; ++i)
        if (d >> i & 1)
            x = anc[x][i];
    return x;
}
int lca(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    x = moveup(x, dep[x]- dep[y]);
    if (x == y)
        return x;
    for (int i = maxlog- 1; i >= 0;--i)
        if (anc[x][i] != anc[y][i])
            x = anc[x][i], y = anc[y][i];
    return anc[x][0];
}
int dist(int x, int y) { //返回结点 x 和 y 之间的距离
    return dep[x] + dep[y]- 2 * dep[lca(x, y)];
}
int move(int x, int y, int d) { //返回从结点 x 向结点 y 走 d 步到达的结点
int p = lca(x, y);
int h = dep[x]- dep[p];
if (h >= d)
return moveup(x, d);
else
return moveup(y, dep[x] + dep[y]- d- 2 * dep[p]);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> c(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0,0);
    for (int j = 1; j < maxlog; ++j)
        for (int i = 1; i <= n; ++i)
            anc[i][j] = anc[anc[i][j- 1]][j- 1];

    vector<ll > dp(n+1);
    function<void (int ,int ) > dfsDP=[&](int u,int fath){
        ll min1=INF,min2=INF;
        for(auto v:G[u]){
            if(v==fath){
                continue;
            }
            dfsDP(v,u);
            if(dp[v]<=min1){
                min2=min1;
                min1=dp[v];
            }else if(dp[v]<=min2){
                min2=dp[v];
            }
        }
        if(min1==INF){
            dp[u]=c[u];
        }else{
            dp[u]=min(c[u],min1+min2);
        }
    };
    dfsDP(1,0);
    
    vector<ll > ans(n+1);
    function<void (int ,int ,ll ) > dfsAns=[&](int u,int fath,ll path){
        ans[u]=path;
        multiset<ll > res;
        for(auto v:G[u]){
            if(v==fath){
                continue;
            }
            res.insert(dp[v]);
        }
        for(auto v:G[u]){
            if(v==fath){
                continue;
            }
            res.extract(dp[v]);
            dfsAns(v,u,path+*res.begin());
            res.insert(dp[v]);
        }
    };

    dfsAns(1,0,0);

    while(m--){
        int x,y;
        cin>>x>>y;
        if(lca(x,y)!=y){
            cout<<-1<<endl;
            continue;
        }
        ll ansFin=ans[x]-ans[y];
        cout<<ansFin<<endl;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
