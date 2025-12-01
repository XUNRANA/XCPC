#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[200010][26],ans;
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	if(n==1) 
	{
		cout<<"1\n";
		return ;
	}
	s=" "+s;
	if(n&1)
	{
		ans=1e9;
		for(int j=0;j<26;j++) c[1][j]=c[2][j]=0;
		c[1][s[1]-'a']++;
		c[2][s[2]-'a']++;
		for(int i=3;i<=n;i++)
		{
			for(int j=0;j<26;j++) c[i][j]=c[i-2][j];
			c[i][s[i]-'a']++;
		}
		
		int mx1=0,mx2=0;
		
		for(int j=0;j<26;j++)
		{
			mx1=max(mx1,c[n][j]-c[1][j]);
			mx2=max(mx2,c[n-1][j]);
		}
		ans=min(ans,n-(mx1+mx2));
	
		mx1=0,mx2=0;
		for(int j=0;j<26;j++)
		{
			mx1=max(mx1,c[n-2][j]);
			mx2=max(mx2,c[n-1][j]);
		}

		ans=min(ans,n-(mx1+mx2));

		
		for(int i=2;i<=n-1;i++)
		{
			mx1=mx2=0;
			for(int j=0;j<26;j++)
			{
				if(i%2==0)
				{      
					mx1=max(mx1,c[i-1][j]+c[n-1][j]-c[i][j]);
					mx2=max(mx2,c[n][j]-c[i-1][j]+c[i-2][j]);
				}
				else
				{
					mx1=max(mx1,c[i-2][j]+c[n-1][j]-c[i-1][j]);
					mx2=max(mx2,c[i-1][j]+c[n][j]-c[i][j]);
				}
			}
	
			ans=min(ans,n-(mx1+mx2));
		}
		cout<<ans<<"\n";
	}
	else
	{
		map<int,int>mp;
		int mx1=0,mx2=0;
		for(int i=1;i<=n;i+=2) 
		{
			mp[s[i]-'a']++;
			mx1=max(mx1,mp[s[i]-'a']);
		}
		mp.clear();
		for(int i=2;i<=n;i+=2) 
		{
			mp[s[i]-'a']++;
			mx2=max(mx2,mp[s[i]-'a']);
		}
		cout<<n-mx1-mx2<<"\n";
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

