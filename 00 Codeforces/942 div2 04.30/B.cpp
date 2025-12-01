#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	if(n==1)
	{
		if(s[0]=='U') cout<<"YES\n";
		else cout<<"NO\n";
	}
	else if(n==2)
	{
		if(s=="UU"||s=="DD") cout<<"NO\n";
		else cout<<"YES\n";
	}
	else
	{
		if(count(s.begin(),s.end(),'U')&1) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
