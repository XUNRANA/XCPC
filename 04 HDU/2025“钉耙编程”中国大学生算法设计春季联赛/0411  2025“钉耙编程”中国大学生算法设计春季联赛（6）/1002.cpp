#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,x;
int a[N];
int d[N];
int p[N];
int s[N];
int f[N][20];
int query(int l,int r)
{
    int le=log2(r-l+1);
    return max(f[l][le],f[r-(1<<le)+1][le]);
}
int que(int l,int r)
{
    int res=0;
    res+=p[l-1];
    res+=s[r+1];
    int mx=query(l,r);
    if(l-1>=1) res+=abs(mx-a[l-1]);
    if(r+1<=n) res+=abs(mx-a[r+1]);
    return res;
}
void solve()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i],f[i][0]=a[i];
    for(int j=1;j<=20;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    int sum=0;
    for(int i=2;i<=n;i++) d[i]=abs(a[i]-a[i-1]),sum+=d[i];
    if(sum<=x)
    {
        cout<<"0\n";
        return ;
    }
    for(int i=2;i<=n;i++) p[i]=p[i-1]+d[i];
    s[n]=s[n+1]=0;
    for(int i=n-1;i>=1;i--) s[i]=s[i+1]+d[i+1];
    
    int ans=n;
    for(int i=1,j=1;j<=n;j++)
    {
        while(i<=n&&que(i,j)<=x)
        {
            ans=min(ans,j-i+1);
            i++;
        } 
    }
    cout<<ans<<"\n";
    // for(int i=1;i<=n;i++)
    // {
    //     int l=i,r=n;
    //     while(l<=r)
    //     {
    //         int m=l+r>>1;
    //         if(que(i,m)<=x) r=m-1;
    //         else l=m+1;
    //     }
    //     if(i<=l&&l<=n&&que(i,l)<=x) ans=min(ans,l-i+1);
    // }
    // cout<<ans<<"\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}