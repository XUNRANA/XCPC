#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100010];
void solve()
{
    int n,k,x,ans=0,mi=1e9;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,vector<int>>mp;
    for(int i=1;i<=n;i++) mp[i%k].push_back(a[i]);
    
    for(int i=0;i<k;i++) 
    {
        int mx=0,s=0;
        for(auto j:mp[i]) mx=max(mx,j),s+=j;
        ans+=mx*mp[i].size()-s;
    }
    
    if(ans>x) cout<<"-1\n";
    else 
    {
        int mx=0;
        for(int i=0;i<k;i++)
        {
            int mx1=0;
            for(auto j:mp[i]) mx1=max(mx1,j);
            mx=max(mx,mx1+(x-ans)/(int)mp[i].size());
        }
        cout<<mx<<"\n";
    }
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
