#include <bits/stdc++.h>
using namespace std;
string s;
int c,k,n;
void solve()
{
	cin>>n>>k;
	map<int,int>m;//0-25
	cin>>s;
	for(auto i:s) m[i-'a']++;
	c=0;
	for(auto i:m) if(i.second&1) c++;
	if(k>=c-1) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
