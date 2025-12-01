#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	string s;
	int a=0,b=0;
	cin>>n>>s;
	for(auto i:s)
	{
		if(i=='1') a++;
		else b++;
		if(b>a) b=a=0;
	}
	if(a+b>3||(!a&&!b)) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
