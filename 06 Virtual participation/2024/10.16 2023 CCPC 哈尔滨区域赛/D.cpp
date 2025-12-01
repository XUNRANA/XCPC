#include <bits/stdc++.h>
using namespace std;
int f[1000010];//f[x]==0 表示x为质数 
int g[1000010];//x含有的质因数的乘积 
int w[1000010];//x含有的质因数的个数 
int sz[1000010];//sz[x]乘积为x的数量 
int vt[1000010];
int fa[1000010];
void init()
{ 
	for(int i=2;i<=1e6;i++)
	{
		if(!f[i])//质数 
		{
			w[i]=1;
			g[i]=i;
			for(int j=i+i;j<=1e6;j+=i)
			{
				w[j]++;//个数++ 
				f[j]=1;//非质数 
				if(!g[j]) g[j]=i;//累积乘积 
				else g[j]*=i;
			}
		}
	}
}

int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void solve()
{
	int l,r;
	cin>>l>>r;
	if(l==1)
	{
		int ans=0;
		for(int j=2;j<=r;j++) ans+=w[j];
		cout<<ans<<"\n";
		return ;
	}
	
	bool isp=0;
	for(int i=l;i<=r;i++) if(!f[i]) isp=1;
	
	if(isp)
	{
		for(int i=1;i<=r;i++) sz[i]=vt[i]=0;
		for(int i=l;i<=r;i++) sz[g[i]]++; 
		int ans=0;
		for(int i=2;i<=r;i++)
		{
			if(!vt[i]&&sz[i])//i和质数连接 
			{
				ans+=w[i]*(sz[i]-1)+w[i]+1;
				vt[i]=1;
				for(int j=i+i;j<=r;j+=i)
				if(!vt[j]&&sz[j])//j和i连接 
				{
					vt[j]=1;
					ans+=w[j]*sz[j];
				}
			}
		}
		cout<<ans-2<<"\n";//质数本身相连，减去2 
	}
	else
	{
		vector<array<int,3>>g;
		for(int i=l;i<=r;i++) fa[i]=i;
		for(int i=l;i<=r;i++)
		{
			for(int j=l+1;j<=r;j++)
			{
				g.push_back({w[i]+w[j]-w[__gcd(i,j)],i,j});
			}
		}
		sort(g.begin(),g.end());
		int ans=0;
		for(auto a:g)
		{
			int u=a[1];
			int v=a[2];
			int w=a[0];
			if(find(u)==find(v)) continue;
			ans+=w;
			fa[find(u)]=find(v);
		}
		cout<<ans<<"\n";
	}
}

int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
