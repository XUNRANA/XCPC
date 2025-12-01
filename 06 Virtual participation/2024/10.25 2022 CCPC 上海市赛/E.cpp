#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[110];
void solve()
{
	string s,f;
	cin>>s>>f;
	if(f.size()==1)
	{
		cout<<f<<"\n";
		return ;
	}
	int ans=s.size(),l=0;
	for(int i=0;i<=100;i++) dp[i]=-1;
	
	for(int i=0;i<s.size();i++)
	{
		for(int j=f.size()-1;j>=0;j--)
		{
			if(f[j]==s[i])
			{
				if(!j) dp[j]=i;
				else 
				{
					if(dp[j-1]!=-1) 
					{
						dp[j]=dp[j-1];
						if(j==f.size()-1) 
						{
							if(i-dp[j]+1<ans)
							{
								ans=i-dp[j]+1;
								l=dp[j];
							}
						}
					}
				}
			}
		}
	}
	cout<<s.substr(l,ans)<<"\n";
}
/*
4
114514 15
shanghaicpc ac
aaabbbaaabbbccc abc
howdeliciousandfreshitis oishii
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
