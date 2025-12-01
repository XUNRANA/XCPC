#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[10010];
int c[10010];
int sz[10010];
int sum[10010];
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

void merge(int u,int v)
{
	int fu=find(u);
	int fv=find(v);
	if(fu<fv) f[fv]=fu;
	else f[fu]=fv;
}
bool cmp(int x,int y)
{
	if(1.0*sum[x]*sz[y]==1.0*sum[y]*sz[x]) return x<y;
	return 1.0*sum[x]*sz[y]>1.0*sum[y]*sz[x];
}
void solve()
{
	int n;
	cin>>n;
	for(int i=0;i<=10000;i++) f[i]=i,sz[i]=1;
	set<int>st;
	for(int i=1;i<=n;i++)
	{
		int id,fa,mo,k,sid,cnt,s,x;
		cin>>id>>fa>>mo>>k;
		st.insert(id);
		for(int i=1;i<=k;i++) 
		{
			cin>>x;
			merge(id,x);
			st.insert(x);
		}
		cin>>c[id]>>sum[id];
		if(fa!=-1)
		{
			merge(id,fa);
			st.insert(fa);
		}
		if(mo!=-1)
		{
			merge(id,mo);
			st.insert(mo);
		}
	}
	vector<int>ans;
	for(auto i:st) 
	{
		if(find(i)!=i)
		{
			sz[find(i)]+=sz[i];
			c[find(i)]+=c[i];
			sum[find(i)]+=sum[i];
		}
		else ans.push_back(i);
	}
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	for(auto i:ans) printf("%04d %d %.3f %.3f\n",i,sz[i],1.0*c[i]/sz[i],1.0*sum[i]/sz[i]);
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}



/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[10010];
int c[10010];
int sz[10010];
int sum[10010];
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

void merge(int u,int v)
{
	int fu=find(u);
	int fv=find(v);
	if(fu<fv)
	{
		f[fv]=fu;
		c[fu]+=c[fv];
		sum[fu]+=sum[fv];
		sz[fu]+=sz[fv];
	}
	else if(fv<fu)
	{
		f[fu]=fv;
		c[fv]+=c[fu];
		sum[fv]+=sum[fu];
		sz[fv]+=sz[fu];
	}
}
bool cmp(int x,int y)
{
	if(1.0*sum[x]*sz[y]==1.0*sum[y]*sz[x]) return x<y;
	return 1.0*sum[x]*sz[y]>1.0*sum[y]*sz[x];
}
void solve()
{
	int n;
	cin>>n;
	for(int i=0;i<=10000;i++) f[i]=i,sz[i]=1,c[i]=sum[i]=0;
	set<int>st;
	vector<pair<int,int>>e;
	for(int i=1;i<=n;i++)
	{
		int id,fa,mo,k,sid,cnt,s,x;
		cin>>id>>fa>>mo>>k;
		st.insert(id);
		for(int i=1;i<=k;i++) 
		{
			cin>>x;
			e.push_back({x,id});
		}
//		int xx,yy;
//		cin>>xx>>yy;
//		c[id]+=xx;
//		sum[id]+=yy;
		cin>>c[id]>>sum[id];
		if(fa!=-1) e.push_back({fa,id});
		if(mo!=-1) e.push_back({mo,id});
	}
	for(auto i:e) merge(i.first,i.second);
	
	
	set<int>s1;
	for(auto i:st) s1.insert(find(i));
	vector<int>ans;
	for(auto i:s1) ans.push_back(i);
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	for(auto i:ans) printf("%04d %d %.3f %.3f\n",i,sz[i],1.0*c[i]/sz[i],1.0*sum[i]/sz[i]);
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
*/
