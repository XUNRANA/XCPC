#include <bits/stdc++.h>
using namespace std;
#define int long long
int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}
int a[100010];
int b[100010];

int a1[100010];
int b1[100010];
int c[100010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) c[i]=lcm(a[i],b[i]);

    
    a1[1]=c[1];
    for(int i=2;i<=n;i++) a1[i]=__gcd(a1[i-1],c[i]);

    b1[n]=c[n];
    for(int i=n-1;i>=1;i--) b1[i]=__gcd(b1[i+1],c[i]);
    for(int i=1;i<=n;i++) if(a[i]!=a1[i]||b[i]!=b1[i])
    {
        cout<<"NO\n";
        return ;
    }
    cout<<"YES\n";

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
