#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int ca=0,cb=0;
	string s;
	cin>>s;
	for(auto i:s) if(i=='A') ca++;
	else cb++;
	if(ca>cb) cout<<"A\n";
	else cout<<"B\n";
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
