#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,p[100010],q[100010];
int q2[100010];
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];
    
    q2[0]=1;
    for(int i=1;i<=n;i++) q2[i]=q2[i-1]*2%P;
    
    int i1=0,i2=0;
    for(int i=0;i<n;i++)
    {
        if(p[i]>p[i1]) i1=i;
        if(q[i]>q[i2]) i2=i;
        array<int,2>a={p[i1],q[i-i1]};
        array<int,2>b={q[i2],p[i-i2]};
        array<int,2>c=max(a,b);
        cout<<(q2[c[0]]+q2[c[1]])%P<<" ";
    }
    cout<<"\n";
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