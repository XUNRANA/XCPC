#include <bits/stdc++.h>
using namespace std;
#define int long long
int mx1,mx2,s,t,m,mx11,mx22,in,n,a[100010];
void solve()
{
    mx1=mx2=in=s=0;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]>mx1) in=i,mx1=a[i];
        s+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(i==in) continue;
        mx2=max(mx2,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        t=s-a[i];
        mx11=mx1;
        if(i==in) mx11=mx2;
        if(mx11>t-mx11)
        {
            m=mx11-(t-mx11);
        }
        else
        {
            m=t%2;
        }
        if(a[i]>m) cout<<"1 ";
        else cout<<"0 ";
    }
    cout<<"\n";
}
signed main()
{
    int t1;
    cin>>t1;
    while(t1--) solve();
}