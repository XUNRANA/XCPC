#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,m,u,v;
char op;
int fa[2*N];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int a,int b)
{
	int fat=find(a),fb=find(b);
	if(fat!=fb) fa[fat]=fb;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=2*n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>op>>u>>v;
		if(op=='D') 
		{
			merge(u,n+v);
			merge(n+u,v);
		}
		else 
		{
			merge(u,v);
			merge(n+u,n+v);
		}
	}
	set<int>s;
	for(int i=1;i<=n;i++) 
	if(find(i)==find(i+n)) 
	{
		cout<<0<<"\n";
		return ;
	}
	for(int i=1;i<=2*n;i++)
	s.insert(find(i));
	int ans=s.size()/2;
	cout<<1;
	while(ans--) cout<<"0";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

