#include <bits/stdc++.h>
using namespace std;
#define int long long


int a[300010];
int c[300010];
void solve()
{
    int n,l;
    cin>>n>>l;

    a[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        a[i]=(a[i-1]+a[i])%l;
    }
    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++) c[a[i]]++;
    
    if(l%3) cout<<"0\n";
    else
    {
        int dd=l/3;
        int ans=0;
        for(int i=0;i<l;i++)
        {

            ans+=c[i]*c[(i+dd)%l]*c[(i+2*dd)%l];
        }
        cout<<ans/3<<"\n";
    }
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