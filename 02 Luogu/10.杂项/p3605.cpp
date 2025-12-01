#include <bits/stdc++.h>
using namespace std;
int n,p[100010],b[100010],ans[100010],fa;
vector<int>g[100010];
struct hxtree
{
	int t[100010];
	int lowbit(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		while(i<=n)
		{
			t[i]+=x;
			i+=lowbit(i);
		}
	}
	int sum(int i)
	{
		int res=0;
		while(i)
		{
			res+=t[i];
			i-=lowbit(i);
		}
		return res;
	}
}hx;
void dfs(int x)
{
	ans[x]-=(hx.sum(n)-hx.sum(p[x]));//原来比x强的
	for(auto i:g[x]) dfs(i);//加x的下属
	ans[x]+=hx.sum(n)-hx.sum(p[x]);//后来比x强的
	hx.add(p[x],1);//加x自己
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i],b[i]=p[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++) p[i]=lower_bound(b+1,b+n+1,p[i])-b;
	for(int i=2;i<=n;i++)
	{
		cin>>fa;
		g[fa].push_back(i);
	}
	dfs(1); 
	for(int i=1;i<=n;i++) cout<<ans[i]<<"\n"; 
}
