#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int x;
	cin>>x;
	if(x>=90) cout<<"gong xi ni kao le "<<x<<" fen!";
	else cout<<"kao le "<<x<<" fen bie xie qi!";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
