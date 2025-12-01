#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,l,r,m,cnt,x,ans,c,f,e,a[200010],b[200010];
bool ck(int x)
{
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x) cnt+=(a[i]-x+b[i]-1)/b[i];
	}
	return cnt<=k;
} 
void solve()
{
	ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	l=0,r=1e9;
	while(l<=r)
	{
		m=l+r>>1;
		if(ck(m)) 
		{
			x=r;
			r=m-1;
		}
		else l=m+1;
	}
	
	cnt=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>q;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x) 
		{
			c=(a[i]-x+b[i]-1)/b[i];
			cnt+=c;
			f=a[i];
			e=a[i]-(c-1)*b[i];
			ans+=(f+e)*c/2;
			q.push({max(0ll,e-b[i]),b[i]});
		}
		else q.push({a[i],b[i]});
	}
	
	while(cnt<k&&!q.empty())
	{
		f=q.top().first;
		e=q.top().second;
		q.pop();
		ans+=f;
		f=max(0ll,f-e);
		if(f) q.push({f,e});
		cnt++;
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
