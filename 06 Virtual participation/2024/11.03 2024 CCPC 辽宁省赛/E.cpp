#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
void up(int x,vector<vector<int>>&ans)
{
	
	ans[1][x]=ans[1][x+1]=ans[2][x+1]=ans[3][x+1]=cnt;
	ans[2][x]=ans[3][x]=ans[4][x]=ans[5][x]=cnt+1;
	ans[6][x]=ans[6][x+1]=ans[5][x+1]=ans[4][x+1]=cnt+2;
	cnt+=3;
}

void up1(int x,vector<vector<int>>&ans)
{
	
	ans[x][1]=ans[x][2]=ans[x][3]=ans[x+1][1]=cnt;
	
	ans[x+1][2]=ans[x+1][3]=ans[x+1][4]=ans[x+1][5]=cnt+1;
	
	ans[x+1][6]=ans[x][4]=ans[x][5]=ans[x][6]=cnt+2;
	
	cnt+=3;
}

void solve()
{
	cin>>n>>m;
	vector<vector<int>>ans(n+10,vector<int>(m+10,0));
		
	if(n%4==0)
	{
		cnt=1;
		int c=0;
		for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
		{
			ans[i][j]=cnt;
			c++;
			if(c==4) cnt++,c=0;
		}
	}
	else if(m%4==0)
	{
		cnt=1;
		int c=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			ans[i][j]=cnt;
			c++;
			if(c==4) cnt++,c=0;
		}
	}
	else if(n>=6&&(n-6)%4==0&&m%2==0)
	{
		
		cnt=1;
		for(int j=1;j<=m;j+=2) up(j,ans);
		
		int c=0;
		for(int j=1;j<=m;j++)
		{
			for(int i=7;i<=n;i++)
			{
				ans[i][j]=cnt;
				c++;
				if(c==4) cnt++,c=0;
			}
		}
	}
	else if(m>=6&&(m-6)%4==0&&n%2==0)
	{
		cnt=1;
		for(int i=1;i<=n;i+=2) up1(i,ans);
		
		int c=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=7;j<=m;j++)
			{
				ans[i][j]=cnt;
				c++;
				if(c==4) cnt++,c=0;
			}
		}
	}
	else 
	{
		cout<<"NO\n";
		return ;
	}
	
	cout<<"YES\n";
	for(int i=1;i<=n;i++,cout<<"\n") 
	for(int j=1;j<=m;j++) 
	{
		cout<<ans[i][j]<<" ";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
