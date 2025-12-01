#include <bits/stdc++.h>
using namespace std;
struct data
{
	int x,y,z;
}f[100010];
int n,m,a[20010],b[20010];
int cmp(struct data a,struct data b)
{
	return a.z>b.z;//先处理怨气大的 
}
int find(int x)
{
	if(a[x]==x) return x;
	return a[x]=find(a[x]);
}
void ad(int x,int y)
{
	x=find(a[x]);
	y=find(a[y]);
	a[x]=y;
}
int check(int x,int y)
{
	x=find(x);
	y=find(y);
	return x==y;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<=m;i++) cin>>f[i].x>>f[i].y>>f[i].z;
	sort(f+1,f+1+m,cmp);//先按怨气值排序。 
	for(int i=1;i<=m+1;i++)//m+1时会输出0 
	{
		if(check(f[i].x,f[i].y))//判断两个人是否是同一个集合 
		{
			cout<<f[i].z;//输出最大,结束。 
			break;
		}
		else
		{
			if(!b[f[i].x]) b[f[i].x]=f[i].y; //标记敌人 
			else ad(b[f[i].x],f[i].y);       //将敌人的敌人合并 
			
			if(!b[f[i].y]) b[f[i].y]=f[i].x;
			else ad(b[f[i].y],f[i].x);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
