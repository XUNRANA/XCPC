#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
void solve()
{
	ans=1;
	cin>>s;
	char p=s[0];
	for(int i=1;i<s.size();i++)
	{
		if(s[i]!=p)
		{
			ans++;
			p=s[i];
		}
	}
	if(ans==1) cout<<"1\n";
	else
	{
		if(ans==2&&s[0]=='1') cout<<2<<"\n";
		else cout<<ans-1<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
