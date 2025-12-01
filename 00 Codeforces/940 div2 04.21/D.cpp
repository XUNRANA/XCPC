#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],ans,t;
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<vector<int>>s(31,vector<int>(n+1,0));
	for(int j=0;j<=30;j++)
	{
		t=0;
		for(int i=1;i<=n;i++)
		{
			t^=(a[i]>>j&1);//前缀异或和
			s[j][i]=s[j][i-1]+t;//1的个数 
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=30;j>=0;j--)
		{
			if(a[i]>>j&1)
			{
				/*
				111 011 111 010 001
				2:1   1   0   0   0
				1:1   0   1   0   0
				0:1   0   1   1   0
				*/
				/*
				cout<<a[i]<<" "<<j<<"\n";
				cout<<s[j][i-1]<<" "<<(s[j][n]-s[j][i-1])<<"\n";
				cout<<(i-s[j][i-1])<<" "<<(n-i+1-(s[j][n]-s[j][i-1]))<<"\n\n";
				*/
				ans+=s[j][i-1]*(s[j][n]-s[j][i-1]);
				ans+=(i-s[j][i-1])*(n-i+1-(s[j][n]-s[j][i-1]));
				break;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T=1;
	cin>>T;
	while(T--) solve();
}
