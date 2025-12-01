#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[110];
bool ck()
{
    int mi=1e9;
    int g=0;
    for(int i=1;i<=n;i++) 
    {
        mi=min(mi,a[i]);
        g=__gcd(g,a[i]);
    }
    if(g==mi) return 1;
    return 0;
}
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(ck()) cout<<n-1<<"\n";
    else
    {
        sort(a+1,a+1+n);
        int g=0;
        for(int i=2;i<=n;i++) if(a[i]%a[1]) g=__gcd(g,a[i]);
        int f=0;
        if(a[1]<g) f=1;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        {
            if(a[j]%a[i]==0) continue;
            int t=a[j];
            a[j]%=a[i];
            f|=ck();
            a[j]=t;
        }
        if(f) cout<<n<<"\n";
        else cout<<n+1<<"\n";
    }
  

}

signed main() 
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}