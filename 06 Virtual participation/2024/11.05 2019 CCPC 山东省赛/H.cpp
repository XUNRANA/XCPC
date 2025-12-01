#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[100010];
int y[100010];
int n,k;
string s;
void solve()
{
	cin>>n>>k;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='R') x[i]=x[i-1]+1,y[i]=y[i-1];
		else if(s[i]=='L') x[i]=x[i-1]-1,y[i]=y[i-1];
		else if(s[i]=='U') x[i]=x[i-1],y[i]=y[i-1]+1;
		else x[i]=x[i-1],y[i]=y[i-1]-1;
	}
	
	int x1=x[n]*(k-1);
	int y1=y[n]*(k-1);
	
	
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		ans=max(abs(x[i]+x1)+abs(y[i]+y1),ans);
		ans=max(abs(x[i])+abs(y[i]),ans);
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
