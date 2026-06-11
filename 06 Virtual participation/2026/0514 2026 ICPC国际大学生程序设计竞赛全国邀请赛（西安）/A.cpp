#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000010];
int c[1000010];
void solve()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n!=0) 
    {
        cout<<"-1\n";
        return ;
    }


    for(int i=1;i<n;i++)
    {
        int d=sum/n-a[i];
        if(d>=0)
        {
            a[i]+=d;
            a[i+1]-=d;
            c[i]=d;
        }
        else 
        {
            cout<<"-1\n";
            return ;
        }
    }
    int ans=c[1];
    for(int i=3;i<n;i+=2)
    {
        if(c[i-2]<c[i])
        {
            ans+=c[i]-c[i-2];
        }
    }
    ans+=c[2];
    for(int i=4;i<n;i+=2)
    {
        if(c[i-2]<c[i])
        {
            ans+=c[i]-c[i-2];
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}