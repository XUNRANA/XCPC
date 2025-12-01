#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]){
            cnt++;
        }
    }
    ll ans=0;
    ans+=(cnt+1)/2;
    for(int i=1;i<=n;i++){
        if(a[i]>b[i]){
            ans++;
        }
    }
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
