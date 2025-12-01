#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,ans=0;
	string s;
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
	{	
		if(i+4<s.size()&&s.substr(i,5)=="chuan") ans++;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
