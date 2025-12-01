#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}

int jc[100010];
int inv[100010];
void init()
{
    jc[0]=inv[0]=1;
    for(int i=1;i<=1e5;i++) jc[i]=jc[i-1]*i%P;
    for(int i=1;i<=1e5;i++) inv[i]=ksm(jc[i],P-2);
}
int C(int a,int b)
{
    return jc[a]*inv[b]%P*inv[a-b]%P;
}
int n,L,R,in[100010];
void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        in[u]++;
        in[v]++;
    }
    cin>>L>>R;
    int ans=0;
    if(L==1) 
    {
        ans+=n+n-1;
        L=3;
    }
    else if(L==2)
    {
        ans+=n-1;
        L=3;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(in[i]>=L-1)
        {
            for(int j=L-1;j<=R-1;j++)
            {
                if(j>in[i]) break;
                ans+=C(in[i],j);
                ans%=P;
            }
        }
    }
    cout<<ans<<"\n";
}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}