#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int g=0;
    for(int i=1;i<n;i++) g=__gcd(g,a[i+1]-a[i]);
    
    if(g==0) 
    {
        cout<<"infinite\n";
        return ;
    }
    
    if(a[1]%g==0) cout<<g<<" "<<1<<"\n";
    else
    {
        int x=a[1]%g;
        cout<<g<<" "<<g/__gcd(x,g)<<"\n";
    }
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}