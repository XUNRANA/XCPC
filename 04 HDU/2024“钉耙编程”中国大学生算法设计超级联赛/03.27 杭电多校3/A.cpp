#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int f[1000010];
int g[1000010];
int n;
void solve() 
{
    cin>>n;
    f[1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            f[j+1]+=f[i];
            f[j+1]%=P;
            g[j]+=f[i];
            g[j]%=P;
        }
    }
    for(int i=1;i<=n;i++) cout<<g[i]<<" ";
    cout<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}