#include <bits/stdc++.h>
using namespace std;
#define N 50010
int fa[3*N],n,k,op,u,v,ans;
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=3*n;i++) fa[i]=i;
	while(k--)
	{
		cin>>op>>u>>v;
		if(u>n||v>n) ans++;
		else 
		{
			if(op==1)
			{
				if(find(n+u)==find(v)||find(n+v)==find(u)) ans++;
				else 
				{
					fa[find(u)]=find(v);
					fa[find(u+n)]=find(v+n);
					fa[find(u+n+n)]=find(v+n+n);
				}
			}
			else
			{
				if(find(u)==find(v)||find(n+v)==find(u)) ans++;
				else
				{
					fa[find(u+n)]=find(v);
					fa[find(u+n+n)]=find(v+n);
					fa[find(u)]=find(v+n+n);
				}
			} 
		}
	}
	cout<<ans;
}
