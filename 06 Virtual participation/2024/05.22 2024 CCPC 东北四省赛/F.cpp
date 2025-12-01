#include <bits/stdc++.h>
using namespace std;
#define int long long
int pri[50];
int cnt[50];
int idx[50];
int c;
int ans;
int p,x,k;
//第i个质数，选了j个
void dfs(__int128 s,int j)
{
    for(int i=j;i<c;i++)
    {
        if(s*pri[i]<=x&&idx[i]<cnt[i])
        {
            ans++;
            idx[i]++;
            dfs(s*pri[i],i);
            idx[i]--;
        }
    }
}
void solve()
{
    cin>>p>>x>>k;
    unordered_map<int,int>mp;
    for(int i=2;i*i<=p;i++)
    {
        while(p%i==0)
        {
            mp[i]++;
            p/=i;
        }
    }
    if(p!=1) mp[p]++;
    
    for(int i=2;i*i<=k;i++)
    {
        while(k%i==0)
        {
            mp[i]+=64;
            k/=i;
        }
    }
    if(k!=1) mp[k]+=64;

    
    for(auto i:mp) 
    {
        pri[c]=i.first;
        cnt[c]=i.second;
        c++;
    }
    // for(int i=0;i<c;i++) cout<<pri[i]<<" "<<cnt[i]<<"??\n";
    ans=1;
    dfs(1,0);
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
