#include <bits/stdc++.h>
using namespace std;
#define N 200010
multiset<int>st[N];
//map<int,int>mp[N];
//map<int,int>mr;
multiset<int>rst;
vector<int>g[N];
int n,m;
int a1,b1,x1,y1,z1;
int a[N],b[N],x[N],y[N],z[N],x11[N],y11[N];
void add(int i,int t)
{
	a1=a[i];
	b1=b[i];
	x1=x[i];
	y1=y[i];
	z1=z[i];
	
	int ra=*st[a1].rbegin();
	int rb=*st[b1].rbegin();
	
	st[a1].erase(st[a1].find(x11[i]));
	st[b1].erase(st[b1].find(y11[i]));


	if(a1==t)
	{
		st[a1].insert(x1+z1);
		st[b1].insert(y1);
	}
	else
	{
		st[a1].insert(x1);
		st[b1].insert(y1+z1);
	}
	
	int ra1=*st[a1].rbegin();
	int rb1=*st[b1].rbegin();
	
	if(ra1!=ra) 
	{
		rst.erase(rst.find(ra));
		rst.insert(ra1);
	}
	
	if(rb1!=rb) 
	{
		rst.erase(rst.find(rb));
		rst.insert(rb1);
	}
}
void del(int i,int t)
{
	a1=a[i];
	b1=b[i];
	x1=x[i];
	y1=y[i];
	z1=z[i];
	
	int ra=*st[a1].rbegin();
	int rb=*st[b1].rbegin();
	
	if(a1==t)
	{
		st[a1].erase(st[a1].find(x1+z1));
		st[b1].erase(st[b1].find(y1));

	}
	else
	{
		st[a1].erase(st[a1].find(x1));
		st[b1].erase(st[b1].find(y1+z1));
	}
	
	st[a1].insert(x11[i]);
	st[b1].insert(y11[i]);
	
	
	int ra1=*st[a1].rbegin();
	int rb1=*st[b1].rbegin();
	
	if(ra1!=ra) 
	{
		rst.erase(rst.find(ra));
		rst.insert(ra1);
	}
	
	if(rb1!=rb) 
	{
		rst.erase(rst.find(rb));
		rst.insert(rb1);
	}
}
void solve()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) g[i].clear(),st[i].clear();
	
	rst.clear();
	
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>x[i]>>y[i]>>z[i];
		if(x[i]+z[i]<=y[i])
		{
			x11[i]=x[i]+z[i];
			y11[i]=y[i];
		}
		else if(y[i]+z[i]<=x[i])
		{
			x11[i]=x[i];
			y11[i]=y[i]+z[i];
		}
		else
		{
			int s=x[i]+y[i]+z[i];
			x11[i]=y11[i]=s/2;
			if(s%2==1) x11[i]++;
		}
		st[a[i]].insert(x11[i]);
		st[b[i]].insert(y11[i]);
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);

	}
	
	for(int i=1;i<=n;i++) rst.insert(*st[i].rbegin());
	
	vector<int>res;
	for(int i=1;i<=n;i++)
	{
		for(auto j:g[i]) add(j,i);
		int x=*st[i].rbegin();
		if((x==*rst.rbegin())&&*(--rst.rbegin())!=x) res.push_back(i);
		for(auto j:g[i]) del(j,i);
	}
	
	cout<<res.size()<<"\n";
	for(auto i:res) cout<<i<<" ";
	cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
