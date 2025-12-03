#include <bits/stdc++.h>
using namespace std;
int n,k,d;
int h[500010];
int stmx[500010][21],stmi[500010][21];
int f[500010][21];
int Log[500010];
int get(int x)
{
    int cnt=0;
    int mi=1e9+1;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        if(mx==0)
        {
            mx=mi=h[i];
            cnt++;
        }
        else
        {
            mi=min(mi,h[i]);
            mx=max(mx,h[i]);
            if(mx-mi>x)
            {
                cnt++;
                mx=mi=h[i];
            }
        }
    }
    return cnt;
}
int getmx(int l,int r)
{
    int k=Log[r-l+1];
    return max(stmx[l][k],stmx[r-(1<<k)+1][k]);
}
int getmi(int l,int r)
{
    int k=Log[r-l+1];
    return min(stmi[l][k],stmi[r-(1<<k)+1][k]);
}


void solve()
{
    Log[1] = 0;
    for (int i = 2; i < 500010; i++) Log[i] = Log[i >> 1] + 1;

    cin>>n>>k>>d;
    int mi=1e9;
    int mx=1;
    for(int i=1;i<=n;i++) 
    {
        cin>>h[i];
        stmx[i][0]=stmi[i][0]=h[i];
        mi=min(mi,h[i]);
        mx=max(mx,h[i]);
    }
    int l=1,r=mx-mi;
    while(l<=r)
    {
        int m=l+r>>1;
        if(get(m)<=k) r=m-1;
        else l=m+1;
    }
    cout<<l<<"\n";
    cout<<get(d)<<"\n";

    for(int i=1;i<=20;i++) 
    for(int j=1;j+(1<<i)-1<=n;j++)
    {
        stmx[j][i]=max(stmx[j][i-1],stmx[j+(1<<(i-1))][i-1]);
        stmi[j][i]=min(stmi[j][i-1],stmi[j+(1<<(i-1))][i-1]);
    }

    for(int i=1;i<=n;i++)
    {
        l=i+1,r=n;
        while(l<=r)
        {
            int m=l+r>>1;
            if(getmx(i,m)-getmi(i,m)<=d) l=m+1;
            else r=m-1;
        }
        f[i][0]=l;
    }
    f[n+1][0]=n+1;//key

    for(int i=1;i<=20;i++) 
    for(int j=1;j<=n+1;j++)//key
    f[j][i]=f[f[j][i-1]][i-1];


    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int s=i;
        for(int j=0;j<=20;j++) if(k>>j&1) s=f[s][j];
        ans=max(ans,s-i);
    }
    cout<<ans<<"\n";
} 

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
