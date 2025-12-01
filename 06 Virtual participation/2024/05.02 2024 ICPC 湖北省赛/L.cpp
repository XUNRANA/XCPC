#include <bits/stdc++.h>
using namespace std;
#define int long long

int lcm(int x,int y)
{
	return x*y/__gcd(x,y);
}
int c[10],k;
int g[10][10];
void floyd()
{
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i==j) g[i][j]=0;
			else g[i][j]=lcm(c[i],c[j]);
		}
	}
	
	
	for(int p=1;p<=k;p++)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				g[i][j]=min(g[i][j],g[i][p]+g[p][j]);
			}
		}	
	}
}
void solve()
{
	k=0;
	int x,y;
	cin>>x>>y;
	c[++k]=x;
	c[++k]=y;
	c[++k]=2;
	if(__gcd(x,y)!=1) c[++k]=__gcd(x,y);
	for(int i=2;i*i<=x;i++) 
	if(x%i==0)
	{
		c[++k]=i;
		break;
	} 
	
	for(int i=2;i*i<=y;i++) 
	if(y%i==0)
	{
		c[++k]=i;
		break;
	}
	sort(c+1,c+1+k);
	k=unique(c+1,c+1+k)-c-1;
	for(int i=1;i<=k;i++)
	{
		if(c[i]==x)
		{
			floyd();
			cout<<g[i][k]<<"\n";
			return ;
		}
	}
}
signed main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
