#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,l,r,mid,n,a[100010];

int check(ll x)
{
	vector<ll>dp;
	for(int i=0,j=1;j<=n;j++)
	{
		if(a[j]-a[i]==x)
		{
			i=j+1;
			dp.push_back(a[j+1]-a[j]);
		}
		else if(a[j]-a[i]>x)
		{
			if(a[j]-a[i+1]==x)
			{
				dp.push_back(a[i+1]-a[i]);
				dp.push_back(a[j+1]-a[j]);
				i=j+1;
			}
			else 
			{
				i=j;
				dp.push_back(a[j]-a[j-1]);
			}
		}
	}
	for(int i=1;i<dp.size();i++) dp[i]+=dp[i-1];
	return dp[dp.size()-1]<=x;
}

void solve()
{
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
	a[n+1]=a[n];
	l=0,r=a[n];
	while(l<=r)
	{
		//cout<<l<<" "<<r<<"\n";
		mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) solve();
}
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,m,i,j,l,r,mid,ql,qr;
void solve()
{
	cin>>n;
	vector<ll> a(n+2),s(n+2),f(n+2),q(n+3);
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	s[n+1]=s[n];
	l=0,r=s[n];
	auto ck=[&](ll lim)
	{
		f[0]=0;
		ql=0,qr=0;
		for(i=1;i<=n+1;i++)
		{
			cout<<ql<<" "<<qr<<"\n";
			while(ql<=qr&&s[i-1]-s[q[ql]]>lim) ql++;
			if(ql>qr) return false;
			f[i]=f[q[ql]]+a[i];
			while(ql<=qr&&f[i]<=f[q[qr]]) --qr;
			q[++qr]=i;
		}
		cout<<"\n\n";
		return f[n+1]<=lim;
	};	
	while(l<r)
	{
		cout<<l<<" "<<r<<"\n";
		mid=l+r>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) solve();
}
*/
