#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
void solve()
{
	int n,k,t,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mp[t%k]++;
	}
	for(auto i:mp) 
	{
        if(!i.first) ans+=i.second;
        else 
        {
            if(k&1)
            {
                if(i.first<=k/2) ans+=min(i.second,mp[k-i.first]);
            }
            else 
            {
                if(i.first<k/2) ans+=min(i.second,mp[k-i.first]);
                else if(i.first==k/2) ans+=i.second/2;
            }
        }
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

