#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,q;
	cin>>n>>q;
	while(q--)
	{
		string s;
		cin>>s;
		int k=1,ans=1;
		for(int i=s.size()-1;i>=0;i--)
		{
			if(s[i]=='R') ans+=k;
			k*=2;
		}
		cout<<ans<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
