#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(!b&&!c)
	{
		cout<<"YES\n";
		if(a==1) cout<<"0\n";
		else cout<<"1\n";
	}
	else if(a>b+c)
	{
		cout<<"YES\n";
		cout<<2*(b+c)+1<<"\n";
	}
	else cout<<"NO\n";
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
