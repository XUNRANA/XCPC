#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	string s,ans;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='L') 
		{
			ans+=s[i];
			continue;
		}
		int f=0;
		if(i-1>=0&&s[i-1]=='L') f=1;
		if(i+1<n&&s[i+1]=='L') f=1;
		if(!f) ans+='C';
		else ans+=s[i];
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
