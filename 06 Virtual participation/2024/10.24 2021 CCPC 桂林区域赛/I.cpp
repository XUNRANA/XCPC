#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	int cnt=0;
	long long ans=0;
	for(int i=n-1;i>=0;i--)
	{
		if(!cnt) cnt++;
		else
		{
			if(s[i]=='1') 
			{
				ans+=i+1;
				cnt--;
			}
			else cnt++;
		}
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
