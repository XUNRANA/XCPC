#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x,y,z;
	cin>>x>>y>>z;
	cout<<y<<" ";
	if(!z)
	{
		if(y>x) cout<<"JJ\n";
		else cout<<"MM\n";
	}
	else
	{
		if(y>x) cout<<"GG\n";
		else cout<<"DD\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
