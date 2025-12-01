#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int f=0;
	string s,t="";
	cin>>s;
	for(auto i:s)
	{
		if(i!='0') f=1;
		if(f) t+=i;
	}
	if(t=="") t="0";
	cout<<t<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
