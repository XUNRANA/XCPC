#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,m,a,b,ans,sum,l,r;
void solve()
{
	cin>>n>>k>>m>>a>>b;
	if(k==1)
	{
		if(n%m==0) cout<<"0\n";
		else cout<<"-1\n";
		return ;
	}
	if(n%m==0) 
	{
		cout<<"0\n";
		return ;
	}
	ans=0;
	map<int,int>mp;
	while(n)
	{
		mp[n]=ans;
		n/=k;
		ans+=b;
	}
	for(auto i:mp)
	{
		l=r=i.first%m;
		sum=i.second;
		if(l%m==0)
		{
			ans=min(ans,sum);
			continue;
		}
		while(1)
		{
			sum+=a;
			if(sum>=ans) break;
			l=l*k;
			r=r*k+k-1;
			if(r/m>l/m||l%m==0||r%m==0)
			{
				ans=min(ans,sum);
				break;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T=1;
	cin>>T;
	while(T--) solve();
}
