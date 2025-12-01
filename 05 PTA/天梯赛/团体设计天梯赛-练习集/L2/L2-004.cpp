#include <bits/stdc++.h>
using namespace std;
#define int long long

int l[1010];
int r[1010];
int v[1010];

int l1[1010];
int r1[1010];
int v1[1010];

int a[1010];

int idx,idx1;
void insert(int rt,int x)
{
	if(x>=v[rt])
	{
		if(r[rt]!=-1)
		{
			insert(r[rt],x);
		}
		else
		{
			r[rt]=idx;
			v[idx]=x;
			idx++;
		}
	}
	else
	{
		if(l[rt]!=-1)
		{
			insert(l[rt],x);
		}
		else
		{
			l[rt]=idx;
			v[idx]=x;
			idx++;
		}
	}
}

void insert1(int rt,int x)
{
	if(x<v1[rt])
	{
		if(r1[rt]!=-1)
		{
			insert1(r1[rt],x);
		}
		else
		{
			r1[rt]=idx1;
			v1[idx1]=x;
			idx1++;
		}
	}
	else
	{
		if(l1[rt]!=-1)
		{
			insert1(l1[rt],x);
		}
		else
		{
			l1[rt]=idx1;
			v1[idx1]=x;
			idx1++;
		}
	}
}
vector<int>p,p1;
void dfs(int rt)
{
	if(v[rt]!=1e9) p.push_back(v[rt]);
	if(l[rt]!=-1) dfs(l[rt]);
	if(r[rt]!=-1) dfs(r[rt]);
}

void dfs1(int rt)
{
	if(v1[rt]!=1e9) p1.push_back(v1[rt]);
	if(l1[rt]!=-1) dfs1(l1[rt]);
	if(r1[rt]!=-1) dfs1(r1[rt]);
}
vector<int>ans,ans1;
void df(int rt)
{
	
	if(l[rt]!=-1) df(l[rt]);
	if(r[rt]!=-1) df(r[rt]);
	if(v[rt]!=1e9) ans.push_back(v[rt]);
}
void df1(int rt)
{
	if(l1[rt]!=-1) df1(l1[rt]);
	if(r1[rt]!=-1) df1(r1[rt]);
	if(v1[rt]!=1e9) ans1.push_back(v1[rt]);
}
void solve()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++) l[i]=r[i]=l1[i]=r1[i]=-1,v1[i]=v[i]=1e9;
	
	vector<int>t;
	for(int i=1;i<=n;i++) cin>>a[i],t.push_back(a[i]);


	
	idx=idx1=2;
	
	v[1]=v1[1]=a[1];
	
	for(int i=2;i<=n;i++)
	{
		insert(1,a[i]);
		insert1(1,a[i]);
	}
	dfs(1);
	dfs1(1);
	if(t==p||t==p1) 
	{
		cout<<"YES\n";
		if(t==p)
		{
			df(1);
			int f=0;
			for(auto i:ans)
			{
				if(f) cout<<" ";
				cout<<i;
				f=1;
			}
			cout<<"\n";
		}
		else
		{
			df1(1);
			int f=0;
			for(auto i:ans1)
			{
				if(f) cout<<" ";
				cout<<i;
				f=1;
			}
			cout<<"\n";
		}
	}
	else cout<<"NO\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

