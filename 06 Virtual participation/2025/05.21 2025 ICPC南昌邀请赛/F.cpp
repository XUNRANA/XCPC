#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
5.125
7.90625

4.125
6.28125

3.125
4.65625

2.125
3.03125

1.125
1.40625

0.125
-0.21875

*/
double r[200010];
double c[200010];
void solve()
{
    int n,k;
    double p,L,R;
    cin>>n>>k;
    cin>>r[0]>>c[0]>>p>>L>>R;
    for(int i=1;i<=n;i++) r[i]=L;
    while(k--)
    {
        int x;
        double y;
        cin>>x>>y;
        r[x]=y;
    }
    for(int i=1;i<=n;i++) c[i]=p*c[i-1]+(1.0-p)*r[i-1];
    double ans=0;
    for(int i=1;i<=n;i++) ans+=c[i]-r[i];
    printf("%.10f\n",ans);
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
