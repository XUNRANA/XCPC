#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,h,r,f[1010],f1[100001],f2[100001],x[100001],y[100001],z[100001],a1,a2,t,t1,t2;
ll dis(ll x,ll y,ll z,ll x1,ll y1,ll z1)//计算两点距离 
{
	return (x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1);
}
int find(int x)//找集合的祖先 
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void solve()
{
	cin>>n>>h>>r;
	for(int i=1;i<=n;i++) f[i]=i;
	t1=t2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		if(z[i]+r>=h) f1[++t1]=i;//该点是否与顶面相交 
		if(z[i]-r<=0) f2[++t2]=i;//该点是否与底面相交 
		for(int k=1;k<=i;k++)
		{
			if(((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]))>4*r*r) continue;//两点不相交直接跳过 
			if(dis(x[i],y[i],z[i],x[k],y[k],z[k])<=4*r*r)//相交 
			{
				a1=find(i);
				a2=find(k);
				if(a1!=a2) f[a2]=a1;//若两点属两个集合。并在一起。 
			}
		}
	}
	for(int i=1;i<=t1;i++) for(int j=1;j<=t2;j++) 
	if(find(f1[i])==find(f2[j])) //若有一条可以从顶面到底面的路径 
	{
		cout<<"Yes\n";
		return ;
	}
	cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) solve();
}
