#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int b,r,d,s;
	cin>>b>>r>>d>>s;
	
	if(!d)
	{
		cout<<"ok\n";
		return ;
	}
	
	if(!b||!r)
	{
		if(d) cout<<"gua!\n";
		else cout<<"ok\n";
		return ;
	}
	
	if(!s)
	{
		if(d<=b) cout<<"ok\n";
		else cout<<"gua!\n";
		return ;
	}
	
	int t=(d+b-1)/b;
	
	
	int j=r*s/60+1;
	

	
	if(t<=j) cout<<"ok\n";
	else cout<<"gua!\n";
}
/*
7
38 156 152 1
280 25 280 0
99 51 9 10
0 0 1 1
99 0 1 1
11 1080 209 1
11 1080 210 1
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
