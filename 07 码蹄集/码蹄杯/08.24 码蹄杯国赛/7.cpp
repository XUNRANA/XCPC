#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int f[1000010];
//08: 41: 23
void init()
{
    f[1]=f[2]=1;
    for(int i=3;i<=1e6;i++) f[i]=f[i-1]+f[i-2];

    // for(int i=1;i<=30;i++) cout<<f[i]<<"\n";
}

int fxg(int x)
{
    int ans=0;
    for(int i=1;i<=x;i++) if(x%i==0) ans++;
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++)
    {
        int g1=__gcd(i,j);
        g1=__gcd(g1,k);


        int g2=__gcd(f[i],f[j]);
        g2=__gcd(g2,f[k]);

        if(g2!=1)
        {
            cout<<i<<" "<<f[i]<<"\n";
            cout<<j<<" "<<f[j]<<"\n";
            cout<<k<<" "<<f[k]<<"\n";

            cout<<g2<<" "<<min(min(f[i],f[j]),f[k])<<"?????\n";
        }

        // g1=fxg(g1);

        // if(g2!=1) cout<<g1<<" "<<g2<<"\n";
        
        // ans+=g1*g2%P;
    }
    cout<<ans<<"\n";
}
signed main()
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}