#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,mx,l,ans,a[2010];
int lcm(int x,int y)
{
	return x*y/__gcd(x,y);
}
int ck(int x)
{
	int l=1,cnt=0;
	for(int i=1;i<=n;i++)
	if(x%a[i]==0)
	{
		l=lcm(l,a[i]);
		cnt++;
	}
	if(l==x) return cnt;
	else return 0;
}

void solve()
{
	cin>>n;
	mx=0;
	l=1;
	map<int,int>mp;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]),mp[a[i]]=1;
	for(int i=1;i<=n;i++)
	{
		l=lcm(l,a[i]);
		if(l>mx)
		{
			cout<<n<<"\n";
			return ;
		}
	}
	ans=0;
	for(int i=1;i*i<=mx;i++) 
	if(mx%i==0) 
	{
		if(!mp.count(i)) ans=max(ans,ck(i));
		if(!mp.count(mx/i)) ans=max(ans,ck(mx/i));
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
