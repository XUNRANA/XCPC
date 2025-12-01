#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e6+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

int fa[MAXN];
int dep[MAXN];
int deep[MAXN];

// int find(int x){
//     while(fa[x]!=x){
//         x=fa[x];
//     }
//     return x;
// }
int find(int x){
    if(x==fa[x]) return x;
    int tmp=find(fa[x]);
    deep[x]+=deep[fa[x]];
    return fa[x]=tmp;
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        fa[i]=i;
        dep[i]=0;
        deep[i]=0;
    }
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        fa[b]=a;
        deep[b]=1;
        find(b);
        dep[find(a)]=max(dep[find(a)],dep[b]+deep[b]);
        cout<<dep[c]<<" ";
    }
    cout<<endl;
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
