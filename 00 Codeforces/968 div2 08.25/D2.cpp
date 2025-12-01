#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,m,l,t,u[N],v[N],mu,mv,mx,fu,fv,d[N],fa[N];
int get(int x,int y)
{
	return (x+y)*(y-x+1)/2;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void solve()
{
	cin>>n>>m;
	mu=mv=mx=0;
	for(int j=1;j<=n;j++)
	{
		cin>>l;
		vector<int>a(l+10);
		for(int i=1;i<=l;i++)
		{
			cin>>t;
			if(t>=l+10) continue;
			a[t]=1;
		}
		u[j]=v[j]=-1;
		for(int i=0;i<l+10;i++)
		{
			if(!a[i])
			{
				if(u[j]==-1) u[j]=i;
				else 
				{
					v[j]=i;
					break;
				}
			}
		}
		mu=max(mu,u[j]);
		mv=max(mv,v[j]);
	}
	
	for(int i=0;i<=mv;i++) fa[i]=i,d[i]=0;
	
	for(int i=1;i<=n;i++)
	{
//		cout<<"u&v:"<<u[i]<<" "<<v[i]<<"\n";
		fu=find(u[i]);
		fv=find(v[i]);
		if(fv>fu) fa[fu]=fv;
		else fa[fv]=fu;
		d[u[i]]++;
		
	}
	for(int i=0;i<=mv;i++) if(d[i]>=2) mx=max(mx,find(i));
	
	int ans=0;
	if(m<=mv)
	{
//		for(int i=0;i<=mv;i++) cout<<find(i)<<" ";
//		cout<<"\n";
		for(int i=0;i<=m;i++)
		{
			ans+=max({i,find(i),mu,mx});
//			cout<<i<<" "<<mu<<" "<<max({i,find(i),mu})<<"\n";
		}
	}
	else 
	{
//		for(int i=1;i<=mv;i++) cout<<find(i)<<" ";
//		cout<<"\n";
		ans=get(mv+1,m);
		for(int i=0;i<=mv;i++)
		{
//			cout<<max({i,find(i),mu,mx})<<"\n";
			ans+=max({i,find(i),mu,mx});
//			cout<<i<<" "<<mu<<" "<<max({i,find(i),mu})<<"\n";
		}
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
