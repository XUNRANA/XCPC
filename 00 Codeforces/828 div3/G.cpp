#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int idx[200010];
void solve () 
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        idx[x]=i;
    }
    
    int mi=n-1;
    int mx=0;
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;i++)
    {
        mi=min(mi,idx[i]);
        mx=max(mx,idx[i]);
        mp[{mi,mx}]=i+1;
    }
    idx[n]=n;
    int ans=0;
    for(auto i:mp) 
    {
        int l=i.first.first;
        int r=i.first.second;
        int x=i.second;
        if(r-l+1>2*x) continue;

        int j=idx[x];
        if(j<l) 
        {
            for(j++;j<=l;j++)
            {
                int r1=j+x-1;
                int r2=j+2*x-1;
                r1=max(r1,r);
                r2=min(r2,n-1);
                ans+=max(r2-r1+1,0ll);
            }
        }
        else 
        {
            for(j--;j>=r;j--)
            {
                int l1=j-2*x+1;
                int l2=j-x+1;
                l1=max(l1,0ll);
                l2=min(l2,l);
                ans+=max(l2-l1+1,0ll);
            }
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
    while(T--)
    solve();
}