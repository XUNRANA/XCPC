#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,dp[1010][100];
int a[5][1010];
int p3[]={1,3,9,27,81};
int ck1(int x)
{
    vector<int>v;
	while(x)
	{
		v.push_back(x%3);
		x/=3;
	}
    while(v.size()<n) v.push_back(0);
    for(int i=1;i<v.size();i++) if(v[i]==v[i-1]) return 0;
    return 1;
}
int ck(int x,int y)
{
	vector<int>v,v1;
	while(x)
	{
		v.push_back(x%3);
		x/=3;
	}
	while(y)
	{
		v1.push_back(y%3);
		y/=3;
	}
	while(v.size()<n) v.push_back(0);
	while(v1.size()<n) v1.push_back(0);
	for(int i=0;i<n;i++) if(v[i]==v1[i]) return 0;
	return 1;
}
int f(int i,int k)
{
	vector<int>v;
	while(k)
	{
		v.push_back(k%3);
		k/=3;
	}
	while(v.size()<n) v.push_back(0);
	
	int cnt=0;
	for(int j=1;j<=n;j++) if(a[j][i]!=v[j-1]) cnt++;
	return cnt;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++) 
	{
		char ch;
		cin>>ch;
		if(ch=='r') a[i][j]=0;
		else if(ch=='e') a[i][j]=1;
		else if(ch=='d') a[i][j]=2;
	}
    
	for(int i=0;i<=m;i++) for(int j=0;j<p3[n];j++) dp[i][j]=1e18;
    for(int j=0;j<p3[n];j++) if(ck1(j)) dp[1][j]=f(1,j);
    
    for(int i=2;i<=m;i++) 
	{
		for(int j=0;j<p3[n];j++)
		{
			if(dp[i-1][j]!=1e18)
			{
				for(int k=0;k<p3[n];k++)
				{
					if(ck1(k)&&ck(j,k)) dp[i][k]=min(dp[i-1][j]+f(i,k),dp[i][k]);
				}
			}
		}
	}
	int ans=1e18;
	for(int j=0;j<p3[n];j++) ans=min(dp[m][j],ans);
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

