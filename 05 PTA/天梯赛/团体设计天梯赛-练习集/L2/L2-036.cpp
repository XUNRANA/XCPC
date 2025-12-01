#include <bits/stdc++.h>
using namespace std;

int d[210][210];
const int inf=0x3f3f3f3f;
void solve()
{
	int n,m;
	cin>>n>>m;
	memset(d,inf,sizeof(d));
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		d[u][v]=min(d[u][v],w);
		d[v][u]=min(d[v][u],w);
	}
	int q;
	cin>>q;
	int as=inf;
	int a=0,cnt=0;
	for(int i=1;i<=q;i++)
	{
		int l;
		cin>>l;
		vector<int>p(l+2,0),c(n+1,0);
		int f=0,sum=0;
		for(int j=1;j<=l;j++) cin>>p[j],c[p[j]]++;
		for(int j=1;j<=l;j++) if(c[p[j]]!=1) f=1;
		if(l!=n) f=1;
		for(int j=1;j<=l+1;j++) 
		{
			if(d[p[j-1]][p[j]]==inf) f=1;
			else sum+=d[p[j-1]][p[j]];
		}
		if(f) continue;
		cnt++;
		if(sum<as)
		{
			as=sum;
			a=i;
		}
	}
	cout<<cnt<<"\n"<<a<<" "<<as<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

