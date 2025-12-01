#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1)
    {
        cout<<"1\n";
        return ;
    }
    int f1=0,f2=0;
    for(int i=2;i<=n-1;i++)
    {
        if(a[i]<a[1]&&a[i]<a[n]) f1=1;
        else if(a[i]>a[1]&&a[i]>a[n]) f2=1;
    }
    cout<<f1+f2+2<<"\n";
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