#include <bits/stdc++.h>
using namespace std;
#define int long long
//n! 含多少个质数p
int fx(int n,int p)
{
    int ans=0;
    while(n)
    {
        n/=p;
        ans+=n;
    }
    return ans;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    for(int i=2;i*i<=k;i++)
    {
        while(k%i==0)
        {
            mp[i]++;
            k/=i;
        }
    }
    if(k!=1) mp[k]++;
    int res=1e18;
    for(auto i:mp) 
    {
        int x=i.first;
        int y=i.second;
        res=min(res,fx(n,x)/y);
        // cout<<i.first<<" "<<i.second<<"\n";
    }
    if(res==1e18) res=-1;
    cout<<res<<"\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
