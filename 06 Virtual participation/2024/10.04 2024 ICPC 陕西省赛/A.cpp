#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	string ans;
	for(auto j:s)
	{
		int t=j-'0';
		for(int i=2;i>=0;i--)
		{
			if(t>>i&1)
			{
				if(i==2) ans+='r';
				
				if(i==1) ans+='w';
			
				if(i==0) ans+='x';
			
			}
			else ans+='-';
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
