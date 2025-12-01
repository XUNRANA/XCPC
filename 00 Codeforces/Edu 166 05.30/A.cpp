#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	int n;
	cin>>n>>s;
	int pi=0,f=0;
	char pa='a';
	for(auto i:s)
	{
		if(i-'0'>=0&&i-'0'<=9)
		{
			if(i-'0'<pi||f==1) 
			{
				cout<<"NO\n";
				return ;
			}
			pi=i-'0';
		}
		else
		{
			f=1;
			if(i<pa) 
			{
				cout<<"NO\n";
				return ;
			}
			pa=i;
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
