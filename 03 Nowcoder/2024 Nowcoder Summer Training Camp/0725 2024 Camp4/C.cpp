#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int > > cnt(3);
    vector<int > vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[a[i]]==1){
            continue;
        }
        vis[a[i]]=1;
        if(a[i]!=i){
            int t=a[i];
            int count=0;
            while(1){
                t=a[t];
                if(vis[t]==1){
                    break;
                }
                vis[t]=1;
                count++;
            }
            cnt[count%3].push_back(count);
        }
    }
    // cout<<"te"<<endl;
    // for(int i=0;i<3;i++){
    //     for(auto t:cnt[i]){
    //         cout<<t<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"end"<<endl;
    ll ans=0;
    ll k=0;
    for(auto t:cnt[1]){
        if(k>0){
            k--;
            if(t-1>0){
                cnt[2].push_back(t-1);
            }
        }else{
            ans+=(t+2)/3;
            k++;
        }
    }
    ll sum=0;
    for(auto t:cnt[2]){
        sum+=(t+2)/3;
    }
    for(auto t:cnt[0]){
        sum+=(t+2)/3;
    }
    sum=max(sum-k/2,0ll);
    // cout<<ans<<" "<<sum<<endl;
    ans+=sum;
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
