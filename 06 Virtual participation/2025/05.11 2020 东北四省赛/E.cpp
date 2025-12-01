#include <bits/stdc++.h>
using namespace std;
#define int long long
int C[100][100];
void init()
{
    for(int i=0;i<=70;i++)
    {
        for(int j=0;j<=i;j++) 
        if(!j) C[i][j]=1;
        else 
        {
            C[i][j]=min(C[i-1][j-1]+C[i-1][j],1000000000ll);

        }
    }
}
int n,k;
int ans[100][70];
void solve() 
{
    cin>>n>>k;
    if(k%2==0||C[n][k]<n) cout<<"-1\n";
    else
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans[i][j]=0;
        for(int i=1;i<=k+1;i++) for(int j=1;j<=k+1;j++) ans[i][j]=1;
        for(int i=1;i<=k+1;i++) ans[i][k-i+2]=0;

        for(int i=k+2;i<=n;i++) 
        {
            for(int j=1;j<k;j++) ans[i][j]=1;
            ans[i][i]=1;
        }

        for(int i=1;i<=n;i++)
        {
            int res=0;
            for(int j=1;j<=n;j++) if(ans[i][j]) res+=1ll<<(j-1);
            cout<<res<<" ";
        }
        cout<<"\n";
    }
}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}