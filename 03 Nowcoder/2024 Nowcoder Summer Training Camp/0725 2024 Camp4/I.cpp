#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int ,int > > cnt;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        cnt.emplace_back(v,u);
    }
    sort(cnt.begin(),cnt.end());
    cnt.emplace_back(0,0);
    // for(int i=0;i<=m;i++){
    //     cout<<cnt[i].first<<" "<<cnt[i].second<<endl;
    // }
    int l=0,r=0;
    vector<int > res(n+1,0);
    for(int i=m-1;i>=0;i--){
        if(cnt[i].first==cnt[i+1].first){
            if(cnt[i].second==l-1){
                l--;
            }
        }else if(cnt[i].first!=cnt[i+1].first){
            // ans+=(r-l+1)*(r-l)/2;
            res[cnt[i+1].first]=l;
            if(cnt[i].second==cnt[i].first-1){
                r=cnt[i].first;
                l=cnt[i].second;
            }else{
                r=cnt[i].first;
                l=cnt[i].first;
            }
        }
    }
    res[cnt[0].first]=l;
    // ans+=(r-l+1)*(r-l)/2;
    int k=0;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(res[i]==0){
            res[i]=i;
        }
        k=max(k,res[i]);
        ans+=i-k+1;
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
