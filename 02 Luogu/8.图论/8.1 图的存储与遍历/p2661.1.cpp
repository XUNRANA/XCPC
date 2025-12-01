#include <bits/stdc++.h>
using namespace std;
int f[200010],d[200010],n,ans;
int fa(int x)
{
	if(f[x]!=x) //更新祖先节点和路径长 
	{
		int last=f[x];       //记录父节点 
		f[x]=fa(f[x]);       //更新祖先节点 
		d[x]+=d[last];       //更新路径长 
	}
	return f[x];
}
void check(int a,int b)
{
	int x=fa(a),y=fa(b);
	if(x!=y) 
	{
		f[x]=y;//将a的祖先更改成b的祖先，a到祖先的距离等于b到祖先的距离加1 
		d[a]=d[b]+1;
	}
	else ans=min(ans,d[a]+d[b]+1);//构成环，环的长度为a、b到祖先的距离之后加1 
	return ;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) f[i]=i;
	ans=0x7777777;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		check(i,t);
	}
	cout<<ans;
}
