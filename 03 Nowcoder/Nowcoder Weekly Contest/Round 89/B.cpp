#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(i+1<n&&s[i]=='1'&&s[i+1]=='1')
		{
			ans++;
			s[i+1]='0';
		}
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
