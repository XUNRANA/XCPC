#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int dp[2][310][310][3];
int g[310][310][310];
//前i个元素，放了多少个a，多少个b，最后一个为a/b/c的合法方案 
void solve()
{
	int n,q;
	string s;
	cin>>n>>q>>s;
	s=" "+s;
	
	int c=0;//?的数量 
	if(s[1]!='?') dp[1][0][0][s[1]-'a']=1;
	else
	{
		c++;
		for(int i=0;i<3;i++) dp[1][i==0][i==1][i]=1;
	}
	
	for(int i=2,f=0;i<=n;i++,f^=1)
	{
		if(s[i]=='?')
		{
			for(int j=0;j<=c;j++)//a的个数 
			{
				for(int k=0;j+k<=c;k++)//b的个数 
				{
					for(int p=0;p<3;p++)//最后一位 
					{
						if(dp[f^1][j][k][p])
						{
							for(int q=0;q<3;q++)//枚举问号填啥 
							if(q!=p)
							{
								dp[f][j+(q==0)][k+(q==1)][q]+=dp[f^1][j][k][p];
								dp[f][j+(q==0)][k+(q==1)][q]%=P;
							} 
							dp[f^1][j][k][p]=0;
						}
					}
				}
			}
			c++; 
		}
		else
		{
			for(int j=0;j<=c;j++)
			{
				for(int k=0;k+j<=c;k++)
				{
					for(int p=0;p<3;p++)
					{
						if(p!=s[i]-'a') dp[f][j][k][s[i]-'a']+=dp[f^1][j][k][p];
						dp[f^1][j][k][p]=0;
					}
				}
			}
		}
	}
	
	
	for(int i=0;i<=c;i++)
	{
		for(int j=0;i+j<=c;j++)
		{
			for(int k=0;k<3;k++)
			{
				g[i][j][c-i-j]=(g[i][j][c-i-j]+dp[n&1][i][j][k])%P;
			}
		}
	}
	
	
	
	
	for(int i=1;i<=c;i++)
	{
		for(int j=0;j<=c;j++)
		{
			for(int k=0;k<=c;k++)
			{
				g[i][j][k]=(g[i][j][k]+g[i-1][j][k])%P;
			}
		}
	}
	
		
		
		
		
	for(int i=0;i<=c;i++)
	{
		for(int j=1;j<=c;j++)
		{
			for(int k=0;k<=c;k++)
			{
				g[i][j][k]=(g[i][j][k]+g[i][j-1][k])%P;
			}
		}
	}	
		
		
	
	for(int i=0;i<=c;i++)
	{
		for(int j=0;j<=c;j++)
		{
			for(int k=1;k<=c;k++)
			{
				g[i][j][k]=(g[i][j][k]+g[i][j][k-1])%P;
			}
		}
	}	
	
	
	
	while(q--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		x=min(x,c);
		y=min(y,c);
		z=min(z,c);
		cout<<g[x][y][z]<<"\n";
	}
	

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
