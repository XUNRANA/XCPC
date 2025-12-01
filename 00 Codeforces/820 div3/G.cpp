#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
#define P1 1331
int p[510];
int h[510];
int f[510];//最小操作
int g[510];//方案数
int get(int l,int r)
{
    return (h[r]-h[l-1]*p[r-l+1]%P+P)%P;
}
void solve() 
{
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    s=" "+s;
    t=" "+t;
    p[0]=1;
    h[0]=0;
    for(int i=1;i<=n;i++)
    {
        h[i]=(h[i-1]*P1%P+s[i]-'a'+1)%P;
        p[i]=p[i-1]*P1%P;
    }
    int ht=0;
    for(int i=1;i<=m;i++) ht=(ht*P1%P+t[i]-'a'+1)%P;
    f[0]=0;//最小操作
    g[0]=1;//方案数
    for(int i=1;i<=n;i++)
    {
        if(i<m) 
        {
            f[i]=0;
            g[i]=1;
        }
        else if(get(i-m+1,i)!=ht)
        {
            f[i]=f[i-1];
            g[i]=g[i-1];
        }
        else
        {
            f[i]=1e9;
            for(int j=max(1ll,i-2*m+2);j<=i-m+1;j++)
            if(get(j,j+m-1)==ht) f[i]=min(f[i],f[j-1]+1);

            g[i]=0;
            for(int j=max(1ll,i-2*m+2);j<=i-m+1;j++)
            if(get(j,j+m-1)==ht&&f[j-1]+1==f[i]) g[i]=(g[i]+g[j-1])%P;
        }
    }
    cout<<f[n]<<" "<<g[n]<<"\n";
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