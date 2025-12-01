#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k,ans=0;
	string s;
	cin>>n>>k>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='B')
		{
			ans++;
			i+=k-1;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
