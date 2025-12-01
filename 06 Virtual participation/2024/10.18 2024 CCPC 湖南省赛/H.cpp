#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353 
int dp[10010][15][110];
int fail[110];
//dp[i][j][k]
//表示当前在第i个位置，
//已经匹配了j个字串，
//第j+1个字串匹配到第k个位置 
/*
20 2
abacad
*/
void solve()
{
	int n,k;
	string s;
	cin>>n>>k>>s;
	int len=s.size();
	s="&"+s;
	
	fail[1]=0;
	for(int i=2,j=0;i<=len;i++)
	{
		while(j&&s[i]!=s[j+1]) j=fail[j];
		if(s[i]==s[j+1]) j++;
		fail[i]=j;
	}
	

	
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)//在第i个位置
	{
		for(int j=0;j<=k;j++)//已经匹配了多少个字串 
		{
			for(int l=0;l<len;l++)//当前匹配到第几个 
			{
				for(int c=0;c<26;c++)//遍历下一个字符的所有情况 
				{
					bool f=0;
					int pre=l;
					while(1) 
					{
						if(s[pre+1]==(char)(c+'a'))//下一个刚好匹配 
						{
							if(pre==len-1)//倒数第二个
							{
								dp[i+1][j+1][0]+=dp[i][j][l];
								dp[i+1][j+1][0]%=P;
							}
							else//一般情况 
							{
								dp[i+1][j][pre+1]+=dp[i][j][l];
								dp[i+1][j][pre+1]%=P;
							}
							f=1;
							break;
						}
						if(pre==0) break;//失配到0，退出 
						pre=fail[pre];
					}                                                                                                                                                                                                                                                                                                                                                                                       
					if(f) continue;//匹配成功了，直接跳过
					//匹配失败 
					dp[i+1][j][0]+=dp[i][j][l];
					dp[i+1][j][0]%=P;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<len;i++) 
	{
		ans+=dp[n][k][i];
		ans%=P;
	}
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
