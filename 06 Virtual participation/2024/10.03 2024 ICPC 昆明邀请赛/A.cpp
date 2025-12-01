#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct node
{
	int s;
	int i;
	vector<int>v;
	int sum;
	int cnt;
}a[400010];
int mx[400010];
int n,m,k,t;
bool cmps(node a1,node a2)
{
	return a1.s>a2.s;
}
bool cmpi(node a1,node a2)
{
	return a1.i<a2.i;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
		a[i].i=i;
		a[i].sum=0;
		a[i].cnt=0;
		a[i].v.clear();
		for(int j=1;j<=m;j++)
		{
			cin>>t;
			a[i].v.push_back(t);
			if(t==-1) a[i].cnt++;
			else a[i].sum+=t;
		}
	}
	
	map<int,int>mp;
	sort(a+1,a+1+n,cmps);
	a[1].sum+=a[1].cnt*k;
	for(auto &i:a[1].v) if(i==-1) i=k;
	mp[a[1].s]=a[1].sum;
	
	int mx=1e18;
	for(int i=2;i<=n;i++)
	{
		if(a[i].s==a[1].s)
		{
			a[i].sum+=a[i].cnt*k;
			for(auto &j:a[i].v) if(j==-1) j=k;
			mp[a[1].s]=min(mp[a[1].s],a[i].sum);
		}
		else if(a[i].s==a[i-1].s)
		{
			if(a[i].sum>=mx)
			{
				cout<<"No\n";
				return ;
			}
			if(a[i].sum+a[i].cnt*k>=mx)
			{
				int t=mx-1-a[i].sum;
				a[i].sum=mx-1;
				for(auto &j:a[i].v)
				{
					if(j==-1)
					{
						if(t>=k) j=k,t-=k;
						else j=t,t-=t;
					}
				}
			}
			else
			{
				a[i].sum+=a[i].cnt*k;
				for(auto &j:a[i].v) if(j==-1) j=k;
			}
			mp[a[i].s]=min(mp[a[i].s],a[i].sum);
		}
		else
		{
			mx=min(mx,mp[a[i-1].s]);
			
			if(a[i].sum>=mx)
			{
				cout<<"No\n";
				return ;
			}
			else
			{
				if(a[i].sum+a[i].cnt*k>=mx)
				{
					int t=mx-1-a[i].sum;
					a[i].sum=mx-1;
					for(auto &j:a[i].v)
					{
						if(j==-1)
						{
							if(t>=k) j=k,t-=k;
							else j=t,t-=t;
						}
					}
				}
				else
				{
					a[i].sum+=a[i].cnt*k;
					for(auto &j:a[i].v) if(j==-1) j=k;
				}
				mp[a[i].s]=a[i].sum;
			}
		}
	}
	cout<<"Yes\n";
	sort(a+1,a+1+n,cmpi);
	for(int i=1;i<=n;i++)
	{
		for(auto j:a[i].v) cout<<j<<" ";
		cout<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
