#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m,ans=0;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<int>a(10);
	for(auto i:s) a[i-'A']++;
	for(int i=0;i<=6;i++) if(a[i]<m) ans+=m-a[i];
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
