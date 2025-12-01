#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int c0=0,c1=0;
	for(auto i:s) 
	if(i=='Y') c1++;
	else if(i=='N') c0++;
	if(c0+c1==5)
	{
		if(c1>c0) cout<<"1\n";
		else cout<<"-1\n";
	}
	else
	{
		int t=5-c0-c1;
		if(c0+t>=c1||c1+t>=c0) cout<<"0\n";
		else if(c0>c1+t) cout<<"-1\n";
		else if(c1>c0+t) cout<<"1\n";
		else cout<<"0\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
