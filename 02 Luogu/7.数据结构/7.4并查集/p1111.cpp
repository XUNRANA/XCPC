#include <bits/stdc++.h>
using namespace std;
int f[1010],n,m,x,y;
struct node
{
	int x,y,t;
}a[100010];
bool cmp(struct node a1,struct node a2)
{
	return a1.t<a2.t;
}
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].t;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		x=find(a[i].x);
		y=find(a[i].y);
		if(x!=y) f[x]=y,n--;
		if(n==1) 
		{
			cout<<a[i].t;
			return 0;
		}
	}
	cout<<-1;
} 
