#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int a,b;
	cin>>a>>b;
	if(b) cout<<"-\n";
	else
	{
		if(a==0) cout<<"biii\n";
		else if(a==1) cout<<"dudu\n";
		else cout<<"-\n";
	}
	if(a==0||a==2) cout<<"stop";
	else cout<<"move";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

