#include <bits/stdc++.h>
using namespace std;
int n,c1,c2,ans;
void solve()
{
	cin>>n>>c1>>c2;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		if(s[0]==s[1]||s[1]==s[2])
		{
			if(2*c1>c2) ans+=c2+min(c1,c2);
			else ans+=3*min(c1,c2);
		}
		else ans+=3*min(c1,c2);
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
