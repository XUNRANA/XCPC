#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int a[28];
void solve()
{
	ans=0;
	cin>>n>>s;
	for(int i=0;i<26;i++) a[i]=0;
	for(auto i:s) a[i-'A']++;
	for(int i=0;i<26;i++) if(a[i]>=i+1) ans++;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
