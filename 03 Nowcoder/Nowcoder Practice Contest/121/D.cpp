#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,x,y,z,ans,cur;
ll gcd(ll x,ll y)
{
	return y==0? x:gcd(y,x%y);
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		vector<tuple<ll,ll,ll>>v;
		z=gcd(x,y);
		ans=x*y/(z*z);
		v.push_back(make_tuple(1ll,x,y));
		v.push_back(make_tuple(1ll,x,y));
		for(ll i=1;i*2<=ans;i*=2)
		{
			v.push_back(make_tuple(2ll,z*i,z*i));
			v.push_back(make_tuple(2ll,z*i,z*i));
		}
		cur=0;
		for(ll i=0;(1ll<<i)<=ans;i++)
		{
			if((ans>>i)&1)
			{
				if(cur) v.push_back(make_tuple(2ll,cur,(1ll<<i)*z));
				cur+=(1ll<<i)*z;
			}
		}
		cout<<v.size()<<'\n';
		for(auto [i,j,k]:v) cout<<i<<' '<<j<<' '<<k<<'\n';
	}
} 