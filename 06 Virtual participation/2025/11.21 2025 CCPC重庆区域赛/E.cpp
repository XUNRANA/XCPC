#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int  > > edge(n+1);
    while(m--){
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    if(n==1){
        cout<<a[1]<<endl;
        return ;
    }
    vector<int > odd;
    vector<int > even;
    for(int i=1;i<=n;i++){
        if(edge[i].size()>=2){
            even.push_back(a[i]);
        }else{
            odd.push_back(a[i]);
        }
    }
    if(!odd.empty())
        sort(odd.begin(),odd.end());
    if(!even.empty())
        sort(even.begin(),even.end());
    int oddSz=odd.size();
    int evenSz=even.size();
    int ans=0;
    if(!even.empty()){
        ans=even[evenSz-1];
    }
    if(oddSz>=2){
        ans=max(ans,odd[oddSz-2]);
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
} 
