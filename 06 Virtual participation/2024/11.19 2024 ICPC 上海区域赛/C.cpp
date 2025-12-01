#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int l,r;
	cin>>l>>r;
	
	if(r<2*l) 
	{
		int len=r-l+1;
		if(len&1) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	else if(2*l==r) cout<<"Alice\n";
	else
	{
		if(l&1) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
