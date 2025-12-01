#include <bits/stdc++.h>
using namespace std;
int n,m,k,x[100010],y[100010];
char a[510][510],vt[510][510],c[100010];
int d[]={-2,-1,0,1,2};
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>x[i]>>y[i]>>c[i];
	for(int j=k;j>=1;j--)
	{
		int tx=x[j],ty=y[j];
		for(int i=0;i<5;i++)
		{

			if(tx+d[i]>n||tx+d[i]<1||vt[tx+d[i]][ty]) continue;
			a[tx+d[i]][ty]=c[j];
			vt[tx+d[i]][ty]=1;
		}
		for(int i=0;i<5;i++)
		{
			if(ty+d[i]>m||ty+d[i]<1||vt[tx][ty+d[i]]) continue;
			a[tx][ty+d[i]]=c[j];
			vt[tx][ty+d[i]]=1;
		}
	}
	
	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) 
	if(vt[i][j]) cout<<a[i][j];
	else cout<<".";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

