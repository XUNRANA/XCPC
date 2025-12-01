#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

const int p=998244353;

void solve(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    priority_queue<int ,vector<int > ,greater<int > > quemin;
    quemin.push(a[1]);
    for(int i=2;i<=n;i++){
        int t=quemin.top();
        while(a[i]>t){
            quemin.pop();
            a[i]--;
            t++;
            quemin.push(t);
            t=quemin.top();
        }
        quemin.push(a[i]);
    }
    ll ans=1;
    while(!quemin.empty()){
        ll t=quemin.top();
        quemin.pop();
        ans=ans*t%p;
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
