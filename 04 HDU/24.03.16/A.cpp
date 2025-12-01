#include <bits/stdc++.h>
using namespace std;
#define p 998244353
#define int long long
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		b/=2;
		a=a*a%p;
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,n1,m,t,s,cnt,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		n1=n;
		map<int,int>mp;
		for(int i=2;i*i<=n;i++) while(n%i==0) mp[i]++,n/=i;
		if(n!=1) mp[n]++;
		if(mp.count(n1)) cout<<(ksm(2,m)-1+p)%p<<"\n";
		else if(n1==1) cout<<"1\n";
		else 
		{
			//for(auto i:mp) cout<<i.first<<" "<<i.second<<"\n";
			//s=cnt=1;
			ans=1;
			for(auto i:mp) 
			{
				ans=ans*(ksm(i.second+1,m)-ksm(i.second,m)+p)%p;
			}
			
			//s=(s+i.second+1)%p,cnt=(cnt+p)%p; 
			//cout<<s<<" "<<cnt<<"\n";
			//cout<<(ksm(s,m)-ksm(s-cnt,m)+p)%p<<"\n";
			cout<<ans<<"\n";
		}
	}
}
