#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010];
void solve () 
{
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    s=" "+s;
    int idx=0;
    for(int i=1;i<=n;i++)
    if(s[i]=='0')
    {
        if(!idx) idx=i;
        s[i]='1';
        a[i]=-2e11;
    }

    int s1=0,mx=-1e18;
    for(int i=1;i<=n;i++)
    {
        s1+=a[i];
        mx=max(mx,s1);
        if(s1<0) s1=0;
    }

    if(mx>k||(!idx&&mx!=k)) cout<<"No\n";
    else
    {
        cout<<"Yes\n";
        
        int mx1=-1e18,mx2=-1e18;
        int ss1=0,ss2=0;
        for(int j=idx-1;j>=1;j--)
        {
            ss1+=a[j];
            mx1=max(mx1,ss1);
        }
        if(idx==1) mx1=0;
        
        for(int j=idx+1;j<=n;j++)
        {
            ss2+=a[j];
            mx2=max(mx2,ss2);
        }
        if(idx==n) mx2=0;

        a[idx]=min({k,k-mx1,k-mx2,k-mx1-mx2});
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}