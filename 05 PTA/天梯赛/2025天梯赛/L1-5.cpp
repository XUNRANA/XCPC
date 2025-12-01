#include <bits/stdc++.h>
using namespace std;
int cnt[26];
int c[26];
void solve()
{
	string s;
	cin>>s;
	for(auto i:s) cnt[i-'a']++;
	for(int i=0;i<26;i++) cin>>c[i];
	int ans=0;
	for(int i=0;i<26;i++) 
	{
		ans+=cnt[i]*c[i];
		cout<<cnt[i]<<" \n"[i==25];
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
