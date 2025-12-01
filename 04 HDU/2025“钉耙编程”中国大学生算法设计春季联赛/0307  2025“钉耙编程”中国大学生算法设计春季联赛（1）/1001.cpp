#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	int n;
	cin>>n>>s;
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		string t;
		cin>>t;
		if(t==s) ans=i;
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

