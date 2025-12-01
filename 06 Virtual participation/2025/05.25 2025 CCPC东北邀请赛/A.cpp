#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[100010][22]; 
int g[100010][22]; 
vector<int>idx[1000010];
int queryf(int l,int r)
{
    int k=log2(r-l+1);//求区间长度 
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
int queryg(int l,int r)
{
    int k=log2(r-l+1);//求区间长度 
	return __gcd(g[l][k],g[r-(1<<k)+1][k]);
}
bool ck(int l,int r,int x)
{
    return queryf(l,r)==x&&queryg(l,r)==x;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        idx[x].push_back(i);
        g[i][0]=f[i][0]=x;
    }

    for(int i=1;i<=21;i++) 
    for(int j=1;j+(1<<i)-1<=n;j++)
    {
        f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);//动态规划更新 
        g[j][i]=__gcd(g[j][i-1],g[j+(1<<(i-1))][i-1]);//动态规划更新 
    }

    int ans=0;
    for(int i=1;i<=1e6;i++)
    {
        int p=0;
        for(auto j:idx[i])
        {

            int l1=p+1,r1=j;
            while(l1<=r1)
            {
                int m=l1+r1>>1;
                if(ck(m,j,i)) r1=m-1;
                else l1=m+1;
            }
            int l2=j,r2=n;
            while(l2<=r2)
            {
                int m=l2+r2>>1;
                if(ck(j,m,i)) l2=m+1;
                else r2=m-1;
            }
            l2--;
            ans+=(j-l1+1)*(l2-j+1);
            p=j;
        }
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
    return 0;
}
