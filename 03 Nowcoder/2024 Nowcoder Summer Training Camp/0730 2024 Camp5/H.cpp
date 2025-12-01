#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int > > edges(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int > vis(n+1,0);
    int ans=0;
    function<void (int ,int ) > dfs=[&](int k,int count){
        ans=max(ans,count);
        vector<int > cnt;
        
                
                for(auto st:edges[k]){
                    if(vis[st]==0){
                        vis[st]=1;
                        cnt.push_back(st);
                    }
                }
        
        for(auto t:cnt)
                dfs(t,count+1);
        
        
                for(auto st:cnt){
                    vis[st]=0;
                }
    
    
    };
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(i,1);
        vis[i]=0;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
