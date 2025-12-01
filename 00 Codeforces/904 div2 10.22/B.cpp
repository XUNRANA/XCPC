#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[200010];
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	s=" "+s;
	int c0=0,c1=0,j=1;
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='1') c1++; 
		else 
		{
			c0++;
			ans[j]=ans[j-1]+c1;
			j++;
		}
	}
	for(int i=1;i<j;i++) cout<<ans[i]<<" ";
	for(int i=j;i<=n;i++) cout<<"-1 ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
