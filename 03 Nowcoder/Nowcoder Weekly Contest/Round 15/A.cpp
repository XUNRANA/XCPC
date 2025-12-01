#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
void solve()
{
	cin>>s;
	for(int i=0;i<s.size()-1;i++) if((s[i]-'0')%2==(s[s.size()-1]-'0')%2) ans++;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
