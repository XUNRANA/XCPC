#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n,ans=0;
	string s;
	cin>>n>>s;
	for(auto i:s)
	{
		if(i=='_') continue;
		else if(i=='(') ans+=3;
		else ans++;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
