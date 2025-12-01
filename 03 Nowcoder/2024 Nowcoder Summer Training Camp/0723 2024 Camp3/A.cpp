#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    ll h[n+1];
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    if(l==r){
        if(l==n){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        return ;
    }
    ll s=((n-r)+(r-l)-1)/(r-l);
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=min((h[i]-1)/2,s);
    }
    if(sum>=s*l){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
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
