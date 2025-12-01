#include <bits/stdc++.h>
using namespace std ;
const int MAXN=1e5+7;
const int INF = 0x3f3f3f3f;
typedef long long ll;
#define endl "\n"

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    // int nxt[20][n];
    vector<vector<int > > nxt(20,vector<int > (n));
    // pair<int ,int > res[20][n];
    vector<vector<pair<int ,int > > > res(20,vector<pair<int ,int > > (n));
    for(int i=0;i<n;i++){
        nxt[0][i]=(i+1)%n;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            res[0][i]={0,1};
        }else{
            res[0][i]={1,0};
        }
    }
    auto check=[&](int u){
        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                nxt[i][j]=nxt[i-1][nxt[i-1][j]];
                res[i][j].first=res[i-1][j].first+res[i-1][nxt[i-1][j]].first;
                res[i][j].second=res[i-1][j].second+res[i-1][nxt[i-1][j]].second;
            }
        }
        vector<int > nnxt(n,0),nres(n,0);
        for(int j=0;j<n;j++){
            int now=j,L=0,R=0;
            for(int i=19;i>=0;i--){
                if(L+res[i][now].first<u&&R+res[i][now].second<u){
                    L+=res[i][now].first;
                    R+=res[i][now].second;
                    now=nxt[i][now];
                }
            }
            nres[j]=res[0][now].second;
            nnxt[j]=nxt[0][now];
        }
        for(int j=0;j<n;j++){
            if(nres[j]==1){
                res[0][j]={0,1};
            }else{
                res[0][j]={1,0};
            }
            nxt[0][j]=nnxt[j];
        }
    };
    check(a);
    check(b);
    for(int j=0;j<n;j++){
        cout<<res[0][j].second;
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
