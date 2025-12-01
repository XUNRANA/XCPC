#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,p[N],b[N],ans[N],fa;
vector<int>g[N];
struct hxtree
{
	int v[N];
	int flow(int x) {return x&-x;}
	void fix(int x,int y)
	{
		while(x<=n)
		{
			v[x]+=y;
			x+=flow(x);
		}
	}
	int fsum(int x)
	{
		int res=0;
		while(x)
		{
			res+=v[x];
			x-=flow(x);
		}
		return res;
	}
}hx;
void dfs(int x)
{
	ans[x]=-(hx.fsum(n)-hx.fsum(p[x]));
	for(auto i:g[x]) dfs(i);
	ans[x]+=(hx.fsum(n)-hx.fsum(p[x]));
	hx.fix(p[x],1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i],b[i]=p[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++) p[i]=lower_bound(b+1,b+n+1,p[i])-b;//ÀëÉ¢»¯
	for(int i=2;i<=n;i++)
	{
		cin>>fa;
		g[fa].push_back(i);
	} 
	dfs(1);
	for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
}
