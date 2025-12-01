#include <bits/stdc++.h>
using namespace std;
#define P 998244353
#define int long long
int dp[62][8][2];
int ck(char a)
{
	if(isdigit(a)) return 1;//0-9
	else if(islower(a)) return 2;//a-z
	else if(isupper(a)) return 4;//A-Z
	return 0;//?
}
int ck1(int x)
{
	if(x<10) return 1;
	else if(x<36) return 2;
	else return 4;
}

int ck2(char a)
{
	if(isdigit(a)) return a-'0';//0-9
	else if(islower(a)) return a-'a'+10;//a-z
	else if(isupper(a)) return a-'A'+10+26;//A-Z
}


void solve()
{
	int n;
	string s;
	cin>>n>>s;
	s=" "+s;
	int r=ck(s[1]);
	
	if(r==0)//?
	{
		for(int i=0;i<62;i++)
		{
			int r1=ck1(i);
			dp[i][r1][0]=1;
		}
	}
	else if(r==2)//a-z
	{
		dp[ck2(s[1])][2][0]=1;
		dp[ck2(s[1])+26][4][0]=1;
	}
	else dp[ck2(s[1])][r][0]=1;
	
	
	
	int k=0;
	for(int i=2;i<=n;i++,k^=1)
	{
		for(int i=0;i<62;i++) for(int j=0;j<8;j++) dp[i][j][k^1]=0;		
		int r=ck(s[i]),l=ck2(s[i]);
		if(r==0)//?
		{
			vector<int>a(10);
			for(int i1=0;i1<62;i1++)
			{
				for(int z=0;z<8;z++) a[z]=(a[z]+dp[i1][z][k])%P;
			}
			for(int i1=0;i1<62;i1++)
			{
				for(int j1=1;j1<8;j1++)
				{
					for(int z=0;z<8;z++)
					{
						if((z|ck1(i1))==j1) 
						{
							dp[i1][j1][k^1]+=(a[z]-dp[i1][z][k]+P)%P;
							dp[i1][j1][k^1]%=P;
						}
					}
				}
			}

//TLE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//			for(int i1=0;i1<62;i1++)//以i1结尾 
//			{
//				for(int j1=0;j1<62;j1++)
//				{
//					if(j1==i1) continue;
//					for(int z=0;z<8;z++)
//					{
//						if(!dp[j1][z][k]) continue; 
//						dp[i1][ck1(i1)|z][k^1]+=dp[j1][z][k];
//						dp[i1][ck1(i1)|z][k^1]%=P;
//					}
//				} 
//			}
		}
		else if(r==2)//a-z
		{
			int x=ck2(s[i]);
			for(int i1=x;i1<=x;i1++)//以i1结尾 
			{
				for(int j1=0;j1<62;j1++)
				{
					if(j1==i1) continue;
					for(int z=0;z<8;z++)
					{
						if(!dp[j1][z][k]) continue; 
						dp[i1][ck1(i1)|z][k^1]+=dp[j1][z][k];
						dp[i1][ck1(i1)|z][k^1]%=P;
					}
				} 
			}
			for(int i1=x+26;i1<=x+26;i1++)//以i1结尾 
			{
				for(int j1=0;j1<62;j1++)
				{
					if(j1==i1) continue;
					for(int z=0;z<8;z++)
					{
						if(!dp[j1][z][k]) continue; 
						dp[i1][ck1(i1)|z][k^1]+=dp[j1][z][k];
						dp[i1][ck1(i1)|z][k^1]%=P;
					}
				} 
			}
		}
		else 
		{
			int x=ck2(s[i]);
			for(int i1=x;i1<=x;i1++)//以i1结尾 
			{
				for(int j1=0;j1<62;j1++)
				{
					if(j1==i1) continue;
					for(int z=0;z<8;z++)
					{
						if(!dp[j1][z][k]) continue; 
						dp[i1][ck1(i1)|z][k^1]+=dp[j1][z][k];
						dp[i1][ck1(i1)|z][k^1]%=P;
					}
				} 
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<62;i++) ans=(ans+dp[i][7][k])%P;
	cout<<ans<<"\n";
}
signed main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
