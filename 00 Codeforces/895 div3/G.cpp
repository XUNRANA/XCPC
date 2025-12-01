#include <bits/stdc++.h>
using namespace std;
int a[200010];
int s[200010];
int p[200010];
int fx(int l,int r)
{
    int s=1;
    for(int i=l;i<=r;i++) s*=a[i];
    return s;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],p[i]=p[i-1]+a[i];
    s[n+1]=0;
    for(int i=n;i>=1;i--) s[i]=s[i+1]+a[i];
    int l=1,r=n;
    while(a[l]==1) l++;
    while(a[r]==1) r--;
    if(l>=r) cout<<1<<" "<<1<<"\n";
    else 
    {
        __int128 s1=1;
        vector<int>idx;
        for(int i=l;i<=r;i++)
        {
            if(a[i]!=1) idx.push_back(i);
            s1=s1*a[i];
            if(s1>=1e9)
            {
                cout<<l<<" "<<r<<"\n";
                return ;
            }
        }
        int ans=0;
        for(int i=0;i<idx.size();i++)
        {
            for(int j=i;j<idx.size();j++)
            {
                ans=max(ans,fx(idx[i],idx[j])+p[idx[i]-1]+s[idx[j]+1]);
            }
        }
        // cout<<ans<<"!!!\n";
        for(int i=0;i<idx.size();i++)
        {
            for(int j=i;j<idx.size();j++)
            {
                if(fx(idx[i],idx[j])+p[idx[i]-1]+s[idx[j]+1]==ans)
                {
                    cout<<idx[i]<<" "<<idx[j]<<"\n";
                    return ;
                }
            }
        }
    }
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