#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s[110];
int fx(int i,int j)
{
    int res=0;
    for(int k=0;k<m;k++)
    {
        int t=s[i][k]-s[j][k];
        if(t<0) t*=-1;
        res+=t;
    }
    return res;
}
void solve() 
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    
    int ans=1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        ans=min(ans,fx(i,j));
    }
    cout<<ans<<"\n";

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}