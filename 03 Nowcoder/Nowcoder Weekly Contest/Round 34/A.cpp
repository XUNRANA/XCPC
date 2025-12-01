#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	char a,b;
	cin>>a>>b;
	if(a!=b) cout<<"4\n"<<a<<"\n"<<b<<"\n"<<a<<b<<"\n"<<b<<a<<"\n";
	else  cout<<"2\n"<<a<<"\n"<<a<<b<<"\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

