#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,ans;
void solve()
{
    cin>>n>>m>>k;
    map<pair<int,int>,int>mp;
    for(int i=1;i<=k;i++)
    {
        cin>>x>>y;
        if(mp[make_pair(x+1,y)]==0) ans++;
        if(mp[make_pair(x-1,y)]==0) ans++;
        if(mp[make_pair(x,y-1)]==0) ans++;
        if(mp[make_pair(x,y+1)]==0) ans++;
        mp[make_pair(x,y)]=1;
    }
    cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
    while(T--) solve();
}
