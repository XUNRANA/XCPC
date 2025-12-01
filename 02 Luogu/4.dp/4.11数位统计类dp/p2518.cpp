#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[10],C[60][60],ans;
void init()
{
	for(int i=0;i<60;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!j) C[i][j]=1;
			else C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
}
void solve()
{
	string s;
	cin>>s;
	for(auto i:s) c[i-'0']++;	
	int n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s[i]-'0';j++)
		{
			if(c[j])
			{
				int res=1;
				int sum=n-i;//Ê£ÓàµÄÊý 
				c[j]--;
				for(int k=0;k<10;k++) res=res*C[sum][sum-c[k]],sum-=c[k];
				c[j]++;
				ans+=res; 
			}
		}
		c[s[i]-'0']--;
	}
	cout<<ans<<"\n";
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
