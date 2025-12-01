#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	string s,t;
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			cout<<"YES\n";
			return ;
		}
		else if(t[i]=='1')
		{
			cout<<"NO\n";
			return ;
		}
	}	
	cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
