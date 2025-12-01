#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,len,k;
	cin>>n;
	string s="aeiou",ans;
	len=n/5;
	k=n%5;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<len;j++) ans+=s[i];
		if(i<k) ans+=s[i];
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
