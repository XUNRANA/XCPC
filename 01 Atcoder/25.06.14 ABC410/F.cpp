#include <bits/stdc++.h>
using namespace std;
int n,h,m;
int cnt[600010];
void solve()
{
	cin>>n>>m;
	int mx=max(n,m);
	int mi=min(n,m);
	vector<vector<int>>a(mi+1,vector<int>(mx+1,0));
	vector<vector<int>>p(mi+1,vector<int>(mx+1,0));
	for(int i=1;i<=n;i++) 
	{	
		for(int j=1;j<=m;j++)
		{	
			char ch;
			int x;
			cin>>ch;
			if(ch=='#') x=1;
			else x=-1;
			if(n>m) a[j][i]=x;		
			else a[i][j]=x;
		}
	}
	if(n>m) swap(n,m);
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++) p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
	
//	for(int i=1;i<=n;i++,cout<<"\n") 
//	for(int j=1;j<=m;j++) cout<<a[i][j];
	
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			
			for(int k=1;k<=m;k++)
			{       
				int pp=p[j][k]-p[i-1][k];
				int ppp=p[j][k-1]-p[i-1][k-1];
				cnt[ppp+n*m]++;
				ans+=cnt[pp+n*m];
				
			}
			
			for(int k=1;k<=m;k++)
			{       
				int pp=p[j][k]-p[i-1][k];
				int ppp=p[j][k-1]-p[i-1][k-1];
				cnt[ppp+n*m]--;
//				ans+=cnt[pp+n*m];
			}
		}
	}
	cout<<ans<<"\n";
} 
//5
//1 2 3 4 5
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
