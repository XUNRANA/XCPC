#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,a[500010],s=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],ans+=a[i];
    sort(a+1,a+1+n);
    if(a[1]>=0)
    {
        cout<<ans<<"\n";
        return ;
    }
    s=a[1];
    for(int i=2;i<=n;i++)
    {
        //cout<<s<<"\n";
        a[i]+=s;
        if(a[i]>=0) 
        {
            ans=a[i];
            for(int j=i+1;j<=n;j++) ans+=a[j]+s; 
            cout<<ans<<"\n";
            return ;
        }
        s+=a[i];
    }
    cout<<a[n]<<"\n";
}
signed main()
{
    int t;
    cin>>t;
    while(t--) solve();
}